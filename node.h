#ifndef NODE_H
#define NODE_H

template <typename T>
class node {
public:
    T data;
    node* next;

    // Constructor
    node(const T& newData) : data(newData), next(nullptr) {}

    // Getter method to access the data (declare and define in header for templates)
    T nodeGetData() const {
        return data;
    }
};

#endif // NODE_H
