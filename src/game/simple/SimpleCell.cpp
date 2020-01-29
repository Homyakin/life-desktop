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

sf::RectangleShape SimpleCell::render(int cell_size) const {
    sf::RectangleShape rectangle{};
    rectangle.setSize(sf::Vector2f(cell_size, cell_size));
    rectangle.setFillColor(is_alive() ? sf::Color::Black : sf::Color::White);
    return rectangle;
}
