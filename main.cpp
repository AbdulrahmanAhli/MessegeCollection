#include <iostream>
#include <fstream>
#include <cstdlib>  // For srand and rand
#include <ctime>    // For time
#include "queue.h"
#include "organiser.h"
#include "message.h"

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Define initial capacity for the conversation manager array
    const int INITIAL_CAPACITY = 11;
    int convoCap = INITIAL_CAPACITY;

    // Create and initialize the conversation manager array
    conversationManager** listConvo = new conversationManager * [convoCap];
    for (int i = 0; i < convoCap; ++i) {
        listConvo[i] = nullptr;  // Initialize to nullptr
    }

    // Create the weighted message queue
    wQueue<message>* qList = new wQueue<message>();

    // Open input file
    std::ifstream inputFile("convo.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file!" << std::endl;
        return 1;
    }

    try {
        // Main processing loop
        while (!inputFile.eof() || !qList->emptyQueue()) {
            int N = rand() % 5 + 1;  // Random batch size between 1 and 5

            // Read N fragments from the file if possible
            for (int i = 0; i < N && !inputFile.eof(); ++i) {
                int convID, fragNumber, lengthMsg;

                // Read fragment metadata
                if (!(inputFile >> convID >> fragNumber >> lengthMsg)) {
                    std::cerr << "Error reading fragment metadata." << std::endl;
                    break;  // Stop reading on error
                }

                // Read the actual message content
                std::string text(lengthMsg, '\0');
                inputFile.ignore();  // Skip newline after message length
                inputFile.read(&text[0], lengthMsg);

                if (inputFile.gcount() != lengthMsg) {
                    std::cerr << "Error: Incomplete message content read." << std::endl;
                    continue;  // Skip incomplete fragments
                }

                // Calculate priority and enqueue
                int priority = fragNumber <= 5 ? 1 : (fragNumber <= 10 ? 2 : 3);
                message msg;
                msg.setAll(fragNumber, convID, text, priority);
                qList->enqueue(msg, priority);
            }

            // Build conversations from the queued messages
            organiser org("convo.txt", "output.txt", "conversations.csv");  // Assuming organiser has a default constructor
            org.buildConvo(qList, listConvo, convoCap);
        }

        // After processing all fragments, print the final conversations
        organiser org("convo.txt", "output.txt", "conversations.csv");  // Reuse organiser
        org.print(listConvo, convoCap);

    }
    catch (const std::exception& ex) {
        std::cerr << "An error occurred: " << ex.what() << std::endl;
    }

    // Cleanup
    for (int i = 0; i < convoCap; ++i) {
        if (listConvo[i] != nullptr) {
            delete listConvo[i];
        }
    }
    delete[] listConvo;
    delete qList;
    inputFile.close();

    return 0;
}
