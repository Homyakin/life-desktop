#include "ClassicLife.h"

ClassicLife::ClassicLife(int rows, int cols) : field(rows, cols) {
    this->rows = rows;
    this->cols = cols;
}

void ClassicLife::random_start() {
    field.fill_random();
    tick = 0;
}

void ClassicLife::empty_start() {
    tick = 0;
}

void ClassicLife::change_cell(const sf::RenderWindow &window, int mouse_x, int mouse_y) {
    if (status != GameStatus::PREPARING) return;
    int size_x = window.getSize().x;
    int size_y = window.getSize().y;
    int col = mouse_x * cols / size_x;
    int row = mouse_y * rows / size_y;
    field.change_cell(row, col);
}

void ClassicLife::next_tick() {
    field.update_state();
    ++tick;
}

void ClassicLife::render(sf::RenderWindow &window) const {
    window.clear(sf::Color::White);
    auto cells = field.render(window.getSize().x, window.getSize().y);
    for (auto &cell: cells) {
        window.draw(cell);
    }
    if (grid_enabled) render_grid(window);
}
