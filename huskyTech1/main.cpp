#include "main.h"



//update code and stuff here



void input_update() {
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type) {

			case SDL_QUIT:
				explode();
				break;

			case SDL_KEYDOWN:
				handle_keyboard_movement(e, az_ch);
				break;

			case SDL_KEYUP:
				switch (e.key.keysym.sym) { //i bet u guys love all these switch statements

					case SDLK_ESCAPE:
						explode();
						break;

					case SDLK_t:
						dm = !dm;
						break;

					default:
						handle_keyboard_movement(e, az_ch);
						break;

				}
				break;

		}
	}
}



void physics_update() {
	camera->moveLerp(az_ch->GetPosition());

	az_ch->PhysicsUpdate(deltaTime);
	camera->physicsUpdate(deltaTime);
}



void update() {

}



void draw() {
	//set target to render texture
	SDL_SetRenderTarget(ht_renderer, render_tex);
	SDL_RenderClear(ht_renderer);
	//render stuff to the texture

	if (dm)
		mp->Render({ 0,0 });

	az_ch->Draw(ht_renderer, camera);

	//set target to screen
	SDL_SetRenderTarget(ht_renderer, NULL);
	SDL_RenderClear(ht_renderer);

	SDL_RenderCopy(ht_renderer, render_tex, NULL, NULL);

	//Update screen
	SDL_RenderPresent(ht_renderer);
}



void handle_keyboard_movement(SDL_Event kev, Character* en) {
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[C_forward])
		en->SetInputY(-1);
	else if (state[C_backward])
		en->SetInputY(1);
	else
		en->SetInputY(0);
	if (state[C_sleft])
		en->SetInputX(-1);
	else if (state[C_sright])
		en->SetInputX(1);
	else
		en->SetInputX(0);
}



//required code down here
int main(int argc, char* args[]) {

	//init
	if (init()) {
		
		//program ready, let's start running the code
		while (alive) {
			LAST = NOW;
			NOW = SDL_GetPerformanceCounter();
			deltaTime = ((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

			input_update();

			if (!alive) //the program may no longer be alive after the previous function, therefore we need to check and terminate if needed
				break;

			physics_update();

			update();

			draw();
		}

	}
	else {
		return -1;
	}

	return 0;
}


//initialize sdl stuff
bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}
	else {
		//no issue
		window = SDL_CreateWindow(GAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			return false;
		}
		else {
			//no issue again, window now open
			ht_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (ht_renderer == NULL) {
				return false;
			}
			else {
				//init deltaTime
				NOW = SDL_GetPerformanceCounter();
				LAST = NOW;
				NOW = SDL_GetPerformanceCounter();
				deltaTime = 0;

				render_tex = SDL_CreateTexture(ht_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);

				//camera
				camera = new Camera({ (WORLD_SIZE_X / 2) * TILESIZE, (WORLD_SIZE_Y / 2) * TILESIZE });

				//this is debug stuffz
				az_ch = new Character(new Sprite("data/character_ss.png", ht_renderer, 4, 3), {(WORLD_SIZE_X / 2) * TILESIZE, (WORLD_SIZE_Y / 2) * TILESIZE});
				tile_ren = new TileRenderer(ht_renderer, 4);
				tile_ren->RegisterTexture(TileType::GRASS, "data/grass_t.png");
				tile_ren->RegisterTexture(TileType::SAND, "data/dev0_t.png");
				tile_ren->RegisterTexture(TileType::WATER, "data/dev1_t.png");
				tile_ren->RegisterTexture(TileType::STONE, "data/stone_t.png");
				mp = MapGenerator::generateMap(camera, tile_ren);


				alive = true;
				return true;
			}
		}
	}
}


//deallocate sdl stuff
void explode() {
	alive = false; //make sure that the main loop doesn't continue

	delete az_ch;
	delete tile_ren;
	delete mp;

	delete camera;

	IMG_Quit();

	SDL_DestroyWindow(window);

	SDL_Quit();
}