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
bool linkedList<T>::emptyLinkedList() {
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
        throw emptyContainer("List is Empty\n");
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
        throw emptyContainer("The list is Empty\n");
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
        throw emptyContainer("The list is Empty\n");
    }
    return head->nodeGetData();
}

template <typename T>
inline const T linkedList<T>::tailData() const {
    if (emptyLinkedList()) {
        throw emptyContainer("The list is Empty\n");
    }
    return tail->nodeGetData();
}

template <typename T>
inline const int linkedList<T>::sizeOfList() const {
    return size;
}
