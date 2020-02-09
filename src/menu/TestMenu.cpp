#include "TestMenu.h"

TestMenu::TestMenu(int size_x, int size_y, const Point &_offset) : Menu(size_x, size_y, _offset) {
    buttons.push_back(new TextButton("test", 30, Point(offset.x + 40, offset.y + 40)));
}
