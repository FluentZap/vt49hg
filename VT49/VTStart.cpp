#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_net.h"
#include <stdio.h>
#include <string>
#include <sstream>
//#include "q3.h"
#include "reactphysics3d.h"
#include "VTStart.h"


using namespace std;
using namespace reactphysics3d;


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


bool quit = false;
int framsPerSec;

rp3d::DynamicsWorld* world;
rp3d::RigidBody* body;


SDL_Rect rect1, rect2;
double dist1;

void init_setup()
{
	loadResources();
	
	//rp3d::Vector3 gravity(0.0, -9.81, 0.0);
	rp3d::Vector3 gravity(-10.0, 0.0, 0.0);
	
	world = new DynamicsWorld(gravity);
		
	rp3d::Vector3 initPosition(0.0, 3.0, 0.0);
	rp3d::Quaternion initOrientation = rp3d::Quaternion::identity();
	rp3d::Transform transform(initPosition, initOrientation);
	body = world->createRigidBody(transform);
	
	body->setType(rp3d::BodyType::DYNAMIC);
	
	// Force vector (in Newton) 

	// Apply a force to the center of the body 
	//body->applyForceToCenter(force);
	//Vector3 force(10.0, 10.0, 10.0); 
	//body->applyForceToCenterOfMass(force);
/*
	scene = new q3Scene( 1.0 / 60.0 );
	//q3Scene scene( 1.0 / 60.0 );
	q3BodyDef bodyDef;
	bodyDef.position.Set( 0.0f, 3.0f, 0.0f);
		
	bodyDef.axis.Set( q3RandomFloat( -1.0f, 1.0f ), q3RandomFloat( -1.0f, 1.0f ), q3RandomFloat( -1.0f, 1.0f ) );
	bodyDef.angle = q3PI * q3RandomFloat( -1.0f, 1.0f );
	bodyDef.bodyType = eDynamicBody;
	bodyDef.angularVelocity.Set( q3RandomFloat( 1.0f, 3.0f ), q3RandomFloat( 1.0f, 3.0f ), q3RandomFloat( 1.0f, 3.0f ) );
	bodyDef.angularVelocity *= q3Sign( q3RandomFloat( -1.0f, 1.0f ) );
	bodyDef.linearVelocity.Set( q3RandomFloat( 1.0f, 3.0f ), q3RandomFloat( 1.0f, 3.0f ), q3RandomFloat( 1.0f, 3.0f ) );
	bodyDef.linearVelocity *= q3Sign( q3RandomFloat( -1.0f, 1.0f ) );

	body = scene->CreateBody( bodyDef );
	

	q3BoxDef boxDef; // See q3Box.h for settings details
	q3Transform localSpace; // Contains position and orientation, see q3Transform.h for details
	q3Identity( localSpace ); // Specify the origin, and identity orientation
	
	// Create a box at the origin with width, height, depth = (1.0, 1.0, 1.0)
	// and add it to a rigid body. The transform is defined relative to the owning body
	
	boxDef.Set( localSpace, q3Vec3( 1.0, 1.0, 1.0 ) );
	
	body->AddBox( boxDef );
	
	/*
	q3BoxDef boxDef; // See q3Box.h for settings details
	q3Transform localSpace; // Contains position and orientation, see q3Transform.h for details
	q3Identity( localSpace ); // Specify the origin, and identity orientation
	
	// Create a box at the origin with width, height, depth = (1.0, 1.0, 1.0)
	// and add it to a rigid body. The transform is defined relative to the owning body
	boxDef.Set( localSpace, q3Vec3( 1.0, 1.0, 1.0 ) );
	body->AddBox( boxDef );
	*/
}

void main_loop()
{
	while (SDL_PollEvent(&e) != 0) { handleUI(e); }
	//scene->Step();
	world->update( 1.0 / 60.0 );
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
			Vector3 force(-10000.0, 0.0, 0.0); 
			
			body->applyForceToCenterOfMass(force);
			/*
			q3Vec3 point = {1.0, 1.0, 1.0};
			q3Vec3 force = {1.0, 1.0, 1.0};
			
			point.x = 1.0;
			body->ApplyForceAtWorldPoint(force, point);
			body->ApplyLinearImpulse(point);
			 */
			//rect1.x--;
		}
		
		if (e.key.keysym.sym == SDLK_RIGHT)
		{
			Vector3 force(10000.0, 0.0, 0.0); 
			body->applyForceToCenterOfMass(force);
				//rect1.x++;
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
	SDL_Color color = setColor(255, 255, 255, 255);
	/*
	SDL_Rect rect = {100, 100, 200, 200};
	SDL_RenderDrawRect(gRenderer, &rect);
	
	SDL_RenderDrawRect(gRenderer, &rect1);
	
	
	render_text(gRenderer, 0, 0, "VT-49 OS TEST BUILD 0.0.1", gFontAure, &color);
	render_text(gRenderer, 80, 30, "VT-49 OS TEST BUILD 0.0.1", gFontAG, &color);
	render_text(gRenderer, 900, 0, to_string(framsPerSec).c_str(), gFontAG, &color);
	color = setColor(130, 60, 60, 255);
	render_text(gRenderer, 600, 600, to_string(dist1).c_str(), gFontAG, &color);
	dist1 += 0.000001;
	if (dist1 > 10000) dist1 = -10000;
	 */
	//q3Vec3 vec;
	//body->GetWorldVector(vec);
	//body->enableGravity(false);
	Transform transform = body->getTransform();
	Vector3 vec = transform.getPosition();
	render_text(gRenderer, vec.x + SCREEN_WIDTH / 2, vec.y + SCREEN_HEIGHT / 2, "0", gFontAG, &color);
	
	
	
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
		
		init_setup();

		//loadResources();
		
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