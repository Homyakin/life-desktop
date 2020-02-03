//
// Created by homyakin on 03.02.2020.
//

#ifndef LIFE_DESKTOP_APPLICATION_H
#define LIFE_DESKTOP_APPLICATION_H


#include <SFML/Graphics/RenderWindow.hpp>

class Application {
private:
    int game_width = 1000;
    int game_height = 1000;
    int menu_width = 500;
    int menu_height = 1000;
    sf::RenderWindow window;
public:
    Application();

    void start();
};


#endif //LIFE_DESKTOP_APPLICATION_H
