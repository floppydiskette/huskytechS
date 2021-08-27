#pragma once
#include "PerlinNoise.hpp"
#include "Map.h"
#include "Camera.h"
#include "TileRenderer.h"
#include "SETTINGS.h"
#include "ht_types.h"

class MapGenerator
{
public:
	static Map* generateMap(Camera* camera, TileRenderer* tile_ren);
	
private:
	static TileType determineType(double value);
};

