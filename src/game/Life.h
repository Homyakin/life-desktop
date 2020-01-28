#pragma once

#include "models/Field.h"

template<class T, typename = std::enable_if<std::is_base_of<Cell, T>::value>>
class Life {
protected:
    unsigned int tick = 0;
public:
    virtual void start() = 0;

    virtual void next_tick() = 0;

    virtual const std::vector<std::vector<T>> &get_current_state() const = 0;
};
