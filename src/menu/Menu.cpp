#include <SFML/Graphics/RectangleShape.hpp>
#include "Menu.h"

Menu::Menu(int size_x, int size_y, const Point &_offset) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
}

void Menu::render(sf::RenderWindow &window) const {
    sf::RectangleShape place{};
    place.setSize(sf::Vector2f(size_x, size_y));
    place.setFillColor(sf::Color(128, 128, 128)); //Gray
    place.setPosition(offset.x, offset.y);
    window.draw(place);
}
