#ifndef MESSAGE_H
#define MESSAGE_H

// message.h

/// <summary>
/// this will connect to the organizer so that it can organizer based on the following info
/// 1. conversation id
/// 2. the fragment number
/// 3. the message that all of the passed details belongs to 
/// </summary>

#include <string>

class message {
private:
    int fragmentNumber;
    int conversationID;
    int reenqueueCount;
    std::string messageContent;

public:
    message(); // Default constructor

    void setAll(int fragNum, int convID, const std::string& msgCont);

    // Getters
    int getFrag() const;
    int getConvID() const;
    std::string getMsg() const;

    void incrementReenqueueCount();
    int getReenqueueCount() const;

};

#endif // MESSAGE_H
