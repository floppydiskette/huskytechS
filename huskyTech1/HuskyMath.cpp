#include "HuskyMath.h"

float HuskyMath::clamp(float n, float lower, float upper)
{
    return std::max(lower, std::min(n, upper));
}

//imprecise method that i copypasted from wikipedia (:
float HuskyMath::lerp(float v0, float v1, float t) {
    return v0 + t * (v1 - v0);
}

Point HuskyMath::point_lerp(Point v0, Point v1, float t)
{
    return { lerp(v0.x,v1.x,t), lerp(v0.y,v1.y,t) };
}

bool HuskyMath::arePointSame(Point a, Point b)
{
    return (a.x == b.x && a.y == b.y);
}

Point HuskyMath::mulPointInt(Point a, int b)
{
    return { a.x * b, a.y * b };
}

Point HuskyMath::mulPointFloat(Point a, float b)
{
    return { a.x * b, a.y * b };
}

Point HuskyMath::addPointPoint(Point a, Point b)
{
    return { a.x + b.x, a.y + b.y };
}
