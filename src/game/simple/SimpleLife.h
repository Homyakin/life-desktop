#pragma once

#include <SFML/Graphics.hpp>
#include "../Life.h"
#include "SimpleCell.h"
#include "SimpleField.h"

class SimpleLife : public Life<SimpleCell> {
private:
    SimpleField field;

public:
    SimpleLife(int rows, int cols);

    void random_start() override;

    void empty_start() override;

    void change_cell(const sf::RenderWindow &window, int mouse_x, int mouse_y) override;

    void next_tick() override;

    const std::vector<std::vector<SimpleCell>> &get_current_state() const override;

    void render(sf::RenderWindow &window) const override;
};

