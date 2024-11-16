// conversationManager.cpp
#include <iostream>
#include <sstream>

#include "conversationManager.h"

 conversationManager::conversationManager(int convID) : numberFragment(0), conversationID(convID) { sLL = new linkedList<string>; }

 conversationManager::~conversationManager() { delete sLL; }

 int conversationManager::getNumFrag() const { return numberFragment; }

void conversationManager::addBackOfList(const string& newData) { sLL->addBack(newData); numberFragment++; }

void conversationManager::print() const {
    std::cout << "Conversation ID: " << conversationID << "\n";
    std::cout << "Number of Fragments: " << numberFragment << "\n";
    std::cout << "Assembled Message: " << sLL->concatenate() << "\n";
}
