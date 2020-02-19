#pragma once

#include <SFML/Graphics.hpp>
#include "../Field.h"
#include "ClassicCell.h"
#include "../../models/Point.h"

class ClassicField : public Field<ClassicCell> {
public:
    ClassicField(int rows, int cols);

    void fill_random() override;

    void update_state(std::mutex &field_lock) override;

    void change_cell(int row, int col) override;

    std::vector<sf::RectangleShape> render(int window_size_x, int window_size_y, Point offset) const override;

private:
    int count_live_neighbors(int row, int col);

    std::vector<ClassicCell> get_neighbors(int row, int col);
};

