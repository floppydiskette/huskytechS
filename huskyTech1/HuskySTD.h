#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Tile.h"

class HuskySTD
{
public:
	//copies from array1 into array2
	static bool addArrayTile(Tile *array1, int size, Tile new_tile);
	static bool tile_memcpy(Tile* dst, Tile* src, size_t size);
};