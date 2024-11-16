//organiser.cpp

#include "organiser.h"
#include "sizeOutOfRangeException.h"

organiser::organiser(string fileName){

	inputFile.open(fileName);

	if (!inputFile) cout << "failed to open"; // i can throw	file not valid
}

void organiser::addFragment(queue<message>* qList) {

	int convID, fragNumber, lengthMsg;

	message msg;

	while (inputFile >> convID)
	{
		inputFile >> fragNumber >> lengthMsg;
		char* text = new char[lengthMsg + 1];
		inputFile.ignore();
		inputFile.read(text, lengthMsg);
		text[lengthMsg] = '\0';
		qList->enqueue(msg); 
		delete[] text;
	}
}

void organiser::buildConvo(queue<message>* qList, conversationManager**& list, int& size) {
	
	int convID = qList->frontData().getConvID();
	if (convID >= size)
	{
		try
		{
			resizeArray(list, size, (convID * 2));
		}
		catch (const std::exception& exp)
		{
			cerr << exp.what() << endl;
		}
	}

	if (qList->frontData().getFrag() == (list[convID]->getNumFrag() + 1))
	{
		list[convID]->addBackOfList(qList->frontData().getMsg());
		qList->dequeue();
	}
	else
	{
		message msg = qList->dequeue();
		qList->enqueue(msg);
	}
}

void organiser::resizeArray(conversationManager**& listArray, int& size, int& newSize) {

}




