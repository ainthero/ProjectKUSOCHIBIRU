//
// Created by ainthero on 20.09.20.
//
#include "Player.h"


Player::Player() {
    speed = 6;
    shift_speed = 3;
    state = 0;
    frame = 0;
    vec.x = 1024 / 2 - HITBOX_SIZE / 2;
    vec.y = 768 - 30;
    HITBOX_SIZE = 10;
    hitbox = SDL_FRect{(float) vec.x, (float) vec.y, (float)HITBOX_SIZE, (float)HITBOX_SIZE};
}

Player* Player::get_instance() {
    if (!p_player) p_player = new Player();
    return p_player;
}

void Player::move(direction dir_v, direction dir_h) {
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
    switch (dir_h) {
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

void Player::update_from_input() {
    auto p_inpute = Input::get_instance();
    if (p_inpute->get_prev_inputstate().shift != p_inpute->get_cur_inputstate().shift) state = (state + 1) % 2;
    move(p_inpute->get_cur_inputstate().dir_vertical, p_inpute->get_cur_inputstate().dir_horizontal);
}

SDL_FRect const& Player::get_hitbox() const{
    return hitbox;
}





