// queue.cpp

#include "queue.h"

template <typename T>
queue<T>::queue() { qList = new linkedList<T>(); } // Allocate memory for the linked list

template <typename T>
queue<T>::~queue() { delete qList; }

template <typename T>
int queue<T>::sizeQueue() const {
    return qList->sizeOfList(); // Use sizeOfList() from linkedList
}

template <typename T>
bool queue<T>::emptyQueue() const {
    return qList->emptyLinkedList(); // Use emptyLinkedList() from linkedList
}

template <typename T>
const T queue<T>::frontData() const {
    if (emptyQueue()) {
        throw emptyContainer("The queue is empty\n");
    }
    return qList->headData(); // Access head data from linkedList
}

template <typename T>
const T queue<T>::rearData() const {
    if (emptyQueue()) {
        throw emptyContainer("The queue is empty\n");
    }
    return qList->tailData(); // Access tail data from linkedList
}

template <typename T>
void queue<T>::enqueue(const T newData) {
    qList->addBack(newData); // Add element at the back
}

template <typename T>
const T queue<T>::dequeue() {
    if (qList->emptyLinkedList()) throw emptyContainer("The queue is empty\n"); 

    T frontData = qList->headData(); // Store the front data
    qList->removeFront();       // Remove the front element
    return frontData;                // Return the stored data


}
