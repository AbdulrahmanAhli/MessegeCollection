#include "emptyContainer.h"

emptyContainer::emptyContainer(const std::string& err)
    : std::runtime_error(err) {}
