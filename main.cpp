#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "direction.h"
#include "Input.h"
#include "Screen.h"
#include "Player.h"
#include "Bullet.h"

bool quit = false;

void handle_event(SDL_Event e) {
    if (e.type == SDL_QUIT)
        quit = true;
}

std::vector<Bullet> bullets;


void clear_bullets(){
    int dels = 0;
    for (int i = 0; i < bullets.size() - dels; i++){
        if (bullets[i].vec.x < -10 && bullets[i].vec.x > Screen::WIN_WIDTH || bullets[i].vec.y < -10 || bullets[i].vec.y > Screen::WIN_HEIGHT){
            std::swap(bullets[i], bullets.back());
            bullets.pop_back();
            dels++;
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Screen::init();
    Input::init();
    Player::init(Screen::WIN_WIDTH / 2, Screen::WIN_HEIGHT);
    int ticks = 0;
    while (!quit) {
        Screen::clean();
        Input::update();
        SDL_Event event;
        SDL_SetRenderDrawColor(Screen::renderer, 255, 255, 255, 255);
        if (ticks % 2 == 0) bullets.push_back(Bullet{Screen::WIN_WIDTH / 2, Screen::WIN_HEIGHT / 2});
        while (SDL_PollEvent(&event)) {
            handle_event(event);
        }
        for (auto &c : bullets){
            c.update();
            SDL_RenderFillRectF(Screen::renderer, &c.hitbox);
            if (check_collision(Player::hitbox, c.hitbox)){
                quit = true;
            }
        }
        Player::update_from_input();
        SDL_SetRenderDrawColor(Screen::renderer, 255, 0, 0, 255);
        SDL_RenderFillRectF(Screen::renderer, &Player::hitbox);
        Screen::draw_current_state();
        clear_bullets();
        std::cout<<bullets.size()<<std::endl;
        ticks++;
        SDL_Delay(16);
    }
    return 0;
}
