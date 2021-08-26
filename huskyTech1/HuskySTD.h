#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "ht_types.h"

class HuskySTD
{
public:
	//copies from array1 into array2
	//static bool addArrayTile(Tile *array1, int size, Tile new_tile);
	//static bool tile_memcpy(Tile* dst, Tile* src, size_t size);


	static Point generateRectFromArea(int area);

	//finds the position in a rect from an integer, using right to left, top to bottom. x is -1 if not in bounds
	static Point getPointFromRectInt(int position, Point rect);
};