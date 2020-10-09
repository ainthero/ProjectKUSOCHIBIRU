//
// Created by ainthero on 20.09.20.
//

#pragma once

#include <SDL.h>

class Screen {

    inline static Screen *p_screen;
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Color render_color;

    Screen();


public:
    const int WIN_HEIGHT = 768;
    const int WIN_WIDTH = 1024;

    static Screen *get_instance();

    void clean();

    void draw_current_state();

    void set_renderer_color(SDL_Color);

    void fill_rect(SDL_FRect const &);
};

