#include <SFML/Graphics/RectangleShape.hpp>
#include "Menu.h"

Menu::Menu(int size_x, int size_y, const Point &_offset) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
}

void Menu::render(sf::RenderWindow &window) {
    sf::RectangleShape place{};
    place.setSize(sf::Vector2f(size_x, size_y));
    place.setFillColor(MENU);
    place.setPosition(offset.x, offset.y);
    window.draw(place);
    for (auto button: buttons) {
        button->render(window);
    }
}

bool Menu::click(int mouse_x, int mouse_y) {
    if (mouse_x < offset.x || mouse_x >= offset.x + size_x ||
        mouse_y < offset.y || mouse_y >= offset.y + size_y) {
        return false;
    }
    int i;
    for (i = 0; i < buttons.size() && !buttons[i]->click(mouse_x, mouse_y); ++i);
    if (i < buttons.size()) {
        pressed_button = buttons[i];
    }
    return true;
}

bool Menu::has_pressed_button() const {
    return pressed_button != nullptr;
}

bool Menu::release_button(int mouse_x, int mouse_y) {
    if (pressed_button != nullptr) {
        bool result = pressed_button->release(mouse_x, mouse_y);
        pressed_button = nullptr;
        return result;
    }
    return false;
}
