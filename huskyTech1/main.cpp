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
	//Clear screen
	SDL_RenderClear(ht_renderer);

	if (dm)
		mp->Render({ 0,0 });

	az_ch->Draw(ht_renderer, camera);

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
		window = SDL_CreateWindow(GAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

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

				//camera
				camera = new Camera({ 0,0 });

				//this is debug stuffz
				az_ch = new Character(new Sprite("data/character_ss.png", ht_renderer, 4, 3), {50 * TILESIZE, 50 * TILESIZE});
				tile_ren = new TileRenderer(ht_renderer, 4);
				tile_ren->RegisterTexture(TileType::GRASS, "data/grass_t.png");
				tile_ren->RegisterTexture(TileType::STONE, "data/stone_t.png");
				tile_ren->RegisterTexture(TileType::DEV1, "data/dev_t.png");
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