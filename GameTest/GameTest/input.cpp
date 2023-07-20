#ifndef _INPUT_H
#define _INPUT_H

#include <SDL.h>
#include "input.h"
#include "classdefs.h"
#include <SDL_events.h>
void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			doKeyDown(&event.key);
			break;
		case SDL_KEYUP:
			doKeyUp(&event.key);
			break;
		default:
			break;
		}

	}
}

void doKeyDown(SDL_KeyboardEvent* event)
{
	App *tapp = App::theApp;

	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			tapp->up = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			tapp->down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			tapp->left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			tapp->right = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_SPACE)
		{
			tapp->fire = 1;
		}
	}
}

void doKeyUp(SDL_KeyboardEvent* event)
{
	App* tapp = App::theApp;
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			tapp->up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			tapp->down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			tapp->left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			tapp->right = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_SPACE)
		{
			tapp->fire = 0;
		}
	}
}
#endif