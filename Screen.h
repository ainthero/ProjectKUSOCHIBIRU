//
// Created by ainthero on 20.09.20.
//

#pragma once

#include <SDL2/SDL.h>

namespace Screen {

    extern SDL_Window *win;
    extern SDL_Renderer *renderer;
    extern SDL_Color render_color;
    extern int WIN_HEIGHT;
    extern int WIN_WIDTH;


    void init();

    void clean();

    void draw_current_state();
};

