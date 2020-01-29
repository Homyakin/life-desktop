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

    void start() override;

    void next_tick() override;

    const std::vector<std::vector<SimpleCell>> &get_current_state() const override;

    void render(sf::RenderWindow &window) const override;
};

