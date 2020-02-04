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

void ClassicLife::change_cell(Point upper_left, Point lower_right, int mouse_x, int mouse_y) {
    if (status != GameStatus::PREPARING) return;
    mouse_x -= upper_left.x;
    mouse_y -= upper_left.y;
    int col = mouse_x * cols / (lower_right.x - upper_left.x);
    int row = mouse_y * rows / (lower_right.y - upper_left.y);
    field.change_cell(row, col);
}

void ClassicLife::next_tick() {
    if (status != GameStatus::PAUSE) {
        field.update_state();
        ++tick;
    }
}

void ClassicLife::render(sf::RenderWindow &window, Point upper_left, Point lower_right) const {
    window.clear(sf::Color::White);
    auto cells = field.render(lower_right.x - upper_left.x, lower_right.y- upper_left.y);
    for (auto &cell: cells) {
        window.draw(cell);
    }
    if (grid_enabled) render_grid(window, upper_left, lower_right);
}
