#ifndef VTSTART
#define VTSTART


#include "SDL.h"
#include <SDL_FontCache.h>

//#include "reactphysics3d.h"
//#include "q3.h"

using namespace std;



bool init();
bool loadResources();
void render();
//Render the Galaxy at the location
void renderGalaxyMap(int, int);
void close();

void Serial_Connect();
void Serial_Read();
void Serial_Write();


SDL_Texture* loadTexture(std::string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gXOut = NULL;
SDL_Texture* gTexture = NULL;


void handleUI(SDL_Event);
//void render_text(SDL_Renderer, int, int, const char, TTF_Font, SDL_Color);
void render_text(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Color *color);

SDL_Color setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

Mix_Music *gMusic = NULL;
Mix_Chunk *sfx1 = NULL;
Mix_Chunk *sfx2 = NULL;

SDL_Event e;
SDL_Color textcolor = { 0, 0, 0, 255 };

//TTF_Font *gFontAure = NULL;
//TTF_Font *gFontAG = NULL;
FC_Font* gFontAure;
FC_Font* gFontAG;



void setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void setRenderColor(SDL_Color c);
SDL_Color setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);


void init_setup();



//3dScenePhysics
/*
q3Scene * scene;
q3BodyDef bodyDef;
q3Body* body;

q3BoxDef boxDef;
q3Transform localSpace;
*/

#endif