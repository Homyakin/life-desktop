#pragma once

#include "Life.h"
#include "models/cells/SimpleCell.h"
#include "models/SimpleField.h"

class SimpleLife : public Life<SimpleCell> {
private:
    SimpleField field;

public:
    SimpleLife(int rows, int cols);

    void start() override;

    void nextTick() override;

    std::vector<std::vector<SimpleCell> > getCurrentState() override;
};

