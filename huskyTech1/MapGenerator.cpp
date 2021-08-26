#include "MapGenerator.h"

Map* MapGenerator::generateMap(Camera* camera, TileRenderer* tile_ren)
{
    Perlin* noise = new Perlin();
    Map* map = new Map(camera, tile_ren, WORLD_SIZE_X, WORLD_SIZE_Y);

    for (int x = 0; x < WORLD_SIZE_X; x++) {
        for (int y = 0; y < WORLD_SIZE_Y; y++) {
            map->setTile({ (float)x, (float)y }, determineType(noise->get({ (float)x,(float)y })));
        }
    }
    
    //clean up
    delete noise;

    return map;
}

TileType MapGenerator::determineType(double value)
{
    if ((int)value < (int)(value + 0.5)) { //if closer to 1
        return TileType::GRASS;
    }
    else { //if closer to 0
        return TileType::STONE;
    }
}
