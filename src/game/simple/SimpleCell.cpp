#include "SimpleCell.h"
#include <random>
#include <ctime>

std::mt19937_64 SimpleCell::gen(std::time(nullptr));

SimpleCell::SimpleCell(bool alive) {
    this->alive = alive;
}

SimpleCell SimpleCell::get_random_state() {
    std::uniform_int_distribution alive(0, 1);
    return SimpleCell(alive(gen));
}

bool SimpleCell::is_alive() const {
    return alive;
}

void SimpleCell::set_alive(bool _alive) {
    alive = _alive;
}

sf::RectangleShape SimpleCell::render(int size_x, int size_y) const {
    sf::RectangleShape rectangle{};
    rectangle.setSize(sf::Vector2f(size_x, size_y));
    rectangle.setFillColor(alive ? sf::Color::Black : sf::Color::White);
    return rectangle;
}
