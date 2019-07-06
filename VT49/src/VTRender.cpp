#include "VTRender.h"

VTRender::VTRender(SWSimulation* SWS)
{
    VTRender::SWS = SWS;
}

VTRender::~VTRender()
{
}

bool VTRender::Init(int SCREEN_WIDTH, int SCREEN_HEIGHT, int DISPLAY)
{
    VTRender::SCREEN_WIDTH = SCREEN_WIDTH;
    VTRender::SCREEN_HEIGHT = SCREEN_HEIGHT;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("VT49", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);
    if (gWindow == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_Rect DispayBounds;
    SDL_GetDisplayBounds(DISPLAY, &DispayBounds);
    //SDL_SetWindowPosition( gWindow, DispayBounds.x + ( DispayBounds.w - 900 ) / 2, DispayBounds.y + ( DispayBounds.h - 1440 ) / 2 );
    SDL_SetWindowPosition(gWindow, DispayBounds.x + (DispayBounds.w - 900) / 2, DispayBounds.y);

    //gRenderer = SDL_CreateRenderer(gWindow, -1, NULL);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);
    TTF_Init();
    SDL_ShowCursor(SDL_DISABLE);

    LoadResources();
    //if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() ); return false;}
}

void VTRender::LoadResources()
{
    //Load Fonts
    //gFontAure = TTF_OpenFont("Aurebesh.ttf", 22);
    //gFontAG = TTF_OpenFont("AG-Stencil.ttf", 22);
    gFontAure = FC_CreateFont();
    gFontAG = FC_CreateFont();

    FC_LoadFont(gFontAure, gRenderer, "Aurebesh.ttf", 22, FC_MakeColor(220, 140, 40, 255), TTF_STYLE_NORMAL);
    FC_LoadFont(gFontAG, gRenderer, "AG-Stencil.ttf", 22, FC_MakeColor(80, 130, 240, 255), TTF_STYLE_NORMAL);

    //Load Images
    //gXOut = imageLoader("x.png");
    gTexture = loadTexture("VT49-2.png");
    UITexture = loadTexture("UI.png");
    //gTexture = loadTexture("elf.png");
    //gTexture = loadTexture("elf.jpg");
    //if( gTexture == NULL ) {printf( "Unable to load image %s! SDL Error: %s\n", "x.png", SDL_GetError() ); success = false;}

    //Load Music/SFX
    //gMusic = Mix_LoadMUS( "BEEP.mp3" );
    sfx1 = Mix_LoadWAV("BEEP.wav");
    sfx2 = Mix_LoadWAV("WELD2.wav");
}

void VTRender::Render()
{
    SDL_SetRenderDrawColor(gRenderer, 10, 10, 10, 255);
    SDL_RenderClear(gRenderer);
    setRenderColor(80, 130, 240, 255); //Blue (50, 160, 240, 255);
                                       //Orange (220, 140, 40, 255);

    FC_Draw(gFontAG, gRenderer, 0, 0, to_string(SWS->FPS).c_str());
    // FC_Draw(gFontAG, gRenderer, 0, 20, to_string(FPS_Adjust).c_str());

    //setRenderColor(255, 255, 255, 255);
    SDL_Color color = setColor(80, 130, 240, 255);
    color = setColor(220, 140, 40, 255);

    //color = setColor(50, 160, 240, 255);

    SDL_Rect rect = {100, 100, 200, 200};
    //SDL_RenderDrawRect(gRenderer, &rect);
    //SDL_RenderDrawRect(gRenderer, &rect1);

    //for (int x = 0; x < count; x++)
    //{
    //pName = planetMap->FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "Placemark" )->NextSiblingElement( "Placemark" )->FirstChildElement( "name" )->GetText();
    //}

    color = setColor(220, 140, 40, 255);
    //render_text(gRenderer, 0, 0, "p", gFontAure, &color);

    color = setColor(50, 160, 240, 255);
    //render_text(gRenderer, 40, 0, "vt-49 os test build 0.0.1", gFontAure, &color);
    //render_text(gRenderer, 80, 30, "VT-49 OS TEST BUILD 0.0.1", gFontAG, &color);
    //render_text(gRenderer, 0, 0, to_string(fpsStart).c_str(), gFontAG, &color);
    //render_text(gRenderer, 0, 60, to_string(SDL_GetTicks()).c_str(), gFontAG, &color);

    //render_text(gRenderer, 900, 0, to_string(framsPerSec).c_str(), gFontAG, &color);
    color = setColor(130, 60, 60, 255);

    // if (StarMap->StarMap.find(count) != StarMap->StarMap.end())
    // {
    //     if (StarMap->StarMap.find(count)->second->Name != nullptr)
    //     {
    //         FC_Draw(gFontAG, gRenderer, 100, 100, StarMap->StarMap.find(count)->second->Name);
    //     }
    // }

    //	FC_Draw(gFontAG, gRenderer, 100, 100, to_string(parser->ConsolePotValue[0]).c_str());
    //	FC_Draw(gFontAG, gRenderer, 100, 120, to_string(parser->ConsolePotValue[1]).c_str());
    //	FC_Draw(gFontAG, gRenderer, 100, 140, to_string(parser->ConsolePotValue[2]).c_str());
    //	FC_Draw(gFontAG, gRenderer, 100, 160, to_string(parser->ConsolePotValue[3]).c_str());

    // FC_Draw(gFontAG, gRenderer, 100, 20, ("Success: " + to_string(greendie.success)).c_str());
    // FC_Draw(gFontAG, gRenderer, 100, 40, ("Advantage: " + to_string(greendie.advantage)).c_str());

    string id = "";
    for (int x = 0; x < 15; x++)
    {
        //		id += to_string(parser->CylinderCode[x]) + ": ";
    }

    // FC_Draw(gFontAG, gRenderer, 100, 60, id.c_str());

    //render_text(gRenderer, 600, 600, to_string(dist1).c_str(), gFontAG, &color);
    /*
	FC_Draw(gFontAG, gRenderer, 100, 0, to_string(count).c_str());
	FC_Draw(gFontAG, gRenderer, 150, 0, to_string(speed).c_str());
	if (parser->ConsoleButtons.LeftBoxTog[0]) FC_Draw(gFontAG, gRenderer, 0, 200, "0");
	if (parser->ConsoleButtons.LeftBoxTog[1]) FC_Draw(gFontAG, gRenderer, 20, 200, "0");
	if (parser->ConsoleButtons.LeftBoxTog[2]) FC_Draw(gFontAG, gRenderer, 40, 200, "0");
	if (parser->ConsoleButtons.LeftBoxTog[3]) FC_Draw(gFontAG, gRenderer, 60, 200, "0");
	if (parser->ConsoleButtons.LeftBoxTog[4]) FC_Draw(gFontAG, gRenderer, 0, 250, "0");
	if (parser->ConsoleButtons.LeftBoxTog[5]) FC_Draw(gFontAG, gRenderer, 20, 250, "0");
	if (parser->ConsoleButtons.LeftBoxTog[6]) FC_Draw(gFontAG, gRenderer, 40, 250, "0");
	if (parser->ConsoleButtons.LeftBoxTog[7]) FC_Draw(gFontAG, gRenderer, 60, 250, "0");
	 */
    /*

		if (parser->ConsoleButtons.LTog[0]) render_text(gRenderer, 0, 200, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[1]) render_text(gRenderer, 20, 200, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[2]) render_text(gRenderer, 40, 200, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[3]) render_text(gRenderer, 60, 200, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[4]) render_text(gRenderer, 0, 220, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[5]) render_text(gRenderer, 20, 220, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[6]) render_text(gRenderer, 40, 220, "0", gFontAG, &color);
		if (parser->ConsoleButtons.LTog[7]) render_text(gRenderer, 60, 220, "0", gFontAG, &color);

		//if (tempb[0] == 1) render_text(gRenderer, 60, 220, "Woopadoop", gFontAG, &color);
		if (tempb[2] & 0b0000'0001) render_text(gRenderer, 00, 220, "1", gFontAG, &color);
		if (tempb[2] & 0b0000'0010) render_text(gRenderer, 20, 220, "2", gFontAG, &color);
		if (tempb[2] & 0b0000'0100) render_text(gRenderer, 40, 220, "3", gFontAG, &color);
		if (tempb[2] & 0b0000'1000) render_text(gRenderer, 60, 220, "4", gFontAG, &color);

		if (tempb[3] & 0b0000'0001) render_text(gRenderer, 00, 260, "1", gFontAG, &color);
		if (tempb[3] & 0b0000'0010) render_text(gRenderer, 20, 260, "2", gFontAG, &color);
		if (tempb[3] & 0b0000'0100) render_text(gRenderer, 40, 260, "3", gFontAG, &color);
		if (tempb[3] & 0b0000'1000) render_text(gRenderer, 60, 260, "4", gFontAG, &color);
		//if (buff.length() > 1) render_text(gRenderer, 00, 220, buff.c_str(), gFontAG, &color);

	*/
    /*
	if (consol->isOpen())
	{
		render_text(gRenderer, 40, 300, "Open", gFontAG, &color);
	}
	else
	{
		render_text(gRenderer, 40, 300, "Closed", gFontAG, &color);
	}
	*/
    int x = 500, y = 500;
    rect = {Scroll.x, Scroll.y, 850 * Zoom, 1250 * Zoom};
    SDL_SetTextureColorMod(gTexture, 0, 0, 255);
    SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);

    // rect = {int(SWS.Ship->x) - 5 + x, int(SWS.Ship->z) - 5 + y, 10, 10};
    SDL_RenderDrawRect(gRenderer, &rect);

    rect = {0 + x, 30 + y, 2, 2};
    SDL_RenderDrawRect(gRenderer, &rect);
    rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, UITexture, NULL, &rect);

    //SDL_Point * UIPoints = new SDL_Point[30];
    //SDL_Point p = {50, 50};

    //UIPoints[0] = SDL_Point{0, 0};

    //SDL_RenderDrawLines(gRenderer,  UIPoints, 7);

    // dist1 += 0.000001;
    // if (dist1 > 10000)
    //     dist1 = -10000;

    //q3Vec3 vec;
    //body->GetWorldVector(vec);
    //body->enableGravity(false);
    //Transform transform = body->getTransform();
    //Vector3 vec = transform.getPosition();
    //render_text(gRenderer, vec.x + SCREEN_WIDTH / 2, vec.y + SCREEN_HEIGHT / 2, "0", gFontAG, &color);

    SDL_RenderPresent(gRenderer);
}

