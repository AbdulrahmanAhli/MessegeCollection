// main.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>  // For srand and rand
#include <ctime>    // For time
#include "queue.h"
#include "conversationManager.h"
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

    // Create the message queue
    wQueue<message>* qList = new wQueue<message>;

    try {
        // Instantiate the organiser with input and output file names
        organiser org("convo.txt", "output.txt", "conversations.csv");

        // Main processing loop
        while (!org.isFileEnd() || !qList->emptyQueue()) {
            int N = rand() % 5 + 1;  // Random N between 1 and 5
            if (!org.isFileEnd()) {
                org.addFragment(qList, N);
            }

            // Build conversations from the queued messages
            org.buildConvo(qList, listConvo, convoCap);

            // Remove the print call from inside the loop
        }

        // After processing all fragments, print the final conversations
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

    return 0;
}

