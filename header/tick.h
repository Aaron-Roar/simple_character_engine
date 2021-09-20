#include "models.h"
#include <cstdlib>

struct StateNode {
    StateNode* next = NULL;
    Models::Model* model;

    void (*state_fun)(Models::Model*) = NULL;
};

struct StateList {
    StateNode* list = NULL;
    StateNode* end = NULL;
};

class GameState {
    public:
    GameState() {
    }

    void addModel(Models::Model* model, void (*state_fun)(Models::Model*)) {
        StateNode* node = (StateNode*)malloc(sizeof(StateNode));
        node->model = model;
        node-> state_fun = state_fun;

        if(states.list == NULL) {
            states.list = node;
            states.end = node;
        } else {
            states.end->next = node;
            states.end = node;
        }
    }

    void tick() {
        if(states.list == NULL) {
            perror("State list was empty nothing to update\n");
            return;
        }
        updateState(states.list);
    }

    private:
    StateList states;

    void updateState(StateNode* node) {
        if(node->state_fun == NULL) {
            perror("no function provided to alter state\n");
            return;
        }

        if(node->model == NULL) {
            perror("a model in the list was corupted\n");
            return;
        }

        node->state_fun(node->model);
        if(node->next == NULL) {
            printf("Finished updating states\n");
            return;
        }

        updateState(node->next);

    }

};







