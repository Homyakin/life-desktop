#pragma once

class Point {
public:
    int x;
    int y;
    Point(int _x, int _y): x(_x), y(_y) {}

    Point(Point const &t) {
        x = t.x;
        y = t.y;
    }
};
