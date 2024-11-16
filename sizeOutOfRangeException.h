//sizeOutOfRangeException.h
#ifndef SIZE_OUT_OF_RANGE_EXCEPTION_H
#define SIZE_OUT_OF_RANGE_EXCEPTION_H

#include <stdexcept>
#include <string>

class sizeOutOfRangeException : public std::runtime_error {
public:
    explicit sizeOutOfRangeException(const std::string& err = "too small, try bigger");
};

#endif // SIZE_OUT_OF_RANGE_EXCEPTION_H
