#pragma once
#include "ht_types.h"
#include "SETTINGS.h"
#include "TileRenderer.h"
#include "Matrix.h"
#include "Camera.h"

class Map
{
public:
	Map(Camera* camera, TileRenderer* tileren, int width = 10, int height = 10);
	~Map();

	void setTile(Point pos, TileType tile);

	void Render(Point offset);

	void explode();

private:
	TileRenderer* tile_ren;
	Camera* cam;

	Matrix<TileType>* map_ground;

};

