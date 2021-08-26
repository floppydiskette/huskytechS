#pragma once

#include <SDL.h>
#include <algorithm>
#include "Sprite.h"
#include "Entity.h"
#include "Character.h"
#include "ht_types.h"
#include "keybinds.h"
#include "SETTINGS.h"
#include "TileRenderer.h"
#include "Map.h"
#include "Camera.h"


bool alive = false;

SDL_Window* window = NULL;
SDL_Renderer* ht_renderer = NULL;
Uint64 NOW;
Uint64 LAST;
double deltaTime = 0;

Character* az_ch;
TileRenderer* tile_ren;
Map* mp;
bool dm = true;

Camera* camera;


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