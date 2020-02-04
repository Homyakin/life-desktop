#pragma once

class Clickable {
    // @return true if clicked
    virtual bool click(int mouse_x, int mouse_y) = 0;
};
