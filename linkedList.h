// linkedList.h
#pragma once
#include <iostream>
#include "node.h"
#include "emptyContainer.h"
#include "linkedList.cpp"


template <typename T>
class linkedList : public emptyContainer
{
public:
	linkedList();
	~linkedList();

	bool emptyLinkedList()const;

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


// linkedList.cpp
#include "linkedList.h"

template <typename T>
inline linkedList<T>::linkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
inline linkedList<T>::~linkedList() {
    while (!emptyLinkedList()) {
        removeFront();
    }
}

template <typename T>
bool linkedList<T>::emptyLinkedList() const {
    return head == nullptr;
}

template <typename T>
void linkedList<T>::addFront(const T newData) {
    node<T>* newNode = new node<T>(newData);
    newNode->next = head;
    head = newNode;

    if (size == 0) { // Correctly set tail for an initially empty list
        tail = head;
    }
    ++size;
}

template <typename T>
void linkedList<T>::removeFront() {
    if (emptyLinkedList()) {
        throw emptyContainer();
    }

    node<T>* temp = head;
    head = head->next;

    // If the list becomes empty, update the tail pointer
    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    --size;
}

template <typename T>
void linkedList<T>::addBack(const T newData) {
    node<T>* newNode = new node<T>(newData);
    newNode->next = nullptr;

    if (emptyLinkedList()) {
        head = tail = newNode;
    }
    else {
        // Directly use the tail pointer to avoid traversal
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

template <typename T>
void linkedList<T>::print() const {
    if (emptyLinkedList()) {
        throw emptyContainer();
    }

    node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

template <typename T>
inline const T linkedList<T>::headData() const {
    if (emptyLinkedList()) {
        throw emptyContainer();
    }
    return head->nodeGetData();
}

template <typename T>
inline const T linkedList<T>::tailData() const {
    if (emptyLinkedList()) {
        throw emptyContainer();
    }
    return tail->nodeGetData();
}

template <typename T>
inline const int linkedList<T>::sizeOfList() const {
    return size;
}


