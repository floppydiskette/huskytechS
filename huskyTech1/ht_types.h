#pragma once
#include "Sprite.h"

struct Point {
	float x = 0;
	float y = 0;
};

//unsafe, but ehh heck it (:
enum TileType {
	GRASS = 0,
	SAND = 1,
	WATER = 2,
	STONE = 3,
};