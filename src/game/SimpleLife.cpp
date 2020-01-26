#include "SimpleLife.h"

SimpleLife::SimpleLife(int rows, int cols) : field(rows, cols) {}

void SimpleLife::start() {
    field.fillRandom();
    tick = 0;
}

void SimpleLife::nextTick() {
    field.updateState();
    ++tick;
}

std::vector<std::vector<SimpleCell> > SimpleLife::getCurrentState() {
    return field.getCurrentState();
}

