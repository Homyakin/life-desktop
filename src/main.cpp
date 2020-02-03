#include <SFML/Graphics.hpp>
#include <iostream>
#include "life/classic/ClassicCell.h"
#include "Application.h"

int main() {
    Application app{};
    sf::Clock clock{};
    app.start();

    /*sf::Text text{};
    sf::Font font{};
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setString("Classic");
    text.setPosition(200, 200);
    text.setCharacterSize(20);*/

    std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    return 0;
}
