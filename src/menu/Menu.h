#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../interfaces/Rendered.h"

class Menu : public Rendered {
public:
    Menu(int size_x, int size_y, const Point& _offset);

    void render(sf::RenderWindow &window) const override;
};
