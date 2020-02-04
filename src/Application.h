#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "models/Point.h"

class Application {
private:
    int app_width = 1500;
    int app_height = 1000;
    Point life_upper_left = Point(0, 0);
    Point life_lower_right = Point(1000, 1000);
    Point menu_upper_left = Point(1000, 0);
    Point menu_lower_right = Point(1500, 1000);
    sf::RenderWindow window;
public:
    Application();

    void start();
};
