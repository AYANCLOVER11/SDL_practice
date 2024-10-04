
#include "SDL.h"

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	if (!window) {
		SDL_Log("Window could not be created! SDL_Error: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}


	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		SDL_Log("Renderer could not be created! SDL_Error: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);




	return 0;
}