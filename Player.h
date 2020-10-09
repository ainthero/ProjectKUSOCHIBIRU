//
// Created by ainthero on 20.09.20.
//

#pragma once

#include <SDL.h>
#include "direction.h"
#include "Input.h"
#include "Geom.h"

class Player {
    inline static Player *p_player;
    SDL_Texture *texture;
    double speed;
    int state;
    int frame;
    int shift_speed;
    SDL_FRect hitbox;
    point vec;
    float HITBOX_SIZE;

    Player();

public:
    static Player *get_instance();

    Player(Player const &) = delete;

    void operator=(Player const &) = delete;

    void move(direction, direction);

    void update_from_input();

    [[nodiscard]] SDL_FRect const& get_hitbox() const;
};


