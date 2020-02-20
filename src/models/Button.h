#pragma once

#include "../interfaces/Rendered.h"
#include "../interfaces/Clickable.h"
#include "../menu/MenuEvent.h"

class Button : public Rendered, public Clickable {
protected:
    bool pressed = false;
    MenuEvent event;
public:
    Button(int size_x, int size_y, const Point &_offset, MenuEvent event);

    explicit Button(const Point &_offset);

    void render(sf::RenderWindow &window) override;

    bool click(int mouse_x, int mouse_y) override;

    bool release(int mouse_x, int mouse_y);

    MenuEvent get_event() const;
};