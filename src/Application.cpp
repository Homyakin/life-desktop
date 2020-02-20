#include <iostream>
#include <thread>
#include "Application.h"
#include "life/classic/ClassicLife.h"
#include "menu/MenuManager.h"
#include "menu/MenuEvent.h"

std::atomic<int> app_status = 1; //TODO think about more pretty solution

template<typename Base, typename T>
inline bool instanceof(const T *) {
    return std::is_base_of<Base, T>::value;
}

Application::Application() : window(sf::VideoMode(1500, 1000),
                                    "Game of Life",
                                    sf::Style::Titlebar | sf::Style::Close) {}

void run_life(Life *life);

void Application::start() {
    MenuManager menu(
        menu_lower_right.x - menu_upper_left.x,
        menu_lower_right.y - menu_upper_left.y,
        menu_upper_left
    );
    ClassicLife life(
        100,
        100,
        life_lower_right.x - life_upper_left.x,
        life_lower_right.y - life_upper_left.y,
        life_upper_left
    );
    std::thread *life_thread = nullptr;
    life.enable_grid();
    life.random_start();
    life_thread = new std::thread(run_life, &life);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    app_status = 0;
                    if (life_thread != nullptr) life_thread->join();
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed: {
                    if (event.mouseButton.button == sf::Mouse::Button::Left) {
                        int mouse_x = event.mouseButton.x;
                        int mouse_y = event.mouseButton.y;
                        if (life.click(mouse_x, mouse_y) || menu.click(mouse_x, mouse_y));
                    }
                    break;
                }
                case sf::Event::MouseButtonReleased: {
                    if (menu.has_pressed_button()) menu.release_button(event.mouseButton.x, event.mouseButton.y);
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
            switch (menu.get_event()) {
                case MenuEvent::START:
                    if (life.get_status() == GameStatus::PREPARING) {
                        std::cout << "START" << std::endl;
                        life.start_game();
                        life.disable_grid();
                    }
                    menu.clear_event();
                    break;
                case MenuEvent::NONE:
                    break;
            }
        }
        window.clear();
        life.render(window); //TODO move render to another thread
        menu.render(window);
        window.display();
    }
    delete life_thread;
}

void run_life(Life *life) {
    sf::Clock tick{};
    while (app_status == 1) {
        if (life->get_status() == GameStatus::IN_PROCESS && tick.getElapsedTime().asMilliseconds() >= 500) {
            life->next_tick();
            tick.restart();
        }
    }
}