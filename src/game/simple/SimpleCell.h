#pragma once

#include <random>
#include <ctime>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Cell.h"

class SimpleCell : public Cell {
private:
    static std::mt19937_64 gen;
    bool alive;
public:
    explicit SimpleCell(bool alive = false);

    sf::RectangleShape render(int size_x, int size_y) const override;

    static SimpleCell get_random_state();

    bool is_alive() const;

    void set_alive(bool _alive);
};

