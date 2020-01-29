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

void SimpleLife::render(sf::RenderWindow &window) const {
    int min_size = std::min(window.getSize().x, window.getSize().y);
    window.clear(sf::Color::White);
    auto cells = field.render(min_size);
    for(auto& cell: cells) {
        window.draw(cell);
    }
}
