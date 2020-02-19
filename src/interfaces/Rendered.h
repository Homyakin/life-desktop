#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../models/Point.h"

class Rendered {
protected:
    int size_x;
    int size_y;
    Point offset;
public:
    Rendered(Point _offset) : offset(_offset) {}

    int get_width() const { return size_x; }

    int get_height() const { return size_y; }

    Point get_offset() const { return offset; }

    virtual void render(sf::RenderWindow &window) = 0;
};
