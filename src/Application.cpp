#include <iostream>
#include "Application.h"
#include "life/classic/ClassicLife.h"
#include "menu/Menu.h"

Application::Application() : window(sf::VideoMode(1500, 1000),
                                    "Game of Life",
                                    sf::Style::Titlebar | sf::Style::Close) {}

void Application::start() {
    Menu menu{};
    ClassicLife life(10, 10);
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
                        life.change_cell(life_upper_left, life_lower_right, event.mouseButton.x, event.mouseButton.y);
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
        life.render(window, life_upper_left, life_lower_right);
        menu.render(window, menu_upper_left, menu_lower_right);
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
        life.render(window, life_upper_left, life_lower_right);
        menu.render(window, menu_upper_left, menu_lower_right);
        life.next_tick();
        window.display();
        if (tick.getElapsedTime().asMilliseconds() < 500)
            sf::sleep(sf::milliseconds(500 - tick.getElapsedTime().asMilliseconds()));
    }
}
