//
// Created by ainthero on 20.09.20.
//
#include "Screen.h"

namespace Screen{
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Color render_color;
    int WIN_HEIGHT;
    int WIN_WIDTH;

    void init() {
        WIN_HEIGHT = 768;
        WIN_WIDTH = 1024;
        win = SDL_CreateWindow("undefined gensokyo", 0, 0, WIN_WIDTH, WIN_HEIGHT, 0);
        renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        render_color = SDL_Color{0, 0, 0, 255};
    }

    void clean() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    void draw_current_state() {
        SDL_RenderPresent(renderer);
    }
}
