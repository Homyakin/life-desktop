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
    std::vector<std::vector<T>> getCurrentState() {
        return field;
    }

    virtual void updateState() = 0;

    virtual void fillRandom() = 0;
};
