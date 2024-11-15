#pragma once
#include <iostream>
#include "node.h"
#include "emptyContainer.h"

template <typename T>
class linkedList : public emptyContainer
{
public:
	linkedList();
	~linkedList();

	bool emptyLinkedList();

	void addFront(const T newData);
	void removeFront();

	void addBack(const T newData);

	void print() const throw(emptyContainer);

	const T headData() const throw (emptyContainer);
	const T tailData()const throw (emptyContainer);
	const int sizeOfList() const;

private:

	node<T>* head;
	node<T>* tail;

	int size;



};

