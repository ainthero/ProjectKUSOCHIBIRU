#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "direction.h"
#include "Input.h"
#include "Screen.h"
#include "Player.h"


bool quit = true;

void handle_event(SDL_Event e) {
    if (e.type == SDL_QUIT)
        quit = false;
}


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Screen::init();
    Input::init();
    Player::init(Screen::WIN_WIDTH / 2, Screen::WIN_HEIGHT);
    while (quit) {
        Screen::clean();
        Input::update();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handle_event(event);
        }
        Player::update_from_input();
        SDL_SetRenderDrawColor(Screen::renderer, 255, 0, 0, 255);
        SDL_RenderFillRectF(Screen::renderer, &Player::hitbox);
        Screen::draw_current_state();
        SDL_Delay(16);
    }
    return 0;
}
