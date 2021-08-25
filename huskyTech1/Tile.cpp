#include "Tile.h"

Tile::Tile()
{
	visible = false;
	col = false;
}

Tile::Tile(const char* filename, SDL_Renderer* renderer, bool v, bool c)
{
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", IMG_GetError(), NULL);
	}
	image = IMG_Load(filename);
	if (image == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", IMG_GetError(), NULL);
	}
	tile_tex = SDL_CreateTextureFromSurface(renderer, image);
	visible = v;
	col = c;
}

Tile::~Tile()
{
	explode();
}

void Tile::Draw(SDL_Renderer* renderer, Point position)
{
	if (!visible)
		return;
	SDL_Rect dstrect = { position.x, position.y, TILESIZE, TILESIZE };
	SDL_RenderCopy(renderer, tile_tex, NULL, &dstrect);
}

void Tile::SetVisibility(bool v)
{
	visible = v;
}

void Tile::SetCollision(bool c)
{
	col = c;
}

bool Tile::GetVisibility()
{
	return visible;
}

bool Tile::GetCollision()
{
	return col;
}

void Tile::explode()
{
	if (tile_tex != NULL) {
		SDL_DestroyTexture(tile_tex);
		SDL_FreeSurface(image);
		tile_tex = NULL;
	}
}
