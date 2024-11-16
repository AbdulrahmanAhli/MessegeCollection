// conversationManager


#include "conversationManager.h"

inline conversationManager::conversationManager() : numberFragment(0) { sLL = new linkedList<string>; }

inline conversationManager::~conversationManager() { delete sLL; }

inline int conversationManager::getNumFrag() const { return numberFragment; }

void conversationManager::addBackOfList(const string& newData) { sLL->addBack(newData); numberFragment++; }

void conversationManager::print() const { sLL->print(); }
