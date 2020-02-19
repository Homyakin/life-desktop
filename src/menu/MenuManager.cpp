#include "MenuManager.h"
#include "TestMenu.h"


MenuManager::MenuManager(int size_x, int size_y, const Point &_offset) : Rendered(_offset) {
    this->size_x = size_x;
    this->size_y = size_y;
    active_menu = new TestMenu(size_x, size_y, _offset); //remove size from menu??
}

void MenuManager::render(sf::RenderWindow &window) {
    active_menu->render(window);
}

bool MenuManager::click(int mouse_x, int mouse_y) {
    return active_menu->click(mouse_x, mouse_y);
}

Menu *const MenuManager::get_active_menu() const {
    return active_menu;
}

bool MenuManager::has_pressed_button() const {
    return active_menu->has_pressed_button();
}

bool MenuManager::release_button(int mouse_x, int mouse_y) {
    return active_menu->release_button(mouse_x, mouse_y);
}

