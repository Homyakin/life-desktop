#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../interfaces/Rendered.h"

class Menu : public Rendered {
public:
    void render(sf::RenderWindow &window, Point upper_left, Point lower_right) const override;
};
