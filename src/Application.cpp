#include <iostream>
#include "Application.h"
#include "life/classic/ClassicLife.h"
#include "menu/Menu.h"

Application::Application() : window(sf::VideoMode(1500, 1000),
                                    "Game of Life",
                                    sf::Style::Titlebar | sf::Style::Close) {}

void Application::start() {
    Menu menu(500, 1000, Point(1000, 0));
    ClassicLife life(10, 10, 1000, 1000, Point(0, 0));
    life.enable_grid();
    life.empty_start();
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
                        life.change_cell(event.mouseButton.x, event.mouseButton.y);
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
        menu.render(window);
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
        menu.render(window);
        life.next_tick();
        window.display();
        if (tick.getElapsedTime().asMilliseconds() < 500)
            sf::sleep(sf::milliseconds(500 - tick.getElapsedTime().asMilliseconds()));
    }
}
