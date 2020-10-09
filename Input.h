//
// Created by ainthero on 20.09.20.
//
#pragma once

#include <SDL.h>
#include "direction.h"


class Input {
    struct inputstate {
        direction dir_vertical = NONE;
        direction dir_horizontal = NONE;
        bool shift = false;
        bool button_A = false;
        bool button_B = false;
        bool esc = false;
    };

    inline static Input *p_input;
    inputstate prev_inputstate;
    inputstate cur_inputstate;
    Uint8 const *keystate;

    Input();

public:
    static Input *get_instance();

    inputstate const &get_prev_inputstate() {
        return prev_inputstate;
    }

    inputstate const &get_cur_inputstate() {
        return cur_inputstate;
    }

    void update();
};

