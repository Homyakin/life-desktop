#pragma once

#include "../interfaces/Rendered.h"
#include "../interfaces/Clickable.h"

class Button: public Rendered, public Clickable {
private:
    bool pressed = false;
public:
    Button(int size_x, int size_y, const Point& _offset);

    void render(sf::RenderWindow &window) const override;

    bool check_press(int mouse_x, int mouse_y);

    bool check_release(int mouse_x, int mouse_y);

    bool click(int mouse_x, int mouse_y) override;
};
