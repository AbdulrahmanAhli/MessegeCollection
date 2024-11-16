// conversationManager.cpp


#include "conversationManager.h"

 conversationManager::conversationManager() : numberFragment(0) { sLL = new linkedList<string>; }

 conversationManager::~conversationManager() { delete sLL; }

 int conversationManager::getNumFrag() const { return numberFragment; }

void conversationManager::addBackOfList(const string& newData) { sLL->addBack(newData); numberFragment++; }

void conversationManager::print() const { sLL->print(); }
