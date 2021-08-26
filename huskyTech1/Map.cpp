#include "Map.h"

Map::Map(Camera* camera, TileRenderer* tileren, int width, int height)
{
	tile_ren = tileren;
	cam = camera;
	map_ground = new Matrix<TileType>(width, height);
	/*
	for (int i = 0; i < map_ground->getSizeY(); i++) {
		for (int j = 0; j < map_ground->getSizeX(); j++) {
			map_ground->set(TileType(rand() % 4), j, i);
		}
	}
	*/
}

Map::~Map()
{
	explode();
}

void Map::setTile(Point pos, TileType tile)
{
	if (pos.x > map_ground->getSizeX() || pos.y > map_ground->getSizeY())
		return;

	map_ground->set(tile, pos.x, pos.y);
}

void Map::Render(Point offset)
{
	offset = cam->getOffset(offset);
	//this is the area of the map that we will draw
	Point occluded_min = { 0,0 };
	Point occluded_max = { map_ground->getSizeX(), map_ground->getSizeY() };


	//occlusion culling
	if (offset.x * TILESIZE < 0) {
		//let a be absolute offset x
		//let c be TILESIZE
		//amount of tiles to cull from the left is (int)(a/c)
		occluded_min.x = (int)(abs((int)offset.x) / TILESIZE);
	}
	if (offset.y * TILESIZE < 0) {
		occluded_min.y = (int)(abs((int)offset.y) / TILESIZE);
	}
	if (((map_ground->getSizeX() - offset.x) * TILESIZE) > SCREEN_WIDTH) {
		occluded_max.x = (SCREEN_WIDTH / TILESIZE) + occluded_min.x + 3; //add three just to make sure
	}
	if (((map_ground->getSizeY() - offset.y) * TILESIZE) > SCREEN_HEIGHT) {
		occluded_max.y = (SCREEN_HEIGHT / TILESIZE) + occluded_min.y + 3; //add three just to make sure
	}

	//for debugging, make sure that occlusion culling works
	//occluded_min = HuskyMath::addPointFloat(occluded_min, 1);
	//occluded_max = HuskyMath::addPointFloat(occluded_max, -2);

	//draw the tiles
	for (int i = occluded_min.x; i < occluded_max.x; i++) {
		for (int j = occluded_min.y; j < occluded_max.y; j++) {
			tile_ren->Draw(map_ground->get(i, j), { (i * TILESIZE) + offset.x, (j * TILESIZE) + offset.y });
		}
	}
}

void Map::explode()
{
	if (map_ground != NULL) {
		delete map_ground;
		map_ground = NULL;
	}
}
