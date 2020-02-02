#include "SimpleLife.h"

SimpleLife::SimpleLife(int rows, int cols) : field(rows, cols) {
    this->rows = rows;
    this->cols = cols;
}

void SimpleLife::random_start() {
    field.fill_random();
    tick = 0;
}

void SimpleLife::empty_start() {
    tick = 0;
}

void SimpleLife::change_cell(const sf::RenderWindow &window, int mouse_x, int mouse_y) {
    if (started) return;
    int size_x = window.getSize().x;
    int size_y = window.getSize().y;
    int col = mouse_x * cols / size_x;
    int row = mouse_y * rows / size_y;
    field.change_cell(row, col);
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
