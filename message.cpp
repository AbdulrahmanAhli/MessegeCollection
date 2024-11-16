//message.cpp
#include "message.h"

message::message(): fragmentNumber(0), conversationID(0), messageContent(""), reenqueueCount(0) {}

void message::setAll(int fragNum, int convID, const std::string& msgCont) {
    fragmentNumber = fragNum;
    conversationID = convID;
    messageContent = msgCont;
    reenqueueCount = 0; // Reset reenqueueCount when setting new message data
}

// Getters
int message::getFrag() const { return fragmentNumber; }
int message::getConvID() const { return conversationID; }
std::string message::getMsg() const { return messageContent; }

void message::incrementReenqueueCount() { ++reenqueueCount; }
int message::getReenqueueCount() const { return reenqueueCount; }
