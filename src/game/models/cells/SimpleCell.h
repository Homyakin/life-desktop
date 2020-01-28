#pragma once

#include <random>
#include <ctime>
#include "Cell.h"

class SimpleCell : public Cell {
private:
    static std::mt19937_64 gen;
    bool alive;
public:
    explicit SimpleCell(bool alive = false);

    static SimpleCell get_random_state();

    bool is_alive() const;

    void set_alive(bool _alive);
};

