#include "Perlin.h"

Perlin::Perlin()
{
    repeat = -1;
    init();
}

Perlin::Perlin(int rp)
{
    repeat = rp;
    init();
}

Perlin::~Perlin()
{
    explode();
}

double Perlin::get(Point pos)
{
    int tmp_z = const_z;
    if (repeat > 0) {
        pos.x = fmod(pos.x, repeat);
        pos.y = fmod(pos.y, repeat);
        tmp_z = fmod(tmp_z, repeat);
    }
    int xi = (int)pos.x & 255;
    int yi = (int)pos.y & 255;
    int zi = (int)tmp_z & 255;
    double xf = pos.x - (int)pos.x;
    double yf = pos.y - (int)pos.y;
    double zf = tmp_z - (int)tmp_z;

    double u = fade(xf);
    double v = fade(yf);
    double w = fade(zf);

    int aaa, aba, aab, abb, baa, bba, bab, bbb;
    aaa = p[p[p[xi] + yi] + zi];
    aba = p[p[p[xi] + inc(yi)] + zi];
    aab = p[p[p[xi] + yi] + inc(zi)];
    abb = p[p[p[xi] + inc(yi)] + inc(zi)];
    baa = p[p[p[inc(xi)] + yi] + zi];
    bba = p[p[p[inc(xi)] + inc(yi)] + zi];
    bab = p[p[p[inc(xi)] + yi] + inc(zi)];
    bbb = p[p[p[inc(xi)] + inc(yi)] + inc(zi)];

    double x1, x2, y1, y2;
    x1 = HuskyMath::lerp(grad(aaa, { (float)xf, (float)yf }), grad(baa, { (float)xf - 1, (float)yf }), u);
    x2 = HuskyMath::lerp(grad(aba, { (float)xf - 1, (float)yf }), grad(bba, { (float)xf - 1, (float)yf - 1 }), u);

    y1 = HuskyMath::lerp(x1, x2, v);

    x1 = HuskyMath::lerp(grad(aab, { (float)xf,(float)yf }), grad(bab, { (float)xf - 1, (float)yf }), u);
    x2 = HuskyMath::lerp(grad(abb, { (float)xf,(float)xf - 1 }), grad(bbb, { (float)xf - 1,(float)yf - 1 }), u);

    y2 = HuskyMath::lerp(x1, x2, v);

    return (HuskyMath::lerp(y1, y2, w) + 1) / 2;
}

double Perlin::octave(Point pos, int octaves, double persistence)
{
    double total = 0;
    double frequency = 1;
    double amplitude = 1;
    double max_value = 0;
    for (int i = 0; i < octaves; i++) {
        total += get({ pos.x * (float)frequency, pos.y * (float)frequency }) * amplitude;
        max_value += amplitude;
        amplitude *= persistence;
        frequency *= 2;
    }

    return total / max_value;
}

double Perlin::fade(double t)
{
    return t * t * t * (t * (t * 6 - 15) + 10); //haha stealing ur code ken perlin (:<
}

double Perlin::grad(int hash, Point pos)
{
    switch (hash & 0xF)
    {
    case 0x0: return  pos.x + pos.y;
    case 0x1: return -pos.x + pos.y;
    case 0x2: return  pos.x - pos.y;
    case 0x3: return -pos.x - pos.y;
    case 0x4: return  pos.x + const_z;
    case 0x5: return -pos.x + const_z;
    case 0x6: return  pos.x - const_z;
    case 0x7: return -pos.x - const_z;
    case 0x8: return  pos.y + const_z;
    case 0x9: return -pos.y + const_z;
    case 0xA: return  pos.y - const_z;
    case 0xB: return -pos.y - const_z;
    case 0xC: return  pos.y + pos.x;
    case 0xD: return -pos.y + const_z;
    case 0xE: return  pos.y - pos.x;
    case 0xF: return -pos.y - const_z;
    default: return 0; // never happens
    }
}

int Perlin::inc(int num)
{
    num++;
    if (repeat > 0) num %= repeat;

    return num;
}

void Perlin::init() //actually initialize the class
{
    /*
    int* p_256 = new int[256];
    for (int i = 0; i < 256; i++) {
        p_256[i] = i;
    }
    HuskySTD::shuffleArray<int>(p_256, sizeof(p_256)); //shuffle that array
    */
    HuskySTD::shuffleArray<int>(permutation, 256);

    for (int i = 0; i < 512; i++) { //fill it
        p[i] = permutation[i % 256];
    }

    //delete p_256; //clean up after ourselves
}

void Perlin::explode()
{
}
