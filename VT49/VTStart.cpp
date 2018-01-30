#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <wiringPi.h>
#include <string>
#include <sstream>
#include <ws2811.h>

using namespace std;

bool init();
bool loadResources();
void render();
void close();
bool init_ws();


SDL_Texture* loadTexture(std::string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gXOut = NULL;
SDL_Texture* gTexture = NULL;


const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

void handleUI(SDL_Event);
void render_text(SDL_Renderer, int, int, const char, TTF_Font, SDL_Rect, SDL_Color);
SDL_Color setColor (Uint8 r, Uint8 g, Uint8 b, Uint8 a);

Mix_Music *gMusic = NULL;


//SDL Render Window

bool quit = false;
SDL_Event e;
SDL_Color textcolor = {0, 0, 0, 255};

TTF_Font *gFont = NULL;


ws2811_t ledstring = {};
/*
ws2811_t ledstring =
{
    0,
    0,
    800,
    10,
	
    12, 0, 50, 255, WS2811_STRIP_GBR,
    0

};
*/


//SDL_Point Points[400];


struct StarMap {
public:
	SDL_Point Points[400];
	SDL_Point* getPoints()
		{

		SDL_Point mPoints[400];

		for (int x=0; x < 400; x++)
		{
			mPoints[x].x = Points[x].x;
			mPoints[x].y = Points[x].y;
			mPoints[x].x = rand() % 1000;
			mPoints[x].y = rand() % 1000;
		}
		return mPoints;
	}

};


StarMap starmap;

int main(int argc, char **argv)
{

if (wiringPiSetup () == -1)
	return 1 ;
	
init_ws();
	
	if( init() )
	{

			Uint32 startTicks;
			Uint32 fpsTicks;
			int fps;
			fpsTicks = SDL_GetTicks();
			//While application is running


			for (int x = 0; x < 400; x++)
			{
				starmap.Points[x].x = rand() % 1000;
				starmap.Points[x].y = rand() % 1000;
			}
			
			while( !quit )
			{
				startTicks = SDL_GetTicks();
		
				while( SDL_PollEvent( &e ) != 0 )
				{
					handleUI(e);
				}
					
					
				render();
				fps++;
				
				if (SDL_GetTicks() >= fpsTicks + 1000)
					{
						//printf("%d\n", fps);
						fps = 0;
						fpsTicks = SDL_GetTicks();
					}
				int frameTicks = SDL_GetTicks() - startTicks;
				if( frameTicks < SCREEN_TICKS_PER_FRAME)
				{
					SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
				}
		}
		
	} else printf( "Failed to initialize!\n" );
	
	return 0;
}



void render_text(
    SDL_Renderer *renderer,
    int x,
    int y,
    const char *text,
    TTF_Font *font,
    SDL_Rect rect,
    SDL_Color *color
) {
    SDL_Surface *surface;
    SDL_Texture *texture;
	
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

void handleUI(SDL_Event e)
{
	
	if (e.type == SDL_MOUSEMOTION)
	{
	}
	
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
	}
//Blue Red Green
	if( e.type == SDL_KEYDOWN)
	{
		if( e.key.keysym.sym == SDLK_1 )
			{
				//pinMode (0, OUTPUT);
				//digitalWrite (0, 1);
				for(int x = 0; x < 50; x++){
					ledstring.channel[0].leds[x] = 0x00000080;
				}
				
				ws2811_render(&ledstring);
			}
			if( e.key.keysym.sym == SDLK_2 )
			{
				//pinMode (0, OUTPUT);
				//digitalWrite (0, 1);
				for(int x = 25; x < 50; x++){
					ledstring.channel[0].leds[x] = 0x00ff0000;
				}
				
				ws2811_render(&ledstring);
			}
			if( e.key.keysym.sym == SDLK_3 )
			{
				//pinMode (0, OUTPUT);
				//digitalWrite (0, 1);
				for(int x = 0; x < 50; x++){
					ledstring.channel[0].leds[x] = 0x0000ff00;
				}
				
				ws2811_render(&ledstring);
			}
	}

	if( e.type == SDL_KEYUP)
	{

		if( e.key.keysym.sym == SDLK_1 )
			{
				//pinMode (0, OUTPUT);
				//digitalWrite (0, 0);
				for(int x = 0; x < 50; x++){
					ledstring.channel[0].leds[x] = 0x00000000;
				}
				ws2811_render(&ledstring);
			}
	}



	
	if( e.type == SDL_KEYDOWN ) if( e.key.keysym.sym == SDLK_ESCAPE ) quit = true;
	
	//Quit if escape is detected
	if( e.type == SDL_QUIT )
		quit = true;
}


bool init()
{
	//Init SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); return false;}	

	gWindow = SDL_CreateWindow( "Screen App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);
	if( gWindow == NULL ) {printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); return false;}		
	
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if( gRenderer == NULL ) {printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() ); return false;}

	gScreenSurface = SDL_GetWindowSurface( gWindow );

	//SDL_GL_SetSwapInterval( 1 );
	
	return true;
}


bool init_ws()
{
	
	ws2811_return_t ret;
	
	ledstring.freq = WS2811_TARGET_FREQ;
	ledstring.dmanum = 10;
	
	ledstring.channel[0].gpionum = 12;
	ledstring.channel[0].count = 50;
	ledstring.channel[0].invert = 0;
	ledstring.channel[0].brightness = 255;
	ledstring.channel[0].strip_type = WS2811_STRIP_GBR;
	/*
	ledstring.channel[1].gpionum = 0;
	ledstring.channel[1].count = 0;
	ledstring.channel[1].invert = 0;
	ledstring.channel[1].brightness = 0;
	*/
	ws2811_init(&ledstring);
	
	return true;
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

SDL_Color setColor (Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color color;
	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}


void render()
{
	SDL_SetRenderDrawColor(gRenderer, 40, 40, 40, 255);
	SDL_RenderClear(gRenderer);
	SDL_RenderPresent(gRenderer);
}


void close()
{
	//Deallocate surface
    SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	
	gWindow = NULL;
	gRenderer = NULL;
	
	Mix_FreeMusic( gMusic );
    gMusic = NULL;
	
	//Quit Ws2811
	ws2811_fini(&ledstring);
	
	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	
}
