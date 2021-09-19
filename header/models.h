#pragma once

namespace Models {

    struct Vec2 {
        int x;
        int y;
    };

    struct State {
        int orientation;
        Vec2 pos_top_left;
    };

    struct Dims {
        int rows;
        int cols;
    };

    struct Model {
        int id;

        Dims dim; 
        State state;
        const char* ptr;
    };




    const char idle[][3] = {
        {' ', '0', ' '},
        {'/', '|', '\\'},
        {'/', 'H', '\\'},
    };

    const char face[][5] = {
        {' ', '0', ' ', '0', ' '},
        {'l', 'l', 'l', 'l', ' '},
    };


char screen[][16] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
};

const char* array[] = {&screen[0][0], &idle[0][0], &face[0][0]};
};