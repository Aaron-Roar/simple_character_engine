#include "../header/render.h"
#include "../header/figures.cpp"

int main() {
    Figures::load_figures();

    Render render;
    Pixels pixels;

    Figures::man.state.pos_top_left.x = 1;
    Figures::man.state.pos_top_left.y = 9;
    pixels.upload(Figures::man);

    pixels.uploadCopy(Figures::man, 5, 6);

    render.show(Figures::screen);

}
