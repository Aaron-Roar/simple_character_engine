#pragma once

namespace Models {

    struct Vec2 {
        int x;
        int y;
    };

    struct Bounds {
        Vec2 top_left;
        Vec2 top_right;

        Vec2 bot_left;
        Vec2 bot_right;
    };

    struct State {
        int orientation;

        Bounds bounds;
    };

    struct Dims {
        int rows;
        int cols;
    };

    class Model {
        public:
        void setModel(Vec2 top_left) {
            state.bounds.top_left.y = top_left.y;
            state.bounds.top_right.y = top_left.y;
            state.bounds.bot_left.y = top_left.y + dim.rows;
            state.bounds.bot_right.y = top_left.y + dim.rows;

            state.bounds.top_left.x = top_left.x;
            state.bounds.top_right.x = top_left.x + dim.cols;
            state.bounds.bot_left.x = top_left.x;
            state.bounds.bot_right.x = top_left.x + dim.cols;
        }
        Model(int rows, int cols, const char* chars, Vec2 top_left) {
            dim.rows = rows;
            dim.cols = cols;
            ptr = chars;

            setModel(top_left);
        }

        int id;

        Dims dim; 
        State state;

        const char* ptr;

    };




    const char idle[][3] = {
        {' ', '0', ' '},
        {'/', '|', '\\'},
        {'/', ' ', '\\'},
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
