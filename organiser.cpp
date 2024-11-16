// organiser.cpp

#include "organiser.h"
#include "sizeOutOfRangeException.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <iomanip> // For formatting


// organiser.cpp
organiser::organiser(const std::string& inputFileName,
    const std::string& outputFileName,
    const std::string& csvFileName) {
    inputFile.open(inputFileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file: " + inputFileName);
    }

    outputFile.open(outputFileName);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open output file: " + outputFileName);
    }

    csvFile.open(csvFileName);
    if (!csvFile.is_open()) {
        throw std::runtime_error("Failed to open CSV file: " + csvFileName);
    }
}



organiser::~organiser() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
    if (outputFile.is_open()) {
        outputFile.close();
    }
    if (csvFile.is_open()) {
        csvFile.close();
    }
}

void organiser::addFragment(queue<message>* qList, int N) {
    int convID, fragNumber, lengthMsg;
    int count = 0;

    while (count < N) {
        if (!(inputFile >> convID >> fragNumber >> lengthMsg)) {
            // Reached end of file or read error
            break;
        }

        std::string text(lengthMsg, '\0');
        inputFile.ignore();
        inputFile.read(&text[0], lengthMsg);

        if (static_cast<int>(inputFile.gcount()) != lengthMsg) {
            std::cerr << "Warning: Failed to read the complete message of length " << lengthMsg << std::endl;
            continue;
        }

        message msg;
        msg.setAll(fragNumber, convID, text);
        qList->enqueue(msg);
        ++count;

        // Debug output
        std::cout << "Enqueued fragment: Conversation " << convID
            << ", Fragment " << fragNumber
            << ", Message: " << text << std::endl;
    }
}

const int MAX_REENQUEUE_COUNT = 3; 

void organiser::buildConvo(queue<message>* qList, conversationManager**& list, int& size) {
    int initialQueueSize = qList->sizeQueue();
    int processedFragments = 0;

    while (processedFragments < initialQueueSize) {
        message currentMessage = qList->frontData();
        qList->dequeue();

        int convID = currentMessage.getConvID();

        // Resize array if necessary
        if (convID >= size) {
            try {
                resizeArray(list, size, convID + 1);
            }
            catch (const std::exception& exp) {
                std::cerr << exp.what() << std::endl;
                return;
            }
        }

        // Initialize conversationManager if null
        if (list[convID] == nullptr) {
            list[convID] = new conversationManager(convID);
        }

        int expectedFrag = list[convID]->getNumFrag() + 1;

        if (currentMessage.getFrag() == expectedFrag) {
            list[convID]->addBackOfList(currentMessage.getMsg());
        }
        else {
            currentMessage.incrementReenqueueCount();
            if (currentMessage.getReenqueueCount() <= MAX_REENQUEUE_COUNT) {
                qList->enqueue(currentMessage);  // Re-enqueue the fragment
            }
            else {
                std::cerr << "Discarding fragment " << currentMessage.getFrag()
                    << " of Conversation " << convID
                    << " after " << MAX_REENQUEUE_COUNT << " attempts." << std::endl;
                // Optionally, handle the incomplete conversation
            }
        }

        processedFragments++;
    }
}

void organiser::resizeArray(conversationManager**& listArray, int& size, int newSize) {
    if (newSize <= size) {
        // No need to resize if the new size is not larger
        return;
    }

    if (newSize <= 0) {
        throw sizeOutOfRangeException("New size must be greater than zero.");
    }

    // Allocate new array with the new size
    conversationManager** temp = new conversationManager * [newSize];

    // Copy old elements
    for (int i = 0; i < size; ++i) {
        temp[i] = listArray[i];
    }

    // Initialize new elements to nullptr
    for (int i = size; i < newSize; ++i) {
        temp[i] = nullptr;
    }

    // Delete old array
    delete[] listArray;

    // Update size and list reference
    size = newSize;
    listArray = temp;
}



// Declare the escapeCSV function
std::string escapeCSV(const std::string& data);

void organiser::print(conversationManager* list[], int size) {
    // Iterate over the array in order of conversation IDs
    for (int i = 0; i < size; ++i) {
        if (list[i] != nullptr && list[i]->getNumFrag() > 0) {
            // Print to console
            std::cout << "Conversation " << list[i]->getConvID() << ":\n";
            list[i]->print(std::cout); // Assuming print method prints fragments line by line
            std::cout << "\n";

            // Print to output file
            outputFile << "Conversation " << list[i]->getConvID() << ":\n";
            list[i]->print(outputFile);
            outputFile << "\n";
        }
    }

    // Prepare data for CSV
    // CSV Structure:
    // Each conversation has a header, followed by its fragments in subsequent rows.

    // Reset CSV file pointer to the beginning if needed
    // (Assuming you want to overwrite each time)
    csvFile.close();
    csvFile.open("conversations.csv", std::ios::trunc);
    if (!csvFile.is_open()) {
        throw std::runtime_error("Failed to open CSV file for writing.");
    }

    // Write each conversation's fragments under its header
    for (int i = 0; i < size; ++i) {
        if (list[i] != nullptr && list[i]->getNumFrag() > 0) {
            // Write conversation header
            csvFile << "Conversation " << list[i]->getConvID() << "\n";

            // Write each fragment in a new line
            std::vector<std::string> fragments = list[i]->getFragments();
            for (const auto& frag : fragments) {
                csvFile << escapeCSV(frag) << "\n";
            }

            // Add an empty line to separate conversations
            csvFile << "\n";
        }
    }
}


// Define the escapeCSV function
std::string escapeCSV(const std::string& data) {
    std::string escaped;
    bool needsQuotes = data.find(',') != std::string::npos || data.find('"') != std::string::npos;
    if (needsQuotes) {
        escaped += '"';
        for (char c : data) {
            if (c == '"') {
                escaped += "\"\""; // Escape double quotes
            }
            else {
                escaped += c;
            }
        }
        escaped += '"';
    }
    else {
        escaped = data;
    }
    return escaped;
}

bool organiser::isFileEnd() const { return inputFile.eof(); }
