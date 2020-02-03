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

void ClassicLife::change_cell(int height, int width, int mouse_x, int mouse_y) {
    if (status != GameStatus::PREPARING) return;
    int col = mouse_x * cols / width;
    int row = mouse_y * rows / height;
    field.change_cell(row, col);
}

void ClassicLife::next_tick() {
    if (status != GameStatus::PAUSE) {
        field.update_state();
        ++tick;
    }
}

void ClassicLife::render(sf::RenderWindow &window, int height, int width) const {
    window.clear(sf::Color::White);
    auto cells = field.render(width, height);
    for (auto &cell: cells) {
        window.draw(cell);
    }
    if (grid_enabled) render_grid(window, height, width);
}
