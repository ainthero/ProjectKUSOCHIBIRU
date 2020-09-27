//
// Created by ainthero on 21.09.20.
//

#pragma once

#include "Geom.h"

struct Bullet {
    point vec{};
    SDL_FRect hitbox{};
    double dir_angle{};
    double speed{};
    double acceleration{};

    Bullet(int x, int y);

    void update();
};