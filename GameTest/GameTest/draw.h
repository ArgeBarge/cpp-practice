#include <string>
#include <SDL.h>
#include <SDL_image.h>
void prepareScene();
void presentScene();

SDL_Texture* loadTexture(std::string filename);
void blit(SDL_Texture*, int, int);