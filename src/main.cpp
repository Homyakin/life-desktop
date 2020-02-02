#include <SFML/Graphics.hpp>
#include <iostream>
#include "game/simple/SimpleLife.h"

void printSimple(const std::vector<std::vector<SimpleCell>> &v) {
    for (auto &i: v) {
        for (auto &j: i) {
            std::cout << (j.is_alive() ? 1 : 0) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    sf::RenderWindow window(
        sf::VideoMode(1500, 1000),
        "Game of Life",
        sf::Style::Titlebar | sf::Style::Close
    );
    sf::Clock clock{};

    SimpleLife life(10, 15);
    life.enable_grid();
    life.empty_start();
    /*sf::Text text{};
    sf::Font font{};
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setString("Classic");
    text.setPosition(200, 200);
    text.setCharacterSize(20);*/
    while (window.isOpen() && !life.is_started()) {
        sf::Clock tick{};
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed: {
                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
                        life.change_cell(window, event.mouseButton.x, event.mouseButton.y);
                    }
                    break;
                }
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Return) {
                        std::cout << "START" << std::endl;
                        life.start_game();
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear();
        life.render(window);
        window.draw(text);
        window.display();
    }

    life.disable_grid();

    while (window.isOpen()) {
        sf::Clock tick{};
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear();
        life.render(window);
        life.next_tick();
        window.display();
        if (tick.getElapsedTime().asMilliseconds() < 500)
            sf::sleep(sf::milliseconds(500 - tick.getElapsedTime().asMilliseconds()));
    }

    std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    return 0;
}
