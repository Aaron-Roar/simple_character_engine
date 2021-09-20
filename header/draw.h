#pragma once
#include "models.h"
#include "figures.cpp"

struct Pixels {

    int outOfBounds(Models::Vec2 vec) {
        if(Figures::screen.dim.rows <= vec.y || Figures::screen.dim.cols <= vec.x) {
            return -1;
        }
        if(0 > vec.x || 0 > vec.y) {
            return -1;
        }
         else {
             return 0;
         }
    }

    void uploadPix(const char pix_val, Models::Vec2 vec) {
        if(outOfBounds(vec) == -1) {
            return;
        }
        Models::screen[vec.x][vec.y] = pix_val;
    }

    void uploadCopy(Models::Model model, int row, int col) {
        int pixel = 0;
        int relative_row = 0;
        while(relative_row < model.dim.rows) {

            int relative_col = 0;
            while(relative_col < model.dim.cols) {
                Models::Vec2 pos;
                pos.y = row + relative_col;
                pos.x = col + relative_row;

                uploadPix(model.ptr[pixel], pos);

                relative_col += 1;
                pixel += 1;
            }

            relative_row += 1;
        }
    }

    void upload(Models::Model model, bool fill, char symb) {

        int pixel = 0;
        int relative_row = 0;
        while(relative_row < model.dim.rows) {

            int relative_col = 0;
            while(relative_col < model.dim.cols) {
                Models::Vec2 pos;
                pos.y = model.state.pos_top_left.y + relative_col;
                pos.x = model.state.pos_top_left.x + relative_row;

                if(fill == true) {
                uploadPix(symb, pos);
                } else {
                uploadPix(model.ptr[pixel], pos);
                }

                relative_col += 1;
                pixel += 1;
            }

            relative_row += 1;
        }
    }

    void remove() {
    }
};
