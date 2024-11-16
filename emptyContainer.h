// emptyCntainer.h
#ifndef EMPTY_CONTAINER_H
#define EMPTY_CONTAINER_H

#include <stdexcept>
#include <string>

class emptyContainer : public std::runtime_error {
public:
    emptyContainer(const std::string& err = "list is empty\n" ) : std::runtime_error(err) {}
};

#endif // EMPTY_CONTAINER_H
