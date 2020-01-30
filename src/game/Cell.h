#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class Cell {
public:
    virtual sf::RectangleShape render(int size_x, int size_y) const = 0;
};
