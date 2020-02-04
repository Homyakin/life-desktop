#include "ClassicLife.h"

ClassicLife::ClassicLife(int rows, int cols, int size_x, int size_y, const Point &_offset) :
    field(rows, cols),
    Life(_offset) {
    this->rows = rows;
    this->cols = cols;
    this->size_x = size_x;
    this->size_y = size_y;
}

void ClassicLife::random_start() {
    field.fill_random();
    tick = 0;
}

void ClassicLife::empty_start() {
    tick = 0;
}

void ClassicLife::change_cell(int mouse_x, int mouse_y) {
    mouse_x -= offset.x;
    mouse_y -= offset.y;
    int col = mouse_x * cols / (size_x - offset.x);
    int row = mouse_y * rows / (size_y - offset.y);
    field.change_cell(row, col);
}

void ClassicLife::next_tick() {
    if (status != GameStatus::PAUSE) {
        field.update_state();
        ++tick;
    }
}

void ClassicLife::render(sf::RenderWindow &window) const {
    window.clear(sf::Color::White);
    auto cells = field.render(size_x, size_y, offset);
    for (auto &cell: cells) {
        window.draw(cell);
    }
    if (grid_enabled) render_grid(window);
}
