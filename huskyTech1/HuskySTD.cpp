#include "HuskySTD.h"

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
