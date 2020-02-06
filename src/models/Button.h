#pragma once

#include "../interfaces/Rendered.h"
#include "../interfaces/Clickable.h"

class Button : public Rendered, public Clickable {
protected:
    bool pressed = false;
public:
    Button(int size_x, int size_y, const Point& _offset);

    explicit Button(const Point& _offset);

    void render(sf::RenderWindow &window) const override;

    bool click(int mouse_x, int mouse_y) override;

    bool release(int mouse_x, int mouse_y);
};