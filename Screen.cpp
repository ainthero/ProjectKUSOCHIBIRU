//
// Created by ainthero on 20.09.20.
//
#include "Screen.h"


Screen::Screen() {
    win = SDL_CreateWindow("undefined gensokyo", 0, 0, WIN_WIDTH, WIN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    render_color = SDL_Color{0, 0, 0, 255};
}

Screen *Screen::get_instance() {
    if (!p_screen) p_screen = new Screen();
    return p_screen;
}

void Screen::clean() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Screen::draw_current_state() {
    SDL_RenderPresent(renderer);
}

void Screen::set_renderer_color(SDL_Color clr) {
    render_color = clr;
    SDL_SetRenderDrawColor(renderer, render_color.r, render_color.g, render_color.b, render_color.a);
}

void Screen::fill_rect(SDL_FRect const &rect) {
    SDL_RenderFillRectF(renderer, &rect);
}

