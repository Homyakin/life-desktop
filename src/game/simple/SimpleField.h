#pragma once

#include <SFML/Graphics.hpp>
#include "../Field.h"
#include "SimpleCell.h"

class SimpleField : public Field<SimpleCell> {
public:
    SimpleField(int rows, int cols);

    void fill_random() override;

    void update_state() override;

    void change_cell(int row, int col) override;

    std::vector<sf::RectangleShape> render(int window_size_x, int window_size_y) const override;

private:
    int count_live_neighbors(int row, int col);

    std::vector<SimpleCell> get_neighbors(int row, int col);
};

