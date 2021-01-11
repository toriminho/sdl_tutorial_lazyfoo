// https://lazyfoo.net/tutorials/SDL/index.php
// g++ main.cpp -o game -lsdl2
// g++ main.cpp -o game -lSDL2

#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "SDL could not init : " << SDL_GetError() << std::endl;
	}
	else{
		window = SDL_CreateWindow(
			"SDL Tutorial",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
	}

	if(window == nullptr){
		std::cout << "SDL could not be created : " << SDL_GetError() << std::endl;
	}
	else{
		screenSurface = SDL_GetWindowSurface(window);

		SDL_FillRect(
			screenSurface,
			nullptr,
			SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)
		);

		SDL_UpdateWindowSurface(window);
		SDL_Delay(2000);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

