#pragma once

#include "models/Field.h"

template<class T, typename = std::enable_if<std::is_base_of<Cell, T>::value>>
class Life {
protected:
    unsigned int tick = 0;
public:
    virtual void start() = 0;

    virtual void nextTick() = 0;

    virtual std::vector<std::vector<T>> getCurrentState() = 0;
};
