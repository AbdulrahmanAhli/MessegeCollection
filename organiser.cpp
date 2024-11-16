// organiser.cpp

#include "organiser.h"
#include "sizeOutOfRangeException.h"
#include <stdexcept>
#include <iostream>
#include <vector>


organiser::organiser(const std::string& inputFileName, const std::string& outputFileName) {
    inputFile.open(inputFileName);
    if (!inputFile) {
        throw std::runtime_error("Failed to open input file: " + inputFileName);
    }

    outputFile.open(outputFileName);
    if (!outputFile) {
        throw std::runtime_error("Failed to open output file: " + outputFileName);
    }
}

organiser::~organiser() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

void organiser::addFragment(queue<message>* qList) {
    int convID, fragNumber, lengthMsg;
    message msg;

    while (inputFile >> convID >> fragNumber >> lengthMsg) {
        std::string text(lengthMsg, '\0');
        inputFile.ignore();
        inputFile.read(&text[0], lengthMsg);

        if (inputFile.gcount() != lengthMsg) {
            std::cerr << "Warning: Failed to read the complete message of length " << lengthMsg << std::endl;
            continue;
        }

        msg.setAll(fragNumber, convID, text);
        qList->enqueue(msg);
    }
}

void organiser::buildConvo(queue<message>* qList, conversationManager**& list, int& size) {
    const int convID = qList->frontData().getConvID();

    if (convID >= size) {
        try {
            resizeArray(list, size, convID * 2);
        }
        catch (const std::exception& exp) {
            std::cerr << exp.what() << std::endl;
            return;
        }
    }

    const int expectedFrag = list[convID]->getNumFrag() + 1;

    if (qList->frontData().getFrag() == expectedFrag) {
        list[convID]->addBackOfList(qList->frontData().getMsg());
        qList->dequeue();
    }
    else {
        qList->enqueue(qList->dequeue());
    }
}

void organiser::resizeArray(conversationManager**& listArray, int& size, int newSize) {
    if (newSize <= 0) {
        throw sizeOutOfRangeException("New size must be greater than zero.");
    }

    // Allocate new array with the new size
    conversationManager** temp = new conversationManager * [newSize];

    // Copy old elements
    for (int i = 0; i < size; ++i) {
        temp[i] = listArray[i];
    }

    // Initialize new elements to nullptr initially
    for (int i = size; i < newSize; ++i) {
        temp[i] = new conversationManager();
    }

    // Delete old array
    delete[] listArray;

    // Update size and list reference
    size = newSize;
    listArray = temp;
}

// Modify the print method
void organiser::print(conversationManager* list[], int size) {
    for (int i = 0; i < size; ++i) {
        if (list[i]->getNumFrag() > 0) {
            list[i]->print(outputFile); // Pass outputFile to print method
            outputFile << "\n";
        }
    }
}