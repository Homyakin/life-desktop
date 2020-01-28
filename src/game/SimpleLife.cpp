#include "SimpleLife.h"

SimpleLife::SimpleLife(int rows, int cols) : field(rows, cols) {}

void SimpleLife::start() {
    field.fill_random();
    tick = 0;
}

void SimpleLife::next_tick() {
    field.update_state();
    ++tick;
}

const std::vector<std::vector<SimpleCell>> &SimpleLife::get_current_state() const {
    return field.get_current_state();
}
