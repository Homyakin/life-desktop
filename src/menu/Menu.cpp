#include <SFML/Graphics/RectangleShape.hpp>
#include "Menu.h"

Menu::Menu(int size_x, int size_y, const Point &_offset) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
    buttons.emplace_back(20, 20, Point(offset.x + 40, offset.y + 40));
}

void Menu::render(sf::RenderWindow &window) const {
    sf::RectangleShape place{};
    place.setSize(sf::Vector2f(size_x, size_y));
    place.setFillColor(sf::Color(128, 128, 128)); //Gray
    place.setPosition(offset.x, offset.y);
    window.draw(place);
    for(auto& button: buttons) {
        button.render(window);
    }
}

bool Menu::click(int mouse_x, int mouse_y) {
    if (mouse_x < offset.x || mouse_x >= offset.x + size_x ||
        mouse_y < offset.y || mouse_y >= offset.y + size_y) {
        return false;
    }
    for(int i = 0; i < buttons.size() && !buttons[i].click(mouse_x, mouse_y); ++i);
    return true;
}
