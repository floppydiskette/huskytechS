#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "ht_types.h"
#include "Tile.h"
#include "HuskySTD.h"

class Tileset
{
public:
	Tileset();
	~Tileset();

	void addTile(const char* filename, SDL_Renderer* renderer);
	void addTile(const char* filename, bool visible, bool collide, SDL_Renderer* renderer);
	void addTile(Tile new_tile, SDL_Renderer* renderer);

	void drawTile(SDL_Renderer* renderer, int tile, Point position);


private:
	Tile* tiles;
	void explode();
};

