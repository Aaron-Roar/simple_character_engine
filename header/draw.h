#pragma once
#include "models.h"

    Models::Vec2 screenVec = {0};
    Models::Model screen(10, 16, &Models::screen[0][0], screenVec);

    int outOfBounds(Models::Vec2 vec) {
        if(screen.state.bounds.bot_right.y <= vec.y || screen.state.bounds.bot_right.x <= vec.x) {
            return -1;
        }
        if(0 > vec.x || 0 > vec.y) {
            return -1;
        }
        else {
            return 0;
        }
    }
struct Pixels {


    void uploadPix(const char pix_val, Models::Vec2 vec) {
        if(outOfBounds(vec) == -1) {
            return;
        }
        Models::screen[vec.y][vec.x] = pix_val;
    }

    void uploadCopy(Models::Model model, int row, int col) {
        int pixel = 0;
        int relative_row = 0;
        while(relative_row < model.dim.rows) {

            int relative_col = 0;
            while(relative_col < model.dim.cols) {
                Models::Vec2 pos;
                pos.y = row + relative_row;
                pos.x = col + relative_col;

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
                pos.y = model.state.bounds.top_left.y + relative_row;
                pos.x = model.state.bounds.top_left.x + relative_col;

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

};
