#include "../header/render.h"
#include "../header/tick.h"

GameState global_state = GameState();
Render render;
Pixels pixels;

int main() {
    StateFunc man_back_fourth_func;
    int dir = left;
    man_back_fourth_func.data = &dir;
    man_back_fourth_func.state_func = manBackNFourth;

    StateFunc man_back_fourth_func2;
    int dir2 = right;
    man_back_fourth_func2.data = &dir2;
    man_back_fourth_func2.state_func = manBackNFourth;

    Models::Vec2 vec;
    vec.x = 0;
    vec.y = 0;
    Models::Model man(3, 3, &Models::idle[0][0], vec);

    Models::Vec2 vec2;
    vec.x = 4;
    vec.y = 6;
    Models::Model man2(3, 3, &Models::idle[0][0], vec2);

    global_state.addModel(&man, man_back_fourth_func);
    global_state.addModel(&man2, man_back_fourth_func2);


    int i = 0;
    while(true) {
    //if(i > 30) {
    //    break;
    //}

    global_state.tick();
    //pixels.upload(man, false, '\0');
    pixels.upload(man2, false, '\0');
    render.show(screen);
    pixels.upload(man, true, ' ');
    //pixels.upload(man2, true, ' ');

    //printModelCoOrds(&man);
    i += 1;
    }

}
