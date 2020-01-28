#pragma once


#include <vector>
#include "cells/Cell.h"

template<class T, typename = std::enable_if<std::is_base_of<Cell, T>::value>>
class Field {
protected:
    std::vector<std::vector<T>> field;
    int rows = 0;
    int cols = 0;
public:
    const std::vector<std::vector<T>> &get_current_state() const {
        return field;
    }

    virtual void update_state() = 0;

    virtual void fill_random() = 0;
};
