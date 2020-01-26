#include "SimpleCell.h"
#include <random>
#include <ctime>

SimpleCell::SimpleCell(bool alive) {
    this->alive = alive;
}

SimpleCell SimpleCell::getRandomState() {
    std::mt19937_64 gen(std::time(nullptr));
    std::uniform_int_distribution alive(0, 1);
    return SimpleCell(alive(gen));
}

bool SimpleCell::isAlive() const {
    return false;
}

void SimpleCell::setAlive(bool _alive) {
    alive = _alive;
}
