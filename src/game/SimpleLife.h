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

    void next_tick() override;

    const std::vector<std::vector<SimpleCell>> &get_current_state() const override;
};

