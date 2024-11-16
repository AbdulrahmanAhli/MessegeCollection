//message.cpp
#include "message.h"

message::message(): fragmentNumber(0), conversationID(0), messageContent("") {}

void message::setAll(int fragNum, int convID, const std::string& msgCont) {
    fragmentNumber = fragNum;
    conversationID = convID;
    messageContent = msgCont;
}

// Getters
int message::getFrag() const { return fragmentNumber;}

int message::getConvID() const { return conversationID; }

std::string message::getMsg() const { return messageContent;}
