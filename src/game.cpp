#include "../header/render.h"
#include "../header/tick.h"
#include "../header/state_funcs.cpp"

GameState global_state = GameState();
Render render;
Pixels pixels;

int main() {
    Figures::load_figures();
    global_state.addModel(&Figures::man, manWalk);
    printf("Rand addModel\n");


    int i = 0;
    while(true) {
        if(i > 7) {
            break;
        }

    global_state.tick();
    printf("Ran tick\n");
    pixels.upload(Figures::man, false, '\0');
    render.show(Figures::screen);
    pixels.upload(Figures::man, true, ' ');

    i += 1;
    }

}
