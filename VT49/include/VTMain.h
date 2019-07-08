#ifndef VTMAIN_H
#define VTMAIN_H

#include <stdio.h>
#include "SWSimulation.h"
#include "VTRender.h"
#include "VTPhysics.h"
#include "VTSerial.h"
#include "VTNetwork.h"
#include "DiceRoller.h"

// #include "SDL.h"
// #include <SDL_FontCache.h>

using namespace std;

typedef unsigned char byte;

// enum OS_Types;

bool init();
void close();

void Serial_Connect();
void Serial_Read();
int Serial_Write(void *data);

void ConsoleSerialSend(byte ConsolePacketSend);

VTRender *_render;
VTPhysics* _physics;
VTSerial *_serial;
SWSimulation *_sws;


void handleUI(SDL_Event);
//void render_text(SDL_Renderer, int, int, const char, TTF_Font, SDL_Color);


SDL_Event e;
SDL_Color textcolor = { 0, 0, 0, 255 };

#endif
