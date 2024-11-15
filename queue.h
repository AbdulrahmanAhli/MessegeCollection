#pragma once

#include "linkedList.h"

template<typename T>
class queue
{
public:
	queue();
	~queue();

	int sizeQueue() const;
	bool emptyQueue() const;
	const T frontData()const throw(emptyContainer);
	const T rearData()const throw(emptyContainer);

	void enqueue(const T newData); // to put thing is the q list
	const T dequeue() throw(emptyContainer); // deleting and updating the list


private:
	linkedList<T>* qList; 
};

