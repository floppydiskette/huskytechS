#pragma once
#include "ht_types.h"
#include "HuskyMath.h"
#include "SETTINGS.h"

class Camera
{
public:
	Camera(Point pos);

	void moveInstant(Point targ);

	void moveLerp(Point targ);

	void physicsUpdate(double deltaTime);

	Point getOffset(Point cur);

private:
	Point position;

	Point target;

	bool lerping = false;

	const float t = 2;
};

