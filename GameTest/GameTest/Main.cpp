#include <iostream>
#include <SDL.h>
#include <string>
#include "init.h"
#include "input.h"
#include "draw.h"
#include "classdefs.h"
#include <windows.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {

	int moveSpeed = 4;
	App* tapp = App::theApp;

	initSDL();

	atexit(SDL_Quit);
	
	Player* player = new Player(0, 0);
	Bullet* bullet = new Bullet(0, 0);

	while (1)
	{
		prepareScene();

		doInput();
		
		if (*(player->get_y()) < 0)
		{
			*(player->get_y()) += 1;
			continue;
		}
			
		if (*(player->get_x()) < 0)
		{
			*(player->get_x()) += 1;
			continue;
		}
			
		if (tapp->up)
			*(player->get_y()) -= moveSpeed;

		if (tapp->down)
			*(player->get_y()) += moveSpeed;
		
		if (tapp->left)
			*(player->get_x()) -= moveSpeed;

		if (tapp->right)
			*(player->get_x()) += moveSpeed;

		if (tapp->fire && *bullet->get_health() == 0)
		{
			*bullet->get_x() = *player->get_x() + 200;
			if (!*player->get_fired())
			{
				*bullet->get_y() = *player->get_y();
				*player->get_fired() = ~*player->get_fired();
			}
			else
			{
				*bullet->get_y() = *player->get_y() + 110;
				*player->get_fired() = ~*player->get_fired();
			}
			*bullet->get_dx() = 16;
			*bullet->get_dy() = 0;
			*bullet->get_health() = 1;
		}

		*bullet->get_x() += *bullet->get_dx();
		*bullet->get_y() += *bullet->get_dy();

		if (*bullet->get_x() > SCREEN_WIDTH)
			*bullet->get_health() = 0;

		blit(player->get_texture(), *player->get_x(), *player->get_y());

		if (*bullet->get_health() > 0)
			blit(bullet->get_texture(), *bullet->get_x(), *bullet->get_y());

		presentScene();

		SDL_Delay(16);
	}
	
	delete player;
	delete bullet;

	return 0;
	
}

std::wstring get_path() {

	

	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	return std::wstring(buffer).substr(0, pos);
	
}