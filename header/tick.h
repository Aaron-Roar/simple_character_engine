#pragma once
#include "state_funcs.cpp"
#include <cstdlib>

struct StateNode {
    StateNode* next = NULL;
    Models::Model* model;

    StateFunc state_structure;
};

struct StateList {
    StateNode* list = NULL;
    StateNode* end = NULL;
};

class GameState {
    public:
    GameState() {
    }

    void addModel(Models::Model* model, StateFunc state_structure) {
        StateNode* node = (StateNode*)malloc(sizeof(StateNode));
        node->model = model;
        node->state_structure = state_structure;

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
        if(node->state_structure.data == NULL) {
            perror("no data provided to alter state\n");
            return;
        }

        if(node->model == NULL) {
            perror("a model in the list was corupted\n");
            return;
        }

        node->state_structure.state_func(node->model, node->state_structure.data);
        if(node->next == NULL) {
            return;
        }

        updateState(node->next);

    }

};







