#include "message.h"

message::message(): fragmentNumber(0), conversationID(0), messageContent("") {}

void message::setAll(const int fragNum, const int convID, string msgCont) {
	fragmentNumber = fragNum;
	conversationID = convID;
	messageContent = msgCont;
}

/// <summary>
/// those will get the following to update it
/// </summary>

const int message::getFrag() const { return fragmentNumber; }
const int message::getConvID() const { return conversationID; }
const string message::getMsg() const { return messageContent; }