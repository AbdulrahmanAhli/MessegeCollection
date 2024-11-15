// node.h
#pragma once


template <typename T>
class node
{
public:
	node(const T& value) : data(value), next(nullptr) {}
	T nodeGetData() const;
	template<typename E> friend class linkedList;
	T data;
	node<T>* next;
};

