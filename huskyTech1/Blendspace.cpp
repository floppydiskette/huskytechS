#include "Blendspace.h"

Blendspace::Blendspace(Sprite* spr, int udlr[4], int steporder[3], float framesps)
{
	sprite = spr;
	memcpy_s(udlro, 4 * sizeof(int), udlr, 4 * sizeof(int));
	int tmp[4] = { steporder[0], steporder[1], steporder[0], steporder[2] };
	memcpy_s(sorder, 4 * sizeof(int), tmp, 4 * sizeof(int));
	fps = framesps;
}

void Blendspace::Draw(SDL_Renderer* renderer, Point input_vec, Point position, double deltaTime)
{
	timer += deltaTime;
	if (timer >= fps) {
		timer = 0;
		frame++;
	}
	if (frame > 3) {
		frame = 0;
	}

	switch ((int)input_vec.x) {
		case 1: //right
			direction = 3;
			break;
		case -1: //left
			direction = 2;
			break;
	}
	switch ((int)input_vec.y) {
		case 1: //down
			direction = 1;
			break;
		case -1: //up
			direction = 0;
			break;
	}

	if (!HuskyMath::arePointSame(input_vec, { 0, 0 }))
	{
		sprite->renderAtScreenPos(renderer, position.x, position.y, udlro[direction], sorder[frame]);
	}
	else {
		sprite->renderAtScreenPos(renderer, position.x, position.y, udlro[direction], sorder[0]);
	}
}
