#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class emptyContainer : public runtime_error
{
public:
	emptyContainer(string err) : runtime_error(err) {}
};

