#include <SFML/Graphics/RectangleShape.hpp>
#include "Menu.h"

void Menu::render(sf::RenderWindow &window, Point upper_left, Point lower_right) const {
    sf::RectangleShape place{};
    place.setSize(sf::Vector2f(lower_right.x - upper_left.x, lower_right.y - upper_left.y));
    place.setFillColor(sf::Color(128, 128, 128)); //Gray
    place.setPosition(upper_left.x, upper_left.y);
    window.draw(place);
}
