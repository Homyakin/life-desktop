#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Button.h"
#include "Colors.h"

Button::Button(int size_x, int size_y, const Point &_offset, MenuEvent event) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
    this->event = event;
}

Button::Button(const Point &_offset) : Rendered(_offset) {}

void Button::render(sf::RenderWindow &window) {
    sf::RectangleShape place(sf::Vector2f(size_x, size_y));
    place.setFillColor((pressed ? PRESSED_BUTTON : BUTTON));
    place.setOutlineColor(sf::Color::Black);
    place.setOutlineThickness(1);
    place.setPosition(offset.x, offset.y);
    window.draw(place);
}

bool Button::click(int mouse_x, int mouse_y) {
    if (mouse_x < offset.x || mouse_x >= offset.x + size_x ||
        mouse_y < offset.y || mouse_y >= offset.y + size_y) {
        return false;
    }
    pressed = true;
    return true;
}

bool Button::release(int mouse_x, int mouse_y) {
    pressed = false;
    return mouse_x >= offset.x && mouse_x <= offset.x + size_x &&
           mouse_y >= offset.y && mouse_y <= offset.y + size_y;
}

MenuEvent Button::get_event() const {
    return event;
}
