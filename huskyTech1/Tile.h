#pragma once
#include "SETTINGS.h"
#include "ht_types.h"
#include <SDL.h>
#include <SDL_image.h>

class Tile
{
public:
	//WARNING, BLANK TILES WILL HECK UP EVERYTHING! USE CORRECT CONSTRUCTOR
	Tile();
	Tile(const char* filename, SDL_Renderer* renderer, bool v = true, bool c = false);
	~Tile();

	void Draw(SDL_Renderer* renderer, Point position);

	void SetVisibility(bool v);
	void SetCollision(bool c);
	
	bool GetVisibility();
	bool GetCollision();

private:
	SDL_Surface* image;
	SDL_Texture* tile_tex;

	bool visible; //can we see it?
	bool col; //can we collide with it?
	void explode();
};

