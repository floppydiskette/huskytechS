#include "MapGenerator.h"

Map* MapGenerator::generateMap(Camera* camera, TileRenderer* tile_ren)
{
    siv::PerlinNoise noise = siv::PerlinNoise(std::random_device());
    Map* map = new Map(camera, tile_ren, WORLD_SIZE_X, WORLD_SIZE_Y);

    float size = 0.03f;

    for (int x = 0; x < WORLD_SIZE_X; x++) {
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            double e = noise.noise2D_0_1((x * size) + 0.5, (y * size) + 0.5);
            //e = e / (1 + 0.5 + 0.25);
            map->setTile( { (float)x, (float)y }, determineType( abs(e) ) );
        }
    }
    
    //clean up
    //delete noise;

    return map;
}

TileType MapGenerator::determineType(double value)
{
    if (value < 0.39) {
        return TileType::WATER;
    }
    else if (value < 0.42) {
        return TileType::SAND;
    }
    else if (value < 0.6) {
        return TileType::GRASS;
    }
    else {
        return TileType::STONE;
    }
}
