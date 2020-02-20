#pragma once

#include "Menu.h"

class MenuManager : public Rendered, public Clickable {
private:
    Menu *active_menu;
    MenuEvent event = MenuEvent::NONE;
public:
    MenuManager(int size_x, int size_y, const Point &_offset);

    void render(sf::RenderWindow &window) override;

    bool click(int mouse_x, int mouse_y) override;

    Menu *const get_active_menu() const;

    bool has_pressed_button() const;

    bool release_button(int mouse_x, int mouse_y);

    MenuEvent get_event() const;

    void clear_event();
};
