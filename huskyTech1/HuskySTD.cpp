#include "HuskySTD.h"

/*
bool HuskySTD::addArrayTile(Tile* array1, int size, Tile new_tile)
{
	Tile* tmp_array = new Tile[size + 1];
	tile_memcpy(tmp_array, array1, size);
	tmp_array[size] = new_tile;
	delete array1;
	array1 = tmp_array;
	return true;
}

bool HuskySTD::tile_memcpy(Tile* dst, Tile* src, size_t size)
{
	for (int i = 0; i < size; i++) {
		dst[i] = src[i];
	}
	return true;
}
*/

//this function will generate a rectangle with a given area. if not a square, will add one to the length
Point HuskySTD::generateRectFromArea(int area)
{
	float square = sqrt(area);
	Point rect = { 0,0 };
	if (square > (int)square) {
		rect.y = (int)square + 1;
	}
	else {
		rect.y = (int)square;
	}
	rect.x = (int)square;
	return rect;
}

Point HuskySTD::getPointFromRectInt(int position, Point rect)
{
	int c = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < rect.y; i++) {
		for (j = 0; j < rect.x; j++) {
			if (c < position) {
				c++;
			}
			else {
				return { (float)j, (float)i };
			}
		}
		if (c < position) {
			c++;
		}
		else {
			return { (float)j, (float)i };
		}
	}
	return { -1, -1 };
}
