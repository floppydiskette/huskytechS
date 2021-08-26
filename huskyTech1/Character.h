#pragma once
#include "Entity.h"
#include "ht_types.h"
#include "HuskyMath.h"
#include "Blendspace.h"
#include "Camera.h"


class Character :
    public Entity
{
public:
    Character(Sprite* spr, Point pos);

    //void Update() override;

    void PhysicsUpdate(double deltaTime);

    void Draw(SDL_Renderer* renderer, Camera* camera) override;

    void SetInputX(float x);
    void SetInputY(float y);

private:
    const float SPEED = 120;
    const double ACCELERATION = 20;

    Point input_vector;
    double delta_time;

    Blendspace* ch_bs;
};

