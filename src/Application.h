#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "models/Point.h"

class Application {
private:
    int app_width = 1500;
    int app_height = 1000;
    sf::RenderWindow window;
public:
    Application();

    void start();
};
