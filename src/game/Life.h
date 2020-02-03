#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "GameStatus.h"

template<class T, typename = std::enable_if<std::is_base_of<Cell, T>::value>>
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

    virtual void change_cell(const sf::RenderWindow &window, int mouse_x, int mouse_y) = 0;

    virtual const std::vector<std::vector<T>> &get_current_state() const = 0;

    virtual void render(sf::RenderWindow &window) const = 0;

    bool is_grid_enabled() const { return grid_enabled; }

    void enable_grid() { grid_enabled = true; }

    void disable_grid() { grid_enabled = false; }

    void start_game() { status = IN_PROCESS; }

    bool is_started() const { return status != GameStatus::PREPARING; }

protected:
    void render_grid(sf::RenderWindow &window) const {
        sf::VertexArray vertical_lines(sf::Lines, cols * 2);
        int x_size = window.getSize().x / cols;
        for (int i = 0; i < cols * 2; i += 2) {
            vertical_lines[i].position = sf::Vector2f(i / 2 * x_size, 0);
            vertical_lines[i].color = sf::Color::Black;
            vertical_lines[i + 1].position = sf::Vector2f(i / 2 * x_size, window.getSize().y);
            vertical_lines[i + 1].color = sf::Color::Black;
        }
        sf::VertexArray horizontal_lines(sf::Lines, rows * 2);
        int y_size = window.getSize().y / rows;
        for (int i = 0; i < rows * 2; i += 2) {
            horizontal_lines[i].position = sf::Vector2f(0, i / 2 * y_size);
            horizontal_lines[i].color = sf::Color::Black;
            horizontal_lines[i + 1].position = sf::Vector2f(window.getSize().x, i / 2 * y_size);
            horizontal_lines[i + 1].color = sf::Color::Black;
        }
        window.draw(vertical_lines);
        window.draw(horizontal_lines);
    }
};
