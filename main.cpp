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
Screen *screen;
Input *input;
Player *player;

std::vector<Bullet> bullets;


bool check_exit() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            quit = true;
    }
}


void clear_bullets() {
    int dels = 0;
    for (int i = 0; i < bullets.size() - dels; i++) {
        if (bullets[i].vec.x < -10 && bullets[i].vec.x > screen->WIN_WIDTH || bullets[i].vec.y < -10 ||
            bullets[i].vec.y > screen->WIN_HEIGHT) {
            std::swap(bullets[i], bullets.back());
            bullets.pop_back();
            dels++;
        }
    }
}


int main() {
    //initialize things
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = Screen::get_instance();
    input = Input::get_instance();
    player = Player::get_instance();
    int ticks = 0;
    double dir = 0;
    //main loop
    while (!quit) {
        check_exit();
        screen->clean();
        input->update();
        screen->set_renderer_color(SDL_Color{255, 255, 255, 255});
        if (ticks % 1 == 0)
            bullets.push_back(Bullet(screen->WIN_WIDTH / 2, screen->WIN_HEIGHT / 2, dir)), dir = dir + 0.2;
        for (auto &c : bullets) {//update and draw bullets
            c.update();
            screen->fill_rect(c.hitbox);
            if (check_collision(player->get_hitbox(), c.hitbox)) {
                quit = true;
            }
        }
        player->update_from_input();
        screen->set_renderer_color(SDL_Color{255, 0, 0, 255});
        screen->fill_rect(player->get_hitbox());
        screen->draw_current_state();
        clear_bullets();
        ticks++;
        SDL_Delay(16);
    }
    return 0;
}
