#include "../header/render.h"

enum structures{screen, man};


Models::Model createModel(int structure, int pix_x, int pix_y) {
    Models::Model model;

        Models::Vec2 vec;
    switch(structure) {
        case 1:
            model.dim.cols = 3;
            model.dim.rows = 3;

            vec.x = pix_x;
            vec.y = pix_y;
            model.state.pos_top_left = vec;

            model.ptr = Models::array[1];
            break;

        case 0:
            model.dim.cols = 16;
            model.dim.rows = 10;

            vec.x = pix_x;
            vec.y = pix_y;
            model.state.pos_top_left = vec;

            model.ptr = Models::array[0];
            break;

    }


    return model;
}
