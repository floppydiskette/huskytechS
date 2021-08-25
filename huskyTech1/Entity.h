#pragma once
#include <SDL.h>
#include "ht_types.h"
#include "HuskyMath.h"
#include "Sprite.h"

class Entity
{
	
public:
	Entity();
	Entity(Sprite* spr, Point pos = { 0, 0 });

	virtual void Update();

	virtual void Draw(SDL_Renderer* renderer);

	virtual void SetPosition(Point pos);

	virtual Point GetPosition();

	virtual void AddPosition(Point pos);

	virtual void SetVelocity(Point vel);

	virtual Point GetVelocity();

private:
	Point position;
	Sprite* en_sprite;
	Point velocity = { 0, 0 };
};

