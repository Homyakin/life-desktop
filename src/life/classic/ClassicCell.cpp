#include "ClassicCell.h"
#include <random>
#include <ctime>

std::mt19937_64 ClassicCell::gen(std::time(nullptr));

ClassicCell::ClassicCell(bool alive) {
    this->alive = alive;
}

ClassicCell ClassicCell::get_random_state() {
    std::uniform_int_distribution alive(0, 1);
    return ClassicCell(alive(gen));
}

bool ClassicCell::is_alive() const {
    return alive;
}

void ClassicCell::set_alive(bool _alive) {
    alive = _alive;
}

sf::RectangleShape ClassicCell::render(int size_x, int size_y) const {
    sf::RectangleShape rectangle{};
    rectangle.setSize(sf::Vector2f(size_x, size_y));
    rectangle.setFillColor(alive ? sf::Color::Black : sf::Color::White);
    return rectangle;
}
