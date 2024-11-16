#ifndef EMPTY_CONTAINER_H
#define EMPTY_CONTAINER_H



#include <stdexcept>
#include <string>

class emptyContainer : public std::runtime_error {
public:
    explicit emptyContainer(const std::string& err);
};

#endif // EMPTY_CONTAINER_H
