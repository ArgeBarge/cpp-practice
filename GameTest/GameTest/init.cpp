#include "init.h"
#include "classdefs.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

void initSDL(void) {
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Couldn't initialise: " << SDL_GetError() << "\n";
		exit(1);
	}

	App::theApp->window = SDL_CreateWindow("test window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!App::theApp->window)
	{
		std::cout << "Failed to open window " << SDL_GetError() << "\n";
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	App::theApp->renderer = SDL_CreateRenderer(App::theApp->window, -1, rendererFlags);

	if (!App::theApp->renderer)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << "\n";
		exit(1);
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}