// void renderGalaxyMap(int renderX, int renderY)
// {
//     SDL_SetRenderDrawColor(gRenderer, 10, 10, 10, 255);
//     SDL_RenderClear(gRenderer);

//     setRenderColor(80, 130, 240, 255); //Blue (50, 160, 240, 255);
//     //Orange (220, 140, 40, 255);
//     SDL_Color color = setColor(80, 130, 240, 255);
//     color = setColor(220, 140, 40, 255);

//     // FC_Draw(gFontAG, gRenderer, 0, 0, to_string(framsPerSec).c_str());
//     //render_text(gRenderer, 900, 0, to_string(framsPerSec).c_str(), gFontAG, &color);
//     color = setColor(130, 60, 60, 255);

//     // for (pair<int, StarMapData_Type *> e : StarMap->StarMap)
//     // {
//     //     //if (e.second->Grid)
//     //     //if (strcmp(e.second->Grid, "L9") == 0)
//     //     //{
//     //     double x, y;
//     //     y = -e.second->y;
//     //     x = e.second->x;
//     //     x = x * Zoom + Scroll.x;
//     //     y = y * Zoom + Scroll.y;

//     //     if (x > 0 && y > 0 && x < 1920 && y < 1080)
//     //     {
//     //         SDL_Rect rect = {x, y, 10, 20};
//     //         SDL_RenderDrawRect(gRenderer, &rect);
//     //         FC_Draw(gFontAG, gRenderer, x, y + 10, e.second->Name);
//     //     }
//     //     //}
//     // }

//     SDL_RenderPresent(gRenderer);
// }

void VTRender::setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{    
     if (gRenderer != NULL)
        SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
}

void VTRender::setRenderColor(SDL_Color c)
{
    if (gRenderer != NULL)
        SDL_SetRenderDrawColor(gRenderer, c.r, c.g, c.b, c.a);
}

SDL_Color VTRender::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Color color;
    color.a = a;
    color.r = r;
    color.g = g;
    color.b = b;
    return color;
}

void VTRender::render_text(SDL_Renderer *renderer, int x, int y, const char *text, TTF_Font *font, SDL_Color *color)
{
    if (text)
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
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

SDL_Texture* VTRender::loadTexture(std::string path)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *surface = IMG_Load(path.c_str());
    if (surface == NULL)
        return NULL;

    newTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
    if (newTexture == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }

    SDL_FreeSurface(surface);

    return newTexture;
}
