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

public:
    // Constructor: Opens the input file
    explicit organiser(const std::string& fileName);

    // Adds a fragment to the queue
    void addFragment(queue<message>* qList);

    // Builds conversations from the queue
    void buildConvo(queue<message>* qList, conversationManager**& list, int& size);

    // Resizes the array of conversation managers
    void resizeArray(conversationManager**& listArray, int& size, int newSize);

    // Prints all conversations
    void print(conversationManager* list[], int size) const;
};

#endif // ORGANISER_H

