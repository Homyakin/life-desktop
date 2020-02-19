#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"
#include "../models/Point.h"

template<class T, typename = std::enable_if<std::is_base_of<Cell, T>::value>>
class Field {
protected:
    std::vector<std::vector<T>> field;
    int rows = 0;
    int cols = 0;
public:
    const std::vector<std::vector<T>> &get_current_state() const { return field; }

    int get_rows() const { return rows; }

    int get_cols() const { return cols; }

    virtual void update_state(std::mutex &field_lock) = 0;

    virtual void fill_random() = 0;

    virtual void change_cell(int row, int col) = 0;

    virtual std::vector<sf::RectangleShape> render(int window_size_x, int window_size_y, Point offset) const = 0;
};
