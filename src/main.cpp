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
        sf::VideoMode(1000, 1000),
        "Game of Life",
        sf::Style::Titlebar | sf::Style::Close
    );
    sf::Clock clock{};
    SimpleLife life(100, 100);
    life.enable_grid();
    life.start();
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
        if(tick.getElapsedTime().asMilliseconds() < 500)
            sf::sleep(sf::milliseconds(500 - tick.getElapsedTime().asMilliseconds()));
    }
    std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    return 0;
}
