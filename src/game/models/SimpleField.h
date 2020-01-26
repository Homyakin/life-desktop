#pragma once

#include "Field.h"
#include "cells/SimpleCell.h"

class SimpleField : public Field<SimpleCell> {
public:
    SimpleField(int rows, int cols);

    void fillRandom() override;

    void updateState() override;

private:
    int countLiveNeighbors(int row, int col);
    std::vector<SimpleCell> getNeighbors(int row, int col);

};

