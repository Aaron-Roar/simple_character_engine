#pragma once
#include "draw.h"
#include "models.h"
#include <cstdio>

struct Render {
    void show_pix(const char pix) {
        printf("%c", pix);
    }

    void show(Models::Model model) {
        char new_line = '\n';
        int relative_row = 0;
        int pixel = 0;

        while(relative_row < model.dim.rows) {

            int relative_col = 0;
            while(relative_col < model.dim.cols) {
                show_pix(model.ptr[pixel]);

                relative_col += 1;
                pixel += 1;
            }
                show_pix(new_line);

            relative_row += 1;
        }


    }
};
