#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "GameStatus.h"

class Life {
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

    virtual void change_cell(int height, int width, int mouse_x, int mouse_y) = 0;

    virtual void render(sf::RenderWindow &window, int height, int width) const = 0;

    bool is_grid_enabled() const { return grid_enabled; }

    void enable_grid() { grid_enabled = true; }

    void disable_grid() { grid_enabled = false; }

    void start_game() { status = IN_PROCESS; }

    bool is_started() const { return status != GameStatus::PREPARING; }

protected:
    void render_grid(sf::RenderWindow &window, int height, int width) const {
        sf::VertexArray vertical_lines(sf::Lines, (cols + 1) * 2);
        int x_size = width / cols;
        for (int i = 0; i < (cols + 1) * 2; i += 2) {
            vertical_lines[i].position = sf::Vector2f(i / 2 * x_size, 0);
            vertical_lines[i].color = sf::Color::Black;
            vertical_lines[i + 1].position = sf::Vector2f(i / 2 * x_size, height);
            vertical_lines[i + 1].color = sf::Color::Black;
        }
        sf::VertexArray horizontal_lines(sf::Lines, (rows + 1) * 2);
        int y_size = height / rows;
        for (int i = 0; i < (rows + 1) * 2; i += 2) {
            horizontal_lines[i].position = sf::Vector2f(0, i / 2 * y_size);
            horizontal_lines[i].color = sf::Color::Black;
            horizontal_lines[i + 1].position = sf::Vector2f(width, i / 2 * y_size);
            horizontal_lines[i + 1].color = sf::Color::Black;
        }
        window.draw(vertical_lines);
        window.draw(horizontal_lines);
    }
};
