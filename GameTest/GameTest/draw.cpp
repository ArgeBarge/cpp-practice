#include "classdefs.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#ifndef _DRAW_H
#define _DRAW_H

void prepareScene() {
	SDL_SetRenderDrawColor(App::theApp->renderer, 96, 128, 255, 255);
	SDL_RenderClear(App::theApp->renderer);
}

void presentScene() {
	SDL_RenderPresent(App::theApp->renderer);
}

SDL_Texture* loadTexture(std::string filename)
{
	const char* c_filename;
	SDL_Texture* texture;

	c_filename = filename.c_str();

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", c_filename);

	texture = IMG_LoadTexture(App::theApp->renderer, c_filename);

	return texture;
}

void blit(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(App::theApp->renderer, texture, NULL, &dest);
}
#endif