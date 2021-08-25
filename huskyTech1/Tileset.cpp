#include "Tileset.h"

Tileset::Tileset()
{
}

Tileset::~Tileset()
{
}

void Tileset::addTile(const char* filename, SDL_Renderer* renderer)
{
	if (sizeof(tiles) < 1) {
		Tile* tmp_array = new Tile[1];
		tmp_array[0] = Tile(filename, renderer);
		tiles = tmp_array;
	}
	else {
		HuskySTD::addArrayTile(tiles, sizeof(tiles), Tile(filename, renderer));
	}
}

void Tileset::addTile(const char* filename, bool visible, bool collide, SDL_Renderer* renderer)
{
	if (sizeof(tiles) < 1) {
		Tile* tmp_array = new Tile[1];
		tmp_array[0] = Tile(filename, renderer);
		tiles = tmp_array;
	}
	else {
		HuskySTD::addArrayTile(tiles, sizeof(tiles), Tile(filename, renderer, visible, collide));
	}
}

void Tileset::addTile(Tile new_tile, SDL_Renderer* renderer)
{
	if (sizeof(tiles) < 1) {
		Tile* tmp_array = new Tile[1];
		tmp_array[0] = new_tile;
		tiles = tmp_array;
	}
	else {
		HuskySTD::addArrayTile(tiles, sizeof(tiles), new_tile);
	}
}

void Tileset::drawTile(SDL_Renderer* renderer, int tile, Point position)
{
	tiles[tile].Draw(renderer, position);
}

void Tileset::explode()
{
}
