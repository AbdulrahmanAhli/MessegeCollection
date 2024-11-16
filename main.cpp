// main.cpp

#include <iostream>
#include <fstream>
#include "queue.h"
#include "conversationManager.h"
#include "organiser.h"

using namespace std;


int main() {

	int convoCap = 3;

	conversationManager** listConvo = new conversationManager * [convoCap];

	for (auto i = 0; i < convoCap; i++)
	{
		listConvo[i] = new conversationManager;
	}

	queue <message>* qList = new queue<message>;

	organiser org("convo.txt");

	org.addFragment(qList);

	while (!qList->emptyQueue()) {
		org.buildConvo(qList, listConvo, convoCap);
	}

	org.print(listConvo, convoCap);

	for (auto i = 0; i < convoCap; i++)
	{
		delete listConvo[i];
	}
	delete[] listConvo;


	return 0;
}