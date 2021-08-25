#pragma once
#include "Sprite.h"
#include "ht_types.h"
#include "HuskyMath.h"
#include "HuskySTD.h"

class Blendspace
{
public:
	//params are: sprite; rows for (in order in array) up, down, left, right; cols for (in order in array) standing still, step 1, step 2. designed to be used with rpgmaker sprite sheet
	Blendspace(Sprite* spr, int udlr[4], int steporder[3], float framesps);

	void Draw(SDL_Renderer* renderer, Point input_vec, Point position, double deltaTime);

private:
	Sprite* sprite;
	int udlro[4];
	int sorder[4];
	double fps;

	float timer = 0.0f;
	int frame = 0;
	int direction = 0;
};

