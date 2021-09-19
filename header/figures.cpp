#include "models.h"

Models::Vec2 vec;

namespace Figures {

    Models::Model man;
    Models::Model screen;

    void load_figures() {
        vec.x = 0;
        vec.y = 0;

        man.dim.rows = 3;
        man.dim.cols = 3;
        man.state.pos_top_left = vec;
        man.ptr = &Models::idle[0][0];

        screen.dim.rows = 10;
        screen.dim.cols = 16;
        screen.state.pos_top_left = vec;
        screen.ptr = &Models::screen[0][0];
    }

}
