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
    render_grid(window);
    auto cells = field.render(min_size);
    for (auto &cell: cells) {
        window.draw(cell);
    }
}

void SimpleLife::render_grid(sf::RenderWindow &window) const {
    sf::VertexArray vertical_lines(sf::Lines, field.get_cols() * 2);
    int x_size = window.getSize().x / field.get_cols();
    for (int i = 0; i < field.get_cols() * 2; i += 2) {
        vertical_lines[i].position = sf::Vector2f(i / 2 * x_size, 0);
        vertical_lines[i].color = sf::Color::Black;
        vertical_lines[i + 1].position = sf::Vector2f(i / 2 * x_size, window.getSize().y);
        vertical_lines[i + 1].color = sf::Color::Black;
    }
    sf::VertexArray horizontal_lines(sf::Lines, field.get_rows() * 2);
    int y_size = window.getSize().y / field.get_rows();
    for (int i = 0; i < field.get_rows() * 2; i += 2) {
        horizontal_lines[i].position = sf::Vector2f(0, i / 2 * y_size);
        horizontal_lines[i].color = sf::Color::Black;
        horizontal_lines[i + 1].position = sf::Vector2f(window.getSize().x, i / 2 * y_size);
        horizontal_lines[i + 1].color = sf::Color::Black;
    }
    window.draw(vertical_lines);
    window.draw(horizontal_lines);
}
