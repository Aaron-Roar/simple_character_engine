#pragma once
#include "models.h"

struct Pixels {

    void upload_pix(const char pix_val, Models::Vec2 vec) {
        Models::screen[vec.x][vec.y] = pix_val;
    }

    void upload(Models::Model model) {
        int pixel = 0;
        int relative_row = 0;
        while(relative_row < model.dim.rows) {

            int relative_col = 0;
            while(relative_col < model.dim.cols) {
                Models::Vec2 pos;
                pos.y = model.state.pos_top_left.y + relative_col;
                pos.x = model.state.pos_top_left.x + relative_row;

                upload_pix(model.ptr[pixel], pos);

                relative_col += 1;
                pixel += 1;
            }

            relative_row += 1;
        }
    }

    void remove() {
    }
};
