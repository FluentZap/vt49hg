#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include "VTStart.h"

using namespace std;


const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 1280;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


bool quit = false;
int framsPerSec;


SDL_Rect rect1, rect2;
double dist1;



void main_loop()
{
	while (SDL_PollEvent(&e) != 0) { handleUI(e); }
	render();
}



void handleUI(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_1)
		{
			Mix_PlayChannel( 2, sfx1, 0 );
			Mix_SetPanning(2, 120, 0);
		}
		if (e.key.keysym.sym == SDLK_2)
		{
			Mix_PlayChannel( 1, sfx2, 0 );
			Mix_SetPanning(1, 0, 120);
		}
		
		
		if (e.key.keysym.sym == SDLK_LEFT)
		{
				rect1.x--;
		}
		
		if (e.key.keysym.sym == SDLK_RIGHT)
		{
				rect1.x++;
		}
		
	}

	if (e.type == SDL_KEYUP)
	{

		
	}


	if (e.type == SDL_KEYDOWN) if (e.key.keysym.sym == SDLK_ESCAPE) quit = true;

	//Quit if escape is detected
	if (e.type == SDL_QUIT)
		quit = true;
}


void render()
{
	SDL_SetRenderDrawColor(gRenderer, 10, 10, 10, 255);
	SDL_RenderClear(gRenderer);
	
	setRenderColor(255, 255, 255, 255);
	SDL_Rect rect = {100, 100, 900, 900};
	SDL_RenderDrawRect(gRenderer, &rect);
	
	SDL_RenderDrawRect(gRenderer, &rect1);
	
	SDL_Color color = setColor(255, 255, 255, 255);
	render_text(gRenderer, 0, 0, "VT-49 OS TEST BUILD 0.0.1", gFontAure, &color);
	render_text(gRenderer, 80, 30, "VT-49 OS TEST BUILD 0.0.1", gFontAG, &color);
	render_text(gRenderer, 900, 0, to_string(framsPerSec).c_str(), gFontAG, &color);
	
	render_text(gRenderer, 600, 600, to_string(dist1).c_str(), gFontAG, &color);
	dist1 += 0.000001;
	if (dist1 > 10000) dist1 = -10000;
	SDL_RenderPresent(gRenderer);
}




bool init()
{
	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) { printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); return false; }

	gWindow = SDL_CreateWindow("Screen App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);
	if (gWindow == NULL) { printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); return false; }

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) { printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError()); return false; }

	TTF_Init();

	gScreenSurface = SDL_GetWindowSurface(gWindow);
	
	if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() ); return false;}	
	
	SDL_ShowCursor(SDL_DISABLE);
	return true;
}

bool loadResources()
{
	bool success = true;
	//Load Fonts
	gFontAure = TTF_OpenFont("Aurebesh.ttf", 22);
	gFontAG = TTF_OpenFont("AG-Stencil.ttf", 22);
	
	//Load Images
	//gXOut = imageLoader("x.png");
	//gTexture = loadTexture("images\\portrait\\elf.png");
	//gTexture = loadTexture("elf.png");
	//gTexture = loadTexture("elf.jpg");
	//if( gTexture == NULL ) {printf( "Unable to load image %s! SDL Error: %s\n", "x.png", SDL_GetError() ); success = false;}
	
	//Load Music/SFX
	//gMusic = Mix_LoadMUS( "BEEP.mp3" );
	sfx1 = Mix_LoadWAV( "BEEP.wav" );
	sfx2 = Mix_LoadWAV( "WELD2.wav" );
	return success;
}

void close()
{
	//Deallocate surface
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);

	gWindow = NULL;
	gRenderer = NULL;

	Mix_FreeChunk(sfx1);
	Mix_FreeChunk(sfx2);
	sfx1 = NULL;
	sfx2 = NULL;
	gMusic = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

}




int main(int argc, char **argv)
{
	
	if (init())
	{
		
		Uint32 startTicks;
		Uint32 fpsTicks;
		int fps;
		
		loadResources();
		
		fpsTicks = SDL_GetTicks();
		
		//While application is running
		while (!quit)
		{
			startTicks = SDL_GetTicks();
			
			main_loop();
			fps++;

			if (SDL_GetTicks() >= fpsTicks + 1000)
			{
				framsPerSec = fps;
				fps = 0;
				fpsTicks = SDL_GetTicks();
			}
			int frameTicks = SDL_GetTicks() - startTicks;
			if (frameTicks < SCREEN_TICKS_PER_FRAME)
			{
				SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
			}
		}

	}
	else printf("Failed to initialize!\n");
	
	close();
	return 0;
}

void setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	if (gRenderer != NULL)
		SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
}

void setRenderColor(SDL_Color c)
{
	if (gRenderer != NULL)
		SDL_SetRenderDrawColor(gRenderer, c.r, c.g, c.b, c.a);
}

SDL_Color setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color color;
	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

void render_text(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Color *color)
{
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect rect;

	surface = TTF_RenderText_Solid(font, text, *color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	rect.x = x;
	rect.y = y;
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_FreeSurface(surface);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}