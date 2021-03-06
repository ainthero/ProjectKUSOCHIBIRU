//
// Created by ainthero on 20.09.20.
//

#include "Input.h"

Input::Input() {
    keystate = SDL_GetKeyboardState(nullptr);
}

Input *Input::get_instance() {
    if (!p_input) p_input = new Input();
    return p_input;
}


void Input::update() {
    prev_inputstate = cur_inputstate;
    inputstate res{};
    res.dir_horizontal = NONE;
    res.dir_vertical = NONE;
    if (keystate[SDL_SCANCODE_RIGHT]) res.dir_horizontal = RIGHT;
    else if (keystate[SDL_SCANCODE_LEFT]) res.dir_horizontal = LEFT;
    if (keystate[SDL_SCANCODE_UP]) res.dir_vertical = UP;
    else if (keystate[SDL_SCANCODE_DOWN]) res.dir_vertical = DOWN;
    res.shift = keystate[SDL_SCANCODE_LSHIFT];
    res.button_A = keystate[SDL_SCANCODE_Z];
    res.button_B = keystate[SDL_SCANCODE_X];
    res.esc = keystate[SDL_SCANCODE_ESCAPE];
    cur_inputstate = res;
}




