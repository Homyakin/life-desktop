#pragma once

#include <SFML/Graphics/Text.hpp>
#include "../interfaces/Rendered.h"
#include "../interfaces/Clickable.h"
#include "Button.h"

class TextButton : public Button {
private:
    std::string text;
    int charset_size;
public:
    TextButton(const std::string &text, int charset_size, const Point &_offset, MenuEvent event);

    void render(sf::RenderWindow &window) override;
};
