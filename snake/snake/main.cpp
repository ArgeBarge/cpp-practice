#include <SDL.h>
#include <vector>
#include <algorithm>
#include <deque>

int main(int argc, char **argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event e;
	
	enum Direction {
		DOWN,
		UP,
		LEFT,
		RIGHT
	};

	SDL_Rect head = { 250, 250, 10, 10 };

	std::deque<SDL_Rect> rq;
	int size = 1;
	
	std::deque<SDL_Rect> apples;

	for (int i = 0; i < 100; i++)
	{
		SDL_Rect rect = { rand() % 100 * 10, rand() % 100 * 10, 10, 10 };
		apples.emplace_back(rect);
	}

	bool running = true;
	int dir = 0;

	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) { running = false; }
			else if (e.type = SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_DOWN && dir != UP) { dir = DOWN; }
				else if (e.key.keysym.sym == SDLK_UP && dir != DOWN) { dir = UP; }
				else if (e.key.keysym.sym == SDLK_LEFT) { dir = LEFT; }
				else if (e.key.keysym.sym == SDLK_RIGHT) { dir = RIGHT; }
			}
		}

		switch (dir)
		{
		case DOWN:
			head.y += 10;
			break;
		case UP:
			head.y -= 10;
			break;
		case LEFT:
			head.x -= 10;
			break;
		case RIGHT:
			head.x += 10;
			break;
		}

		// Collision detection
	
		if (head.x == apples.front().x && head.y == apples.front().y) {
			{
				size += 10;
				apples.front().x = -10;
				apples.front().y = -10;
				apples.pop_front();
			}
		}

		// Self collision detection
		std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment) {
			if (head.x == snake_segment.x && head.y == snake_segment.y)
			{
				size = 1;
			}
		});

		rq.push_front(head);
		
		while (rq.size() > size)
			rq.pop_back();


		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment) {
			SDL_RenderFillRect(renderer, &snake_segment);
		});

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		//std::for_each(apples.begin(), apples.end(), [&](auto& apple) {
		//	SDL_RenderFillRect(renderer, &apple);
		//});

		SDL_RenderFillRect(renderer, &apples.front());
		

		SDL_RenderFillRect(renderer, &head);
		SDL_RenderPresent(renderer);
		SDL_Delay(50);
	}
	return 0;
}