//
// Created by ainthero on 20.09.20.
//
#pragma once
#include <SDL2//SDL.h>
#include "direction.h"

namespace Input{
    struct inputstate{
        direction dir_vertical;
        direction dir_horizontal;
        bool shift;
        bool button_A;
        bool button_B;
        bool esc;
    };

    extern inputstate prev_inputstate;
    extern inputstate cur_inputstate;
    extern Uint8 const *keystate;

    void init();

    void update();
}

