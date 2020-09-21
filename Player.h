//
// Created by ainthero on 20.09.20.
//

#pragma once
#include <SDL2/SDL.h>
#include "direction.h"
#include "Input.h"
#include "Geom.h"

namespace Player {
    extern SDL_Texture *texture;
    extern double speed;
    extern int state;
    extern int frame;
    extern SDL_FRect hitbox;
    extern point vec;
    void init(double, double);
    void move(direction, direction);
    void update_from_input();
};

