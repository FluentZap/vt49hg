#include <SDL.h>
#include <glew.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>
#include <string>
#include <sstream>


using namespace std;

bool init();
bool initGL();
bool loadResources();
void render();
void renderGL();
void close();


SDL_Texture* loadTexture(std::string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gXOut = NULL;
SDL_Texture* gTexture = NULL;
SDL_GLContext gContext;


const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 1920;
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
int angle;


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

int pitch, yaw;
	
int main(int argc, char **argv)
{
	
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
				//renderGL();
				
				glFlush();
				
				SDL_GL_SwapWindow( gWindow );
				
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
	if( e.type == SDL_KEYDOWN)
	{
			angle = angle + 10;
	}
	
	//Quit if escape is detected
	if( e.type == SDL_QUIT )
		quit = true;
}


bool init()
{
	//Init SDL
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); return false;}	
	gWindow = SDL_CreateWindow( "Screen App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if( gWindow == NULL ) {printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); return false;}	

	gContext = SDL_GL_CreateContext( gWindow );
	SDL_GL_SetSwapInterval( 1 );
	initGL();




	return true;
}


bool initGL()
{
    GLenum error = GL_NO_ERROR;

    //Initialize Projection Matrix
    glEnable ( GL_DEPTH_TEST );
	glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

	glClearColor( 0.f, 0.f, 0.f, 1.f );
    
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


void renderGL()
{
	
	 //Clear color buffer
	glClearDepth( 1.0 );
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt( 0, 0, 0, x2, y2, z2, x3, y3, z3)
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	//gluPerspective(50.0, 1.0, 3.0, 7.0); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    //Render quad
	//glBegin( GL_QUADS );
	//	glVertex2f( -0.5f, -0.5f );
	//	glVertex2f( 0.5f, -0.5f );
	//	glVertex2f( 0.5f, 0.5f );
	//	glVertex2f( -0.5f, 0.5f );
	//glEnd();

	glLoadIdentity();
	gluPerspective(1.3f, SCREEN_WIDTH / SCREEN_HEIGHT, 2.0f, 400.0f);
	
	
	//glScalef(1.0, 1.0, 1.0);
	glTranslatef(0, 0, -75);
	glRotatef( angle, 1.0, 0.0, 0.0 );
	glRotatef( angle, 0.0, 1.0, 0.0 );
	//glTranslatef(0.0, 0.0, -1.0);
	angle+=1;

	glBegin(GL_POINTS);
		glColor3f(1.0,0.0,0.1);
		glPointSize(100);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.6f, 0.5f);
		glVertex3f(0.5f, 0.7f, 0.5f);
		glVertex3f(0.5f, 0.8f, 0.5f);
	glEnd();

	
/*
	glBegin(GL_POLYGON);
		glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
		glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
		glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
		glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple
	glEnd();
*/



glBegin(GL_POLYGON);
glColor3f(   1.0,  1.0, 1.0 );
glVertex3f(  0.5, -0.5, 0.5 );
glVertex3f(  0.5,  0.5, 0.5 );
glVertex3f( -0.5,  0.5, 0.5 );
glVertex3f( -0.5, -0.5, 0.5 );
glEnd();
 
// Purple side - RIGHT
glBegin(GL_POLYGON);
glColor3f(  1.0,  0.0,  1.0 );
glVertex3f( 0.5, -0.5, -0.5 );
glVertex3f( 0.5,  0.5, -0.5 );
glVertex3f( 0.5,  0.5,  0.5 );
glVertex3f( 0.5, -0.5,  0.5 );
glEnd();
 
// Green side - LEFT
glBegin(GL_POLYGON);
glColor3f(   0.0,  1.0,  0.0 );
glVertex3f( -0.5, -0.5,  0.5 );
glVertex3f( -0.5,  0.5,  0.5 );
glVertex3f( -0.5,  0.5, -0.5 );
glVertex3f( -0.5, -0.5, -0.5 );
glEnd();
 
// Blue side - TOP
glBegin(GL_POLYGON);
glColor3f(   0.0,  0.0,  1.0 );
glVertex3f(  0.5,  0.5,  0.5 );
glVertex3f(  0.5,  0.5, -0.5 );
glVertex3f( -0.5,  0.5, -0.5 );
glVertex3f( -0.5,  0.5,  0.5 );
glEnd();
 
// Red side - BOTTOM
glBegin(GL_POLYGON);
glColor3f(   1.0,  0.0,  0.0 );
glVertex3f(  0.5, -0.5, -0.5 );
glVertex3f(  0.5, -0.5,  0.5 );
glVertex3f( -0.5, -0.5,  0.5 );
glVertex3f( -0.5, -0.5, -0.5 );
glEnd();

//glEnable(GL_DEPTH_TEST);


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
	
	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}