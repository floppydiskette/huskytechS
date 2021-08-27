#include "Camera.h"

Camera::Camera(Point pos)
{
	position = HuskyMath::mulPointFloat(pos, -1);
}

void Camera::moveInstant(Point targ)
{
	lerping = false;
	position = HuskyMath::mulPointFloat(targ, -1);
}

void Camera::moveLerp(Point targ)
{
	lerping = true;
	target = targ;
}

void Camera::physicsUpdate(double deltaTime)
{
	if (lerping) {
		position = HuskyMath::point_lerp(position, HuskyMath::mulPointFloat(target, -1), t * deltaTime);
	}
}

Point Camera::getOffset(Point cur)
{
	//camera position is in the center of the screen, so account for that
	return HuskyMath::addPointPoint(Point{ position.x + (SCREEN_WIDTH / 2), position.y + (SCREEN_HEIGHT / 2) }, cur);
}
