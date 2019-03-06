#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();
	
	SDL_Quit();
	
	return 0;
}
