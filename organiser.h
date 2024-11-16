#ifndef ORGANISER_H
#define ORGANISER_H

//organiser.h

#include <fstream>
#include <string>
#include "queue.h"
#include "message.h"
#include "conversationManager.h"

class organiser {
private:
    std::ifstream inputFile;
    std::ofstream outputFile;

public:
    // Constructor: Opens the input file
    explicit organiser(const std::string& inputFileName, const std::string& outputFileName);

    ~organiser()

    // Adds a fragment to the queue
    void addFragment(queue<message>* qList);

    // Builds conversations from the queue
    void buildConvo(queue<message>* qList, conversationManager**& list, int& size);

    // Resizes the array of conversation managers
    void resizeArray(conversationManager**& listArray, int& size, int newSize);

    // Constructor: Opens the input file and output file
    explicit organiser(const std::string& inputFileName, const std::string& outputFileName);

    // Prints all conversations
    void print(conversationManager* list[], int size);
};

#endif // ORGANISER_H

