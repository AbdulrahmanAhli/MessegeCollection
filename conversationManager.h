#ifndef CONVERSATION_MANAGER_H
#define CONVERSATION_MANAGER_H

// conversationManager.cpp

#include "linkedList.h"
#include <string>
#include <ostream>
#include<vector>


/// <summary>
/// this class is responsible of the management of the conversations
/// </summary>

class conversationManager {
private:
    linkedList<std::string>* sLL;
    int numberFragment;
    int conversationID;

public:
    conversationManager(int convID); // Constructor
    ~conversationManager(); // Destructor

    int getNumFrag() const;
    int getConvID() const;
    void addBackOfList(const std::string& newData);
    void print(std::ostream& os) const; // Accept output stream
    std::vector<std::string> getFragments() const;
};

#endif // CONVERSATION_MANAGER_H
