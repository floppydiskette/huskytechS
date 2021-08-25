#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Sprite
{

public:
	//filename is path starting from the data directory; rows and cols start from 0, a full image would have 1 rows and 1 cols
	Sprite(const char* filename, SDL_Renderer* renderer, int rows = 1, int cols = 1);

	~Sprite();

	void renderAtScreenPos(SDL_Renderer* renderer, int x, int y, int row = 0, int col = 0);

private:
	SDL_Surface* image;
	SDL_Texture* sprite_tex;

	int sprite_w;
	int sprite_h;


	//deallocate
	void explode();

};

