// conversationManager.cpp


#include "conversationManager.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>


 conversationManager::conversationManager(int convID): numberFragment(0), conversationID(convID){
    sLL = new linkedList<std::string>;
}

 conversationManager::~conversationManager() { delete sLL; }

 int conversationManager::getNumFrag() const { return numberFragment; }

 int conversationManager::getConvID() const { return conversationID; }

void conversationManager::addBackOfList(const std::string& newData) { sLL->addBack(newData); numberFragment++; }

void conversationManager::print(std::ostream& os) const {
    std::vector<std::string> fragments = getFragments();
    int fragmentNumber = 1;

    // Set up formatting
    const int fragNumWidth = 12;
    const int messageWidth = 50;

    // Print header
    os << std::left << std::setw(fragNumWidth) << "Fragment No."
        << std::left << "Message Content" << "\n";
    os << std::string(fragNumWidth + messageWidth, '-') << "\n";

    // Print each fragment with formatting
    for (const auto& fragment : fragments) {
        os << std::left << std::setw(fragNumWidth) << fragmentNumber
            << fragment << "\n";
        fragmentNumber++;
    }
}

std::vector<std::string> conversationManager::getFragments() const {
    return sLL->toVector(); // Assuming `toVector` returns fragments in insertion order
}



