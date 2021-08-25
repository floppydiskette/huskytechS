#include "Entity.h"



Entity::Entity()
{
    en_sprite = NULL;
    position = { 0, 0 };
}

Entity::Entity(Sprite* spr, Point pos)
{
    en_sprite = spr;
    position = pos;
}

void Entity::Update()
{
}

void Entity::Draw(SDL_Renderer* renderer)
{
    en_sprite->renderAtScreenPos(renderer, position.x, position.y, 0, 0);
}

void Entity::SetPosition(Point pos)
{
    position = pos;
}

Point Entity::GetPosition()
{
    return position;
}

void Entity::AddPosition(Point pos)
{
    position = HuskyMath::addPointPoint(position, pos);
}

void Entity::SetVelocity(Point vel)
{
    velocity = vel;
}

Point Entity::GetVelocity()
{
    return velocity;
}
