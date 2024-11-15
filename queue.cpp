#include "queue.h"

template<typename T>
inline queue<T>::queue() {  qList = new linkedList<T>; }

template<typename T>
inline queue<T>::~queue() { while (!qList->emptyLinkedList()) dequeue(); }

template<typename T>
inline int queue<T>::sizeQueue() const { return qList->sizeOfList(); }

template<typename T>
inline bool queue<T>::emptyQueue() const { return qList->emptyLinkedList(); }

template<typename T>
inline const T queue<T>::frontData() const throw(emptyContainer) {

	if (emptyQueue()) throw(emptyContainer("the queue is empty\n"));
	return qList->headData();
}

template<typename T>
inline const T queue<T>::rearData() const throw(emptyContainer) {

	if (emptyQueue()) throw(emptyContainer("the queue is empty\n"));
	return qList->tailData();
}

template<typename T>
inline void queue<T>::enqueue(const T newData) { qList->addBack(newData); }

template<typename T>
inline const T queue<T>::dequeue() throw(emptyContainer) {

	if (emptyQueue()) throw (emptyContainer("the queue is empty\n"));

	T temp = qList->headData();
	qList->addFront();
	return temp;
}





