#include <SFML/Graphics.hpp>
#include <iostream>
#include "life/classic/ClassicCell.h"
#include "Application.h"

int main() {
    Application app{};
    sf::Clock clock{};

    app.start();

    std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    return 0;
}
