#pragma once


/// <summary>
/// this will connect to the organizer so that it can organizer based on the following info
/// 1. conversation id
/// 2. the fragment number
/// 3. the message that all of the passed details belongs to 
/// </summary>

#include <string>
using namespace std;

class message
{
public:
	message();

	// setting all of the data
	void setAll(const int fragNum, const int convID, string msgCont);

	// getters to update and get the data
	const int getFrag() const;
	const int getConvID() const;
	const string getMsg() const;


private:

	int fragmentNumber; // the number of fragment's
	int conversationID; // this will have the ID of the fragment
	string messageContent; // this will hold the random messeges


};

