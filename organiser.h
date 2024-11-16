//organiser.h
#pragma once
#include<iostream>
#include<fstream>
#include<string>

#include "conversationManager.h"
#include "queue.h"
#include "message.h"

using namespace std;



class organiser : public queue<message>, message, conversationManager
{

public:
	organiser(string fileName);

	void addFragment(queue<message> * qList); // this will read and add a fragment to the list

	void buildConvo(queue<message>* qList, conversationManager**& list, int& size);

	void resizeArray(conversationManager**& listArray, int& size, int& newSize);

	void print(conversationManager* list[], int size);


private:
	ifstream inputFile;


};

