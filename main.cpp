#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>

int main() {
    std::mt19937_64 gen(std::time(nullptr));
    std::uniform_int_distribution color_dist(0, 255);
    sf::RenderWindow window(
            sf::VideoMode(512, 512),
            "SFML works!",
            sf::Style::Titlebar | sf::Style::Close
    );
    sf::CircleShape shape(256.f);
    shape.setFillColor(sf::Color::Red);
    sf::Clock clock{};
    while (window.isOpen()) {
        std::cout << clock.getElapsedTime().asSeconds() << std::endl;
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    shape.setFillColor(sf::Color(color_dist(gen), color_dist(gen), color_dist(gen)));
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
