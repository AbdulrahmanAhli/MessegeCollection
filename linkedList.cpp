// linkedList.cpp
#include "linkedList.h"

template <typename T>
inline linkedList<T>::linkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
inline linkedList<T>::~linkedList() { while (!emptyLinkedList()) removeFront(); }

template<typename T>
bool linkedList<T>::emptyLinkedList() { return head == NULL; }

template<typename T>
void linkedList<T>::addFront(const T newData) {
    node<T>* newNode = new node<T>(newData);
    newNode->next = head;
    head = newNode;

    if (emptyLinkedList()) tail = head = newNode;
    ++size;
}

template<typename T>
void linkedList<T>::removeFront() {
    if (emptyLinkedList()) throw emptyContainer("List is Empty\n");

    node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<typename T>
void linkedList<T>::addBack(const T newData) {
    node<T>* newNode = new node<T>(newData);
    newNode->data = newData;
    newNode->next = nullptr;

    if (emptyLinkedList()) head = tail = newNode;
    
    node<T>* searchForLastNode = head;

    while (searchForLastNode->next = NULL) { searchForLastNode = searchForLastNode->next; }

    searchForLastNode->next = newNode;
}

template <typename T>
void linkedList<T>::print() const throw(emptyContainer) {

    if (emptyLinkedList()) throw(emptyContainer("the list is Empty\n"));

    node<T>* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <typename T>
inline const T linkedList<T>::headData()const throw(emptyContainer) {
    if (emptyLinkedList()) throw(emptyContainer("the list is Empty\n"));
    return head->nodeGetData();
}

template <typename T>
inline const T linkedList<T>::tailData()const throw(emptyContainer) {
    if (emptyLinkedList()) throw(emptyContainer("the list is Empty\n"));
    return tail->nodeGetData();
}

template <typename T>
inline const int linkedList<T>::sizeOfList()const { return size; }

