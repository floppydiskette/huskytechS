#pragma once
#include "ht_types.h"
#include "HuskyMath.h"
#include "HuskySTD.h"


//i really hope this works, because i have no idea what it does
class Perlin
{
public:
    Perlin();
    Perlin(int rp);
    ~Perlin();

    double get(Point pos);

private:
    int repeat = -1;

    int p[512];

    const double const_z = 5;

    void init();
    void explode();

    double fade(double t);
    double grad(int hash, Point pos);
    int inc(int num);
};

