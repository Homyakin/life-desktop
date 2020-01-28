#include <SFML/Graphics.hpp>
#include <iostream>
#include "game/SimpleLife.h"

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
        sf::VideoMode(500, 500),
        "Game of Life",
        sf::Style::Titlebar | sf::Style::Close
    );
    sf::Clock clock{};
    SimpleLife life(10, 10);
    life.start();
    while (window.isOpen()) {

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
        sf::sleep(sf::milliseconds(500));
    }
    std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    return 0;
}
