#include <iostream>
#include "Application.h"
#include "life/classic/ClassicLife.h"
#include "menu/Menu.h"

Application::Application() : window(sf::VideoMode(1500, 1000),
                                    "Game of Life",
                                    sf::Style::Titlebar | sf::Style::Close) {}

void Application::start() {
    Menu menu(
        menu_lower_right.x - menu_upper_left.x,
        menu_lower_right.y - menu_upper_left.y,
        menu_upper_left
    );
    ClassicLife life(
        10,
        10,
        life_lower_right.x - life_upper_left.x,
        life_lower_right.y - life_upper_left.y,
        life_upper_left
    );
    life.enable_grid();
    life.empty_start();
    while (window.isOpen()) {
        sf::Clock tick{};
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed: {
                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
                        int mouse_x = event.mouseButton.x;
                        int mouse_y = event.mouseButton.y;
                        //TODO Clickable bool click(x,y);
                        if (life.click(mouse_x, mouse_y) || menu.click(mouse_x, mouse_y));
                    }
                    break;
                }
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Return && life.get_status() == GameStatus::PREPARING) {
                        std::cout << "START" << std::endl;
                        life.start_game();
                        life.disable_grid();
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
        if (life.get_status() == GameStatus::IN_PROCESS && tick.getElapsedTime().asMilliseconds() < 500) {
            sf::sleep(sf::milliseconds(500 - tick.getElapsedTime().asMilliseconds()));
            life.next_tick();
        }
    }
}
