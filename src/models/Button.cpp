#include <SFML/Graphics/RectangleShape.hpp>
#include "Button.h"

Button::Button(int size_x, int size_y, const Point &_offset) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
}

void Button::render(sf::RenderWindow &window) const {
    sf::RectangleShape place(sf::Vector2f(size_x, size_y));
    place.setFillColor((pressed ? sf::Color::Green : sf::Color::Red)); // TODO make texture
    place.setPosition(offset.x, offset.y);
    window.draw(place);
}

bool Button::check_press(int mouse_x, int mouse_y) {
    if (mouse_x >= offset.x && mouse_x <= offset.x + size_x &&
        mouse_y >= offset.y && mouse_y <= offset.y + size_y) {
        pressed = true;
        return true;
    }
    return false;
}

bool Button::check_release(int mouse_x, int mouse_y) {
    pressed = false;
    return mouse_x >= offset.x && mouse_x <= offset.x + size_x &&
           mouse_y >= offset.y && mouse_y <= offset.y + size_y;
}

bool Button::click(int mouse_x, int mouse_y) {
    if (mouse_x < offset.x || mouse_x >= offset.x + size_x ||
        mouse_y < offset.y || mouse_y >= offset.y + size_y) {
        return false;
    }
    pressed = !pressed;
    return true;
}
