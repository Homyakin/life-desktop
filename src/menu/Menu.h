#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../interfaces/Rendered.h"
#include "../interfaces/Clickable.h"
#include "../models/Button.h"
#include "../models/Colors.h"

class Menu : public Rendered, public Clickable {
private:
    std::vector<Button> buttons;
    Button *pressed_button = nullptr;
public:
    Menu(int size_x, int size_y, const Point &_offset);

    void render(sf::RenderWindow &window) const override;

    bool click(int mouse_x, int mouse_y) override;

    bool has_pressed_button() const;

    bool release_button(int mouse_x, int mouse_y);
};
