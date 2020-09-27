//
// Created by ainthero on 25.09.20.
//
#include "Bullet.h"

Bullet::Bullet(int x, int y) {
    hitbox = SDL_FRect{(float) x, (float) y, 20, 20};
    vec = point{(double) x, (double) y};
    dir_angle = (rand() / double(RAND_MAX)) * 2 * M_PI;
    speed = 1;
    acceleration = 0.1;
}

void Bullet::update() {
    vec.x += speed * sin(dir_angle);
    vec.y += speed * cos(dir_angle);
    hitbox.x = vec.x;
    hitbox.y = vec.y;
    speed += acceleration;
}
