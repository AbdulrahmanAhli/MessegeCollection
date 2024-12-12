#pragma once

#include "node.h"

template<typename T>
class wQueue {
public:
    wQueue();
    ~wQueue();

    int sizeQueue() const;
    bool emptyQueue() const;
    const T frontData() const;
    const T rearData() const;

    void enqueue(const T newData, int priority);  // Enqueue with priority
    const T dequeue();      // Dequeue the highest-priority element

private:
    node<std::pair<T, int>>* head;  // Node with data and priority
    int size;
};


#include "emptyContainer.h"  // Custom exception class

template <typename T>
wQueue<T>::wQueue() : head(nullptr), size(0) {}

template <typename T>
wQueue<T>::~wQueue() {
    while (!emptyQueue()) {
        dequeue();
    }
}

template <typename T>
int wQueue<T>::sizeQueue() const {
    return size;
}

template <typename T>
bool wQueue<T>::emptyQueue() const {
    return head == nullptr;
}

template <typename T>
const T wQueue<T>::frontData() const {
    if (emptyQueue()) throw emptyContainer("The queue is empty\n");
    return head->nodeGetData().first;  // Return front element's data
}

template <typename T>
const T wQueue<T>::rearData() const {
    if (emptyQueue()) throw emptyContainer("The queue is empty\n");
    node<std::pair<T, int>>* current = head;
    while (current->next != nullptr) {
        current = current->next;  // Traverse to the last node
    }
    return current->nodeGetData().first;
}

template <typename T>
void wQueue<T>::enqueue(const T newData, int priority) {
    auto* newNode = new node<std::pair<T, int>>({ newData, priority });

    // If the queue is empty or the new node has higher priority
    if (emptyQueue() || head->nodeGetData().second < priority) {
        newNode->next = head;
        head = newNode;
    }
    else {
        // Traverse the list to find the correct insertion point
        node<std::pair<T, int>>* current = head;
        while (current->next != nullptr && current->next->nodeGetData().second >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

template <typename T>
const T wQueue<T>::dequeue() {
    if (emptyQueue()) throw emptyContainer("The queue is empty\n");

    node<std::pair<T, int>>* temp = head;
    T data = head->nodeGetData().first;  // Extract the front data
    head = head->next;  // Remove the front element
    delete temp;
    size--;
    return data;
}