#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "../interfaces/Rendered.h"
#include "../interfaces/Clickable.h"
#include "GameStatus.h"

class Life : public Rendered, public Clickable {
protected:
    int rows = 0;
    int cols = 0;
    unsigned int tick = 0;
    bool grid_enabled = false;
    GameStatus status = GameStatus::PREPARING;
    std::mutex field_lock;
public:
    Life(Point _offset) : Rendered(_offset) {}

    virtual void random_start() = 0;

    virtual void next_tick() = 0;

    virtual void empty_start() = 0;

    unsigned int get_tick() const { return tick; }

    bool is_grid_enabled() const { return grid_enabled; }

    void enable_grid() { grid_enabled = true; }

    void disable_grid() { grid_enabled = false; }

    void start_game() { status = IN_PROCESS; }

    GameStatus get_status() const { return status; }

protected:
    virtual void change_cell(int mouse_x, int mouse_y) = 0;

    void render_grid(sf::RenderWindow &window) const {
        sf::VertexArray vertical_lines(sf::Lines, (cols + 1) * 2);
        int x_size = size_x / cols;
        for (int i = 0; i < (cols + 1) * 2; i += 2) {
            vertical_lines[i].position = sf::Vector2f(offset.x + i / 2 * x_size, offset.y);
            vertical_lines[i].color = sf::Color::Black;
            vertical_lines[i + 1].position = sf::Vector2f(offset.x + i / 2 * x_size, size_y + offset.y);
            vertical_lines[i + 1].color = sf::Color::Black;
        }
        sf::VertexArray horizontal_lines(sf::Lines, (rows + 1) * 2);
        int y_size = size_y / rows;
        for (int i = 0; i < (rows + 1) * 2; i += 2) {
            horizontal_lines[i].position = sf::Vector2f(offset.x, offset.y + i / 2 * y_size);
            horizontal_lines[i].color = sf::Color::Black;
            horizontal_lines[i + 1].position = sf::Vector2f(size_x + offset.x, offset.y + i / 2 * y_size);
            horizontal_lines[i + 1].color = sf::Color::Black;
        }
        window.draw(vertical_lines);
        window.draw(horizontal_lines);
    }
};
