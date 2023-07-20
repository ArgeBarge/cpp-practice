#include "classdefs.h"
#include "draw.h"
App::App() {
	renderer = NULL;
	window = NULL;
	theApp = NULL;
}

App* App::theApp = new App();

Entity::Entity(SDL_Texture *i, int x, int y) {
	this->texture = i;
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 0;
	this->health = 0;
}

Entity::Entity() {
	this->texture = NULL;
	this->x = 0;
	this->y = 0;
	this->dy = 0;
	this->dx = 0;
	this->health = 0;

}

SDL_Texture *Entity::get_texture()
{
	return this->texture;
}

int *Entity::get_x() {
	return &(this->x);
}

int *Entity::get_y() {
	return &(this->y);
}

int* Entity::get_health() {
	return &(this->health);
}
int* Entity::get_dx() {
	return &(this->dx);
}

int* Entity::get_dy() {
	return &(this->dy);
}

Player::Player(int x, int y) {
	this->texture = loadTexture("C:/gimpprojects/ship_big.png");
	this->has_fired = 0;
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 0;
	this->health = 0;

}

int* Player::get_fired() {
	return &(this->has_fired);
}

Bullet::Bullet(int x, int y) {
	this->texture = loadTexture("C:/gimpprojects/projectile.png");
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 0;
	this->health = 0;
}