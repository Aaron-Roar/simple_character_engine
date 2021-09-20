#include "models.h"

void manWalk(Models::Model* model) {
    model->state.pos_top_left.x += 1;
    model->state.pos_top_left.y += 1;
}
