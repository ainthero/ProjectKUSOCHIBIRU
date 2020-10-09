//
// Created by ainthero on 25.09.20.
//
#include "Bullet.h"

Bullet::Bullet(int x, int y, double dir_a) {
    hitbox = SDL_FRect{(float) x, (float) y, 20, 20};
    vec = point{(double) x, (double) y};
    dir_angle = dir_a == -1 ? (rand() / double(RAND_MAX)) * 2 * M_PI : dir_a;
    speed = 2;
    distance = 0;
    acceleration = 0.1;
}

void Bullet::update() {
    vec.x += speed * sin(dir_angle);
    vec.y += speed * cos(dir_angle);
    /*double deviation = sin(distance * M_PI / 10.) * 10;
    vec.x += sin(dir_angle) * deviation;
    vec.y -= cos(dir_angle) * deviation;*/
    hitbox.x = vec.x;
    hitbox.y = vec.y;
    //speed += acceleration;
}
