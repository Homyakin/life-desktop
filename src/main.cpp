#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
#include "game/SimpleLife.h"

void printSimple(const std::vector<std::vector<SimpleCell>>& v) {
    for (auto& i: v) {
        for(auto& j: i) {
            std::cout << (j.is_alive() ? 1 : 0) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::mt19937_64 gen(std::time(nullptr));
    std::uniform_int_distribution color_dist(0, 255);
    std::uniform_int_distribution window_posy(10, 1000);
    std::uniform_int_distribution window_posx(10, 1900);
    sf::RenderWindow window(
        sf::VideoMode(512, 512),
        "SFML works!",
        sf::Style::Titlebar | sf::Style::Close
    );
    sf::CircleShape shape(256.f, 60);
    shape.setFillColor(sf::Color::Red);
    sf::Clock clock{};
    SimpleLife life(10, 10);
    life.start();
    printSimple(life.get_current_state());
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    shape.setFillColor(sf::Color(color_dist(gen), color_dist(gen), color_dist(gen)));
                    life.next_tick();
                    printSimple(life.get_current_state());
                    std::cout << "MOUSE BUTTON PRESSED" << std::endl;
                    break;
                /*case sf::Event::MouseMoved:
                    //window.setSize(sf::Vector2u(window_posx(gen), window_posy(gen)));
                    //std::cout << "MOUSE MOVED" << std::endl;
                    break;*/
                case sf::Event::KeyPressed:
                    std::cout << "KEY PRESSED" << std::endl;
                    break;
                case sf::Event::TextEntered:
                    if (event.text.unicode < 128)
                        std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    return 0;
}
