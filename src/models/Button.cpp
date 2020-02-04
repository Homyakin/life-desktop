#include "Button.h"

Button::Button(int size_x, int size_y, const Point &_offset) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
}

void Button::render(sf::RenderWindow &window) const {

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
