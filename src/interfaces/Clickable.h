#pragma once

class Clickable {
    /**
     * @param mouse_x
     * @param mouse_y
     * @return true if clicked
     */
    virtual bool click(int mouse_x, int mouse_y) = 0;
};
