#include <stdio.h>
#include "draw.h"
#include "models.h"

enum move{left, right, up, down};

struct StateFunc {
    void* data;
    void (*state_func)(Models::Model*, void*);
};

void moveEntireModel(Models::Model* model, int x, int y) {
    model->state.bounds.top_left.y += y;
    model->state.bounds.top_right.y += y;
    model->state.bounds.bot_left.y += y;
    model->state.bounds.bot_right.y += y;

    model->state.bounds.top_left.x += x;
    model->state.bounds.top_right.x += x;
    model->state.bounds.bot_left.x += x;
    model->state.bounds.bot_right.x += x;
}

void manMove(Models::Model* model, int mag, int dir) {
    switch(dir) {
        case left:
            moveEntireModel(model, -1*mag, 0);
            break;
        case right:
            moveEntireModel(model, mag, 0);
            break;
        case up:
            moveEntireModel(model, 0, -1*mag);
            break;
        case down:
            moveEntireModel(model, 0, mag);
            break;
        default:
            return;
    }
}

int back_four_dir = right;
void manBackNFourth(Models::Model* model, void* void_dir) {
    int* dir = (int*)void_dir;
    if(outOfBounds(model->state.bounds.top_right) == -1) {
        *dir = left;
    } 
    if(outOfBounds(model->state.bounds.top_left) == -1) {
        *dir = right;
    }
        manMove(model, 1, (int)*dir);
}

void manRight(Models::Model* model, void* null) {
    manMove(model, 3, right);
    manMove(model, 3, left);
}

void printModelCoOrds(Models::Model* model) {
    printf("[%d, %d] ", model->state.bounds.top_left.x, model->state.bounds.top_left.y);
    printf("[%d, %d]\n", model->state.bounds.top_right.x, model->state.bounds.top_right.y);

    printf("[%d, %d] ", model->state.bounds.bot_left.x, model->state.bounds.bot_left.y);
    printf("[%d, %d]\n", model->state.bounds.bot_right.x, model->state.bounds.bot_right.y);
}

