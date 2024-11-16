#ifndef CONVERSATION_MANAGER_H
#define CONVERSATION_MANAGER_H

// conversationManager.h

#include "linkedList.h"
#include <string>
using namespace std;

/// <summary>
/// this class is responsible of the management of the conversations
/// </summary>

class conversationManager {
private:
    linkedList<std::string>* sLL;
    int numberFragment;

public:
    conversationManager(); // Constructor
    ~conversationManager(); // Destructor

    int getNumFrag() const; // Getter for number of fragments
    void addBackOfList(const string& newData); // Add to the back of the list
    void print() const; // Print the conversation list
};

#endif // CONVERSATION_MANAGER_H
