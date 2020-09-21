//
// Created by ainthero on 21.09.20.
//

#pragma once
#include "Geom.h"

struct Bullet{
    point vec;
    double dir_angle;
    double speed;
    double acceleration;


    void update();
};