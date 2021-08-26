#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "HuskySTD.h"
#include "ht_types.h"
#include "SETTINGS.h"

class TileRenderer
{
public:
	TileRenderer(SDL_Renderer* renderer, int texture_num = 1);
	~TileRenderer();

	void RegisterTexture(TileType tile, const char* filename);

	void Draw(TileType tile, Point position);

	void ClearAtlas();

private:
	SDL_Renderer* ht_renderer;
	SDL_Texture* tile_atlas;

	Point atlas_size;
	int max_textures;

	Point* pos_list;

	void explode();
};

