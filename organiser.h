#ifndef ORGANISER_H
#define ORGANISER_H

//organiser.h

#include <fstream>
#include <string>
#include <vector>
#include "queue.h"
#include "message.h"
#include "conversationManager.h"


class organiser {
private:
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::ofstream csvFile;

public:
    // Constructor: Opens the input file and output file
    organiser(const std::string& inputFileName, const std::string& outputFileName, const std::string& csvFileName);

    ~organiser();

    // Adds a fragment to the queue
    void addFragment(wQueue<message>* qList, int N);

    // Builds conversations from the queue
    void buildConvo(wQueue<message>* qList, conversationManager**& list, int& size);

    // Resizes the array of conversation managers
    void resizeArray(conversationManager**& listArray, int& size, int newSize);

    // Prints all conversations
    void print(conversationManager* list[], int size);

    bool isFileEnd() const;

    int calculatePriority(const message& msg);
    int calculatePriority(int fragNumber) const;

    void processFragments(wQueue<message>& qList, const message& msg);

    message getNextFragment();
};

#endif // ORGANISER_H

