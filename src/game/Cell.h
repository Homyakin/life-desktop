#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class Cell {
public:
    virtual sf::RectangleShape render(int cell_size) const = 0;
};
