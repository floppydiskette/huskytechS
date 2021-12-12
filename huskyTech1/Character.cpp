#include "Character.h"

Character::Character(Sprite* spr, Point pos) : Entity(spr, pos) {
	int udlr[] = { 3, 0, 1, 2 };
	int so[] = { 1, 0, 2 };
	ch_bs = new Blendspace(spr, udlr, so, 0.2f);
	input_vector = { 0,0 };
	delta_time = 0;
}

void Character::PhysicsUpdate(double deltaTime)
{
	delta_time = deltaTime;
	//for reference, older code
	//az_en->SetPosition({ az_en->GetPosition().x + (az_en->velocity.x * speed * (float)deltaTime), az_en->GetPosition().y + (az_en->velocity.y * speed * (float)deltaTime) });

	if (!HuskyMath::arePointSame(input_vector, { 0,0 })) {
		Entity::SetVelocity(HuskyMath::point_lerp(Entity::GetVelocity(), HuskyMath::mulPointFloat(input_vector, SPEED), ACCELERATION * (deltaTime)));
	}
	else {
		Entity::SetVelocity(HuskyMath::point_lerp(Entity::GetVelocity(), { 0,0 }, ACCELERATION * (deltaTime)));
	}

	Entity::AddPosition(HuskyMath::mulPointFloat(Entity::GetVelocity(), (deltaTime)));
}


void Character::Draw(SDL_Renderer* renderer, Camera* camera)
{
	Point pos = camera->getOffset(Entity::GetPosition());
	ch_bs->Draw(renderer, input_vector, pos, delta_time);
}


void Character::SetInputX(float x)
{
	input_vector.x = x;
}

void Character::SetInputY(float y)
{
	input_vector.y = y;
}
