//sizeOutOfRangeException.cpp
#include "sizeOutOfRangeException.h"

sizeOutOfRangeException::sizeOutOfRangeException(const std::string& err)
    : std::runtime_error(err) {}
