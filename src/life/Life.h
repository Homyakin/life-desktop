#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "../interfaces/Rendered.h"
#include "GameStatus.h"

class Life : public Rendered {
protected:
    int rows = 0;
    int cols = 0;
    unsigned int tick = 0;
    bool grid_enabled = false;
    GameStatus status = GameStatus::PREPARING;
public:
    virtual void random_start() = 0;

    virtual void next_tick() = 0;

    virtual void empty_start() = 0;

    virtual void change_cell(Point upper_left, Point lower_right, int mouse_x, int mouse_y) = 0;

    bool is_grid_enabled() const { return grid_enabled; }

    void enable_grid() { grid_enabled = true; }

    void disable_grid() { grid_enabled = false; }

    void start_game() { status = IN_PROCESS; }

    bool is_started() const { return status != GameStatus::PREPARING; }

protected:
    void render_grid(sf::RenderWindow &window, Point upper_left, Point lower_right) const {
        sf::VertexArray vertical_lines(sf::Lines, (cols + 1) * 2);
        int x_size = (lower_right.x - upper_left.x) / cols;
        for (int i = 0; i < (cols + 1) * 2; i += 2) {
            vertical_lines[i].position = sf::Vector2f(upper_left.x + i / 2 * x_size, upper_left.y);
            vertical_lines[i].color = sf::Color::Black;
            vertical_lines[i + 1].position = sf::Vector2f(upper_left.x + i / 2 * x_size, lower_right.y);
            vertical_lines[i + 1].color = sf::Color::Black;
        }
        sf::VertexArray horizontal_lines(sf::Lines, (rows + 1) * 2);
        int y_size = (lower_right.y - upper_left.y) / rows;
        for (int i = 0; i < (rows + 1) * 2; i += 2) {
            horizontal_lines[i].position = sf::Vector2f(upper_left.x, upper_left.y + i / 2 * y_size);
            horizontal_lines[i].color = sf::Color::Black;
            horizontal_lines[i + 1].position = sf::Vector2f(lower_right.x, upper_left.y + i / 2 * y_size);
            horizontal_lines[i + 1].color = sf::Color::Black;
        }
        window.draw(vertical_lines);
        window.draw(horizontal_lines);
    }
};
