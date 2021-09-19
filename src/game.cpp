#include "../header/render.h"
#include "../header/creator.h"

int main() {

    Render render;
    Pixels pixels;
    Models::Model model_screen = createModel(screen, 0, 0);

    Models::Model model_man = createModel(man, 0, 0);

    pixels.upload(model_man);

    render.show(model_screen);

}
