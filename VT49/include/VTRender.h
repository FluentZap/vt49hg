#ifndef VTRENDER_H
#define VTRENDER_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_net.h"
#include "SDL_thread.h"
#include "SDL_FontCache.h"
#include "SWSimulation.h"
#include <stdio.h>

class VTRender
{
    SDL_Rect Scroll = {0, 0, 0, 0};
    double Zoom = 1;
    SDL_Rect rect1, rect2;
    SDL_Texture *loadTexture(std::string path);
    SDL_Window *gWindow = NULL;
    SDL_Renderer *gRenderer = NULL;
    SDL_Surface *gScreenSurface = NULL;
    SDL_Surface *gXOut = NULL;
    SDL_Texture *gTexture = NULL;
    SDL_Texture *UITexture = NULL;

    FC_Font *gFontAure;
    FC_Font *gFontAG;

    Mix_Music *gMusic = NULL;
    Mix_Chunk *sfx1 = NULL;
    Mix_Chunk *sfx2 = NULL;

    void setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void setRenderColor(SDL_Color c);
    SDL_Color setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void render_text(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Color *color);

public:
    VTRender(SWSimulation *SWS);
    ~VTRender();
    void Render();
    bool Init(int SCREEN_WIDTH, int SCREEN_HEIGHT, int DISPLAY);
    void LoadResources();

private:
    SWSimulation *SWS;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
};
#endif // VTRENDER_H