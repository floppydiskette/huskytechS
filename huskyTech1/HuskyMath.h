#pragma once
#include <algorithm>
#include "ht_types.h"

class HuskyMath
{
public:
	static float clamp(float n, float lower, float upper);
	static float lerp(float v0, float v1, float t);

	static Point point_lerp(Point v0, Point v1, float t);

	static bool arePointSame(Point a, Point b);

	static Point mulPointInt(Point a, int b);
	static Point mulPointFloat(Point a, float b);

	static Point addPointPoint(Point a, Point b);
	
};

