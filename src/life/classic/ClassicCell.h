#pragma once

#include <random>
#include <ctime>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Cell.h"

class ClassicCell : public Cell {
private:
    static std::mt19937_64 gen;
    bool alive;
public:
    explicit ClassicCell(bool alive = false);

    sf::RectangleShape render(int size_x, int size_y) const override;

    static ClassicCell get_random_state();

    bool is_alive() const;

    void set_alive(bool _alive);
};

