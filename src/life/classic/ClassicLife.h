#pragma once

#include <SFML/Graphics.hpp>
#include "../Life.h"
#include "ClassicCell.h"
#include "ClassicField.h"
#include "../../models/Point.h"

class ClassicLife : public Life {
private:
    ClassicField field;

public:
    ClassicLife(int rows, int cols);

    void random_start() override;

    void empty_start() override;

    void change_cell(Point upper_left, Point lower_right, int mouse_x, int mouse_y) override;

    void next_tick() override;

    void render(sf::RenderWindow &window, Point upper_left, Point lower_right) const override;
};

