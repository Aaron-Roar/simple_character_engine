#include "../header/render.h"
#include "../header/figures.cpp"

int main() {
    Figures::load_figures();

    Render render;
    Pixels pixels;

    pixels.uploadCopy(Figures::man, 0, 0);
    pixels.uploadCopy(Figures::man, 5, 6);

    render.show(Figures::screen);

}
