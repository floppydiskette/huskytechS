#pragma once

#include <SDL.h>
#include <algorithm>
#include "Sprite.h"
#include "Entity.h"
#include "Character.h"
#include "ht_types.h"
#include "keybinds.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool alive = false;

SDL_Window* window = NULL;
SDL_Renderer* ht_renderer = NULL;
Uint64 NOW;
Uint64 LAST;
double deltaTime;

Character* az_ch;

SDL_Event e;

//methods
int main(int argc, char* args[]);

void handle_keyboard_movement(SDL_Event kev, Character* en);

//sdl specific ones
bool init();
void explode(); //this just closes the application, but explode() sounded cooler

//order of execution happens here
void input_update(); //first
void physics_update(); //second
void update(); //third
void draw(); //fourth