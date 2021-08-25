#include "sprite.h"

Sprite::Sprite(const char* filename, SDL_Renderer* renderer, int rows, int cols)
{
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", IMG_GetError(), NULL);
	}
	image = IMG_Load(filename);
	if (image == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", IMG_GetError(), NULL);
	}
	sprite_tex = SDL_CreateTextureFromSurface(renderer, image);
	SDL_QueryTexture(sprite_tex, NULL, NULL, &sprite_w, &sprite_h);
	sprite_w = sprite_w / cols;
	sprite_h = sprite_h / rows;
}

Sprite::~Sprite()
{
	explode();
}

void Sprite::renderAtScreenPos(SDL_Renderer* renderer, int x, int y, int row, int col)
{
	if (sprite_tex == nullptr) {
		return;
	}
	SDL_Rect srcrect = { sprite_w * col, sprite_h * row, sprite_w, sprite_h };
	SDL_Rect dstrect = { x, y, sprite_w, sprite_h };

	SDL_RenderCopy(renderer, sprite_tex, &srcrect, &dstrect);
}

void Sprite::explode()
{
	if (sprite_tex != NULL) {
		SDL_DestroyTexture(sprite_tex);
		SDL_FreeSurface(image);
		sprite_tex = NULL;
		sprite_w = 0;
		sprite_h = 0;
	}
}
