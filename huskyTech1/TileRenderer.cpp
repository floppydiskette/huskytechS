#include "TileRenderer.h"

TileRenderer::TileRenderer(SDL_Renderer* renderer, int texture_num)
{
	ht_renderer = renderer;
	max_textures = texture_num;
	atlas_size = HuskySTD::generateRectFromArea(texture_num);
	tile_atlas = SDL_CreateTexture(ht_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, atlas_size.x * TILESIZE, atlas_size.y * TILESIZE);
	pos_list = new Point[texture_num];
	ClearAtlas();
}

TileRenderer::~TileRenderer()
{
	explode();
}

void TileRenderer::RegisterTexture(TileType tile, const char* filename)
{
	if (tile > max_textures) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", "TILE NUMBER GREATER THAN ALLOCATED!", NULL);
		return;
	}
	if (tile < 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", "TILE NUMBER LESS THAN ZERO!", NULL);
		return;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", IMG_GetError(), NULL);
	}
	SDL_Surface* image = IMG_Load(filename);
	if (image == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", IMG_GetError(), NULL);
	}
	SDL_Texture* tmp_tex = SDL_CreateTextureFromSurface(ht_renderer, image);
	SDL_FreeSurface(image);

	SDL_SetRenderTarget(ht_renderer, tile_atlas);

	Point send_to = HuskySTD::getPointFromRectInt(tile, atlas_size);
	pos_list[tile] = send_to;
	SDL_Rect dstrect = { send_to.x * TILESIZE, send_to.y * TILESIZE, TILESIZE, TILESIZE };
	SDL_RenderCopy(ht_renderer, tmp_tex, NULL, &dstrect);
	
	SDL_SetRenderTarget(ht_renderer, NULL);

	SDL_DestroyTexture(tmp_tex);

}

void TileRenderer::Draw(TileType tile, Point position)
{
	if (tile > max_textures) {
		//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", "TILE NUMBER GREATER THAN ALLOCATED!", NULL);
		//return;

		tile = TileType::DEV1;
	}
	if (tile < 0) {
		//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "HECK!", "TILE NUMBER LESS THAN ZERO!", NULL);
		//return;
		tile = TileType::DEV1;
	}
	SDL_Rect srcrect = { pos_list[tile].x * TILESIZE, pos_list[tile].y * TILESIZE, TILESIZE, TILESIZE };
	SDL_Rect dstrect = { position.x, position.y, TILESIZE, TILESIZE };

	SDL_RenderCopy(ht_renderer, tile_atlas, &srcrect, &dstrect);
}

void TileRenderer::ClearAtlas()
{
	SDL_SetRenderTarget(ht_renderer, tile_atlas);
	SDL_RenderClear(ht_renderer);
	SDL_SetRenderTarget(ht_renderer, NULL);
}

void TileRenderer::explode()
{
	if (tile_atlas != NULL) {
		SDL_DestroyTexture(tile_atlas);
		tile_atlas = NULL;
	}
	if (pos_list != NULL) {
		delete pos_list;
		pos_list = NULL;
	}
}
