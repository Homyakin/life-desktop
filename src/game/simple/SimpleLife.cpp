#include "SimpleLife.h"

SimpleLife::SimpleLife(int rows, int cols) : field(rows, cols) {
    this->rows = rows;
    this->cols = cols;
}

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
    window.clear(sf::Color::White);
    auto cells = field.render(window.getSize().x, window.getSize().y);
    for (auto &cell: cells) {
        window.draw(cell);
    }
    if (grid_enabled) render_grid(window);
}
