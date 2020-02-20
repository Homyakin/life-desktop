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

void ClassicLife::next_tick() {
    if (status != GameStatus::PAUSE) {
        field.update_state(field_lock);
        ++tick;
    }
}

void ClassicLife::render(sf::RenderWindow &window) {
    field_lock.lock();
    sf::RectangleShape place(sf::Vector2f(size_x, size_y));
    place.setFillColor(sf::Color::White);
    place.setPosition(offset.x, offset.y);
    window.draw(place);
    if (render_tick != tick) {
        render_tick = tick;
        render_cells = field.render(size_x, size_y, offset);
    }
    for (auto &cell: render_cells) {
        window.draw(cell);
    }
    if (grid_enabled) render_grid(window);
    field_lock.unlock();
}

bool ClassicLife::click(int mouse_x, int mouse_y) {
    if (mouse_x < offset.x || mouse_x >= offset.x + size_x ||
        mouse_y < offset.y || mouse_y >= offset.y + size_y) {
        return false;
    }
    if (status == GameStatus::PREPARING) change_cell(mouse_x, mouse_y);
    return true;
}


void ClassicLife::change_cell(int mouse_x, int mouse_y) {
    mouse_x -= offset.x;
    mouse_y -= offset.y;
    int col = mouse_x * cols / size_x;
    int row = mouse_y * rows / size_y;
    field.change_cell(row, col);
}
