//
// Created by ainthero on 20.09.20.
//
#include "Player.h"

#define HITBOX_SIZE 7

namespace Player{

    SDL_Texture *texture;
    double speed;
    double shift_speed;
    int state;
    int frame;
    SDL_FRect hitbox;
    point vec;

    void init(double x, double y){
        speed = 6;
        shift_speed = 3;
        state = 0;
        frame = 0;
        vec.x = x - HITBOX_SIZE / 2;
        vec.y = y - 30;
        hitbox = SDL_FRect{(float)vec.x, (float)vec.y, HITBOX_SIZE, HITBOX_SIZE};
    }

    void move(direction dir_v, direction dir_h) {
        double current_speed = state == 0 ? speed : shift_speed;
        if (dir_v != NONE && dir_h != NONE) current_speed *= (1.0 / sqrt(2.0));
        switch (dir_v) {
            case UP:
                vec.y -= current_speed;
                break;
            case DOWN:
                vec.y += current_speed;
                break;
            default:
                break;
        }
        switch (dir_h){
            case LEFT:
                vec.x -= current_speed;
                break;
            case RIGHT:
                vec.x += current_speed;
                break;
            default:
                break;
        }
        hitbox.x = vec.x;
        hitbox.y = vec.y;
    }

    void update_from_input(){
        if (Input::prev_inputstate.shift != Input::cur_inputstate.shift) state = (state + 1) % 2;
        move(Input::cur_inputstate.dir_vertical, Input::cur_inputstate.dir_horizontal);
    }
}





