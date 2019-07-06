#ifndef VTSTART
#define VTSTART

#include "VTRender.h"
#include "VTPhysics.h"
// #include "SDL.h"
// #include <SDL_FontCache.h>

using namespace std;

typedef unsigned char byte;

bool init();
void close();

void Serial_Connect();
void Serial_Read();
int Serial_Write(void *data);

void ConsoleSerialSend(byte ConsolePacketSend);

VTRender* _render;
VTPhysics* _physics;

void handleUI(SDL_Event);
//void render_text(SDL_Renderer, int, int, const char, TTF_Font, SDL_Color);




SDL_Event e;
SDL_Color textcolor = { 0, 0, 0, 255 };

//TTF_Font *gFontAure = NULL;
//TTF_Font *gFontAG = NULL;

void init_setup();


#endif
