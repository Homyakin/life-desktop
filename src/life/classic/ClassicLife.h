#pragma once

#include <SFML/Graphics.hpp>
#include "../Life.h"
#include "ClassicCell.h"
#include "ClassicField.h"

class ClassicLife : public Life {
private:
    ClassicField field;

public:
    ClassicLife(int rows, int cols);

    void random_start() override;

    void empty_start() override;

    void change_cell(const sf::RenderWindow &window, int mouse_x, int mouse_y) override;

    void next_tick() override;

    void render(sf::RenderWindow &window) const override;
};

