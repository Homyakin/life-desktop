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
    ClassicLife(int rows, int cols, int size_x, int size_y, const Point &_offset);

    void random_start() override;

    void empty_start() override;

    void next_tick() override;

    void render(sf::RenderWindow &window) override;

    bool click(int mouse_x, int mouse_y) override;

protected:
    void change_cell(int mouse_x, int mouse_y) override;
};

