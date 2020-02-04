#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../models/Point.h"

class Rendered {
    virtual void render(sf::RenderWindow &window, Point upper_left, Point lower_right) const = 0;
};
