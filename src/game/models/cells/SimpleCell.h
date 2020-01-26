#pragma once

#include "Cell.h"

class SimpleCell : public Cell {
private:
    bool alive;
public:
    explicit SimpleCell(bool alive = false);

    static SimpleCell getRandomState();

    bool isAlive() const;

    void setAlive(bool _alive);
};

