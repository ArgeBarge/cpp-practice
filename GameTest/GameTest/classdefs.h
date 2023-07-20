#include <SDL.h>

class App {
	App();

public:
	SDL_Renderer* renderer;
	SDL_Window* window;
	int up;
	int down;
	int left;
	int right;
	int fire;
	static App* theApp;
};

class Entity {

protected:
	int x;
	int y;
	int dx;
	int dy;
	int health;
	SDL_Texture* texture;

public:
	Entity(SDL_Texture*, int, int);
	Entity();
	SDL_Texture* get_texture();
	int *get_x();
	int *get_y();
	int* get_dx();
	int* get_dy();
	int* get_health();

};

class Player : public Entity {
	int has_fired;
public:
	Player(int, int);
	int* get_fired();
};
class Bullet : public Entity {
public:
	Bullet(int, int);
};