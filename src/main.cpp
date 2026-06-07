
#include <iostream>
#include <SDL.h>
#include <cstdlib>

int main(int argc, char* argv[]) {

	 if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError();
		return 1;
	}
        
	SDL_Window* window = SDL_CreateWindow("Caboodle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,480, 0);
		if(window == NULL){
		std::cout << "SDL_CreateWindow Error" << SDL_GetError();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError();
		return 1;
	}

	SDL_SetRenderDrawColor(renderer , 255 ,255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(2000);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	
}
