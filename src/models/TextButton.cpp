#include <SFML/Graphics/RectangleShape.hpp>
#include "TextButton.h"
#include "Colors.h"

TextButton::TextButton(const std::string &text, int charset_size, const Point &_offset) : Button(_offset) {
    this->text = text;
    this->charset_size = charset_size;

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text sf_text(text, font, charset_size);
    auto coords = sf_text.getLocalBounds();

    size_x = coords.width + 20;
    size_y = coords.height + 20;
}

void TextButton::render(sf::RenderWindow &window) const {
    sf::RectangleShape place(sf::Vector2f(size_x, size_y));
    place.setFillColor((pressed ? PRESSED_BUTTON : BUTTON));
    place.setOutlineColor(sf::Color::Black);
    place.setOutlineThickness(1);
    place.setPosition(offset.x, offset.y);
    sf::Font font{};
    font.loadFromFile("arial.ttf");
    sf::Text sf_text("test", font, 30);
    sf_text.setFillColor(sf::Color::Black);
    auto coords = sf_text.getLocalBounds();
    //center text
    sf_text.setOrigin(coords.left + coords.width / 2.0f,
                      coords.top + coords.height / 2.0f);
    sf_text.setPosition(offset.x + coords.width / 2.0f + 10,
                        offset.y + coords.height / 2.0f + 10);
    window.draw(place);
    window.draw(sf_text);
}