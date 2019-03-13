#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_net.h"
#include "SDL_thread.h"
//#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <serial/serial.h>
#include <string>
#include <tinyxml2.h>
#include <VTMap.h>
//#include <sstream>
#include <SDL_FontCache.h>
#include <thread>

//#include <LinearMath/btVector3.h>
//#include <btTransform.h>
#include <btBulletDynamicsCommon.h>
#include <btCollisionObject.h>
//#include <Bullet3Serialize\Bullet2FileLoader\b3BulletFile.h>
#include <b3BulletFile.h>
//#include <btBulletWorldImporter.h>

#include "VTStart.h"
#include "VTSerialPhraser.h"
#include "SWSimulation.h"
#include "VTNetwork.h"



using namespace std;
using namespace tinyxml2;
using namespace bParse;
//using namespace reactphysics3d;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 1440;
const int SCREEN_FPS = 60;
const float SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
const float SERIAL_TICKS_PER_FRAME = 1000 / 60;


bool quit = false;
int framsPerSec;

size_t fpsTicks;
size_t fpsStart;
size_t serialTicks;
size_t serialStart;
VTNetwork* _net;


//DynamicsWorld* world;
//RigidBody* body;





SDL_Rect rect1, rect2;
double dist1;

serial::Serial* console;
serial::Serial* consolePot;

VTSerialPhraser* parser;

//char incomingData[256] = "";

//Current OS Windows Or Linux
enum OS_Types {WIN, LINUX};
OS_Types CurrentOS;
string buff;

SDL_Rect Scroll;
double Zoom = 1;

int count;
bool lit = false;
int speed=0;


const char* pName;
VTMap * StarMap;


SWSimulation SWS;


void init_setup()
{
	#ifdef _WIN32 || _WIN64
    CurrentOS = WIN;
	#endif
	#ifdef __linux__
    CurrentOS = LINUX;
	#endif
	loadResources();
	
	//rp3d::Vector3 gravity(0.0, -9.81, 0.0);
	//Vector3 gravity(0.0, 0.0, 0.0);
	
	//world = new DynamicsWorld(gravity);
		
	//Vector3 initPosition(0.0, 3.0, 0.0);
	//Quaternion initOrientation = Quaternion::identity();
	//Transform transform(initPosition, initOrientation);
	//body = world->createRigidBody(transform);
	
	//body->setType(BodyType::DYNAMIC);
	
	//Serial Connection
	parser = new VTSerialPhraser();
	Serial_Connect();
}


void Serial_Connect()
{
	
	
	//serial::Serial console("/dev/ttyACM0", 9600, serial::Timeout::simpleTimeout(1000));	
	//try
	//{
		if (CurrentOS == LINUX) console = new serial::Serial("/dev/ttyACM0", 28800 , serial::Timeout::simpleTimeout(10));
		if (CurrentOS == WIN) console = new serial::Serial("COM4", 28800 , serial::Timeout::simpleTimeout(10));
		if (CurrentOS == WIN) consolePot = new serial::Serial("COM5", 28800 , serial::Timeout::simpleTimeout(10));
		
		//console->setTimeout(10, 10, 10, 10, 10);
	//}
	//catch(serial::IOException)
	//{
		
	//}
	
}

void Serial_Read()
{
	parser->ConsoleUpdate(console);
	
	parser->ConsolePotUpdate(consolePot);
	/*
	if (console->isOpen())
	{
		if (console->available() > 0 && console->available() >= 12)
		{
			//phraser->DataBuffer = {};
			console->readline(buff, 100, "VT");
			console->read(phraser->DataBuffer, 12);
			phraser->ReadDataStream();
			
			//buff = "";
			
			//uint8_t holdb[12];
			//if (console->read(holdb, 13) == 13)
				//memcpy(tempb, holdb, 13);
		}

	}
	*/
}

uint8_t ConsolePacketSend = 0;


void Serial_Write()
{
	if (serialTicks + SERIAL_TICKS_PER_FRAME < SDL_GetTicks())
	{
		ConsoleSerialSend();
		serialTicks = SDL_GetTicks();
	}
}





	void ConsoleSerialSend()
	{
		ConsolePacketSend = 1;
		
		bool change = false;
		//console->flushOutput();
		uint8_t Buffer[16] = {0};
		Buffer[0] = ConsolePacketSend;
		
		if (ConsolePacketSend == 1)
		{
			if (parser->ConsoleDataSend.ContolButtons[0]) Buffer[1] |= 0x1 << 0;
			if (parser->ConsoleDataSend.ContolButtons[1]) Buffer[1] |= 0x1 << 1;
			if (parser->ConsoleDataSend.ContolButtons[2]) Buffer[1] |= 0x1 << 2;
			if (parser->ConsoleDataSend.ContolButtons[3]) Buffer[1] |= 0x1 << 3;
			if (parser->ConsoleDataSend.FlightStick) Buffer[1] |= 0x1 << 4;
						
			
			for (int x=0; x < 50; x++)
			{
				if (parser->ConsoleDataSend.BLED[x])
				{
					Buffer[2 + (x / 8)] |= 0x1 << (x % 8);
				}
			}
			Buffer[9] = parser->ConsoleDataSend.OnColor.r;
			Buffer[10] = parser->ConsoleDataSend.OnColor.g;
			Buffer[11] = parser->ConsoleDataSend.OnColor.b;
			
			Buffer[12] = parser->ConsoleDataSend.OffColor.r;
			Buffer[13] = parser->ConsoleDataSend.OffColor.g;
			Buffer[14] = parser->ConsoleDataSend.OffColor.b;
			Buffer[15] = parser->ConsolePotValue[1];
		}

		change = true;
		
		if (ConsolePacketSend > 99)
		{
			int num = (ConsolePacketSend - 100) * 5;
			for (int x = 0; x < 5; x++)
			{
				
				if (parser->ConsoleDataSend.LED[num].r != parser->LastConsoleDataSend.LED[num].r) change = true;
				if (parser->ConsoleDataSend.LED[num].g != parser->LastConsoleDataSend.LED[num].g) change = true;
				if (parser->ConsoleDataSend.LED[num].b != parser->LastConsoleDataSend.LED[num].b) change = true;
				
				Buffer[(x*3) + 1] = parser->ConsoleDataSend.LED[num].r;
				Buffer[(x*3) + 2] = parser->ConsoleDataSend.LED[num].g;
				Buffer[(x*3) + 3] = parser->ConsoleDataSend.LED[num].b;
				num++;
			}
		}
		
		//if (change)
		//{
		//parser->ConsoleSend(console, Buffer, 16);

		parser->ConsoleSend(console, Buffer, 16);
		
		//memcpy(parser->LastConsoleDataSend.LED, parser->ConsoleDataSend.LED, 50);
	}
	
		





void handleUI(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_1)
		{
			//Mix_PlayChannel( 2, sfx1, 0 );
			//Mix_SetPanning(2, 120, 0);
			//pName = planetMap->FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "Placemark" )->FirstChildElement( "name" )->GetText();			
			//parser->ConsoleDataSend.LED[count].r = 0;
			//parser->ConsoleDataSend.LED[count].g = 0;
			//parser->ConsoleDataSend.LED[count].b = 255;
			
			//count++;
			
			parser->ConsoleDataSend.OnColor.g++;
			
		}
		if (e.key.keysym.sym == SDLK_2)
		{
			//Mix_PlayChannel( 1, sfx2, 0 );
			//Mix_SetPanning(1, 0, 120);
			
			parser->ConsoleDataSend.LED[count].r = 255;
			parser->ConsoleDataSend.LED[count].g = 0;
			parser->ConsoleDataSend.LED[count].b = 0;
			count--;
		}			
		
		
		if (e.key.keysym.sym == SDLK_LEFT)
		{
			//Vector3 force(-10000.0, 0.0, 0.0); 
			//body->applyForceToCenterOfMass(force);
			/*
			q3Vec3 point = {1.0, 1.0, 1.0};
			q3Vec3 force = {1.0, 1.0, 1.0};
			
			point.x = 1.0;
			body->ApplyForceAtWorldPoint(force, point);
			body->ApplyLinearImpulse(point);
			 */
			//rect1.x--;
			Scroll.x = Scroll.x + 10 * Zoom;			
		}
		
		if (e.key.keysym.sym == SDLK_RIGHT)
		{
			//Vector3 force(10000.0, 0.0, 0.0); 
			//body->applyForceToCenterOfMass(force);
				//rect1.x++;
			Scroll.x = Scroll.x - 10 * Zoom;
		}
		
		if (e.key.keysym.sym == SDLK_UP)
		{
			//Vector3 force(0.0, -10000.0, 0.0); 
			//body->applyForceToCenterOfMass(force);
				//rect1.x++;
			Scroll.y = Scroll.y + 10 * Zoom;
		}
		
		if (e.key.keysym.sym == SDLK_DOWN)
		{
			//Vector3 force(0.0, 10000.0, 0.0); 
			//body->applyForceToCenterOfMass(force);
				//rect1.x++;
			Scroll.y = Scroll.y - 10 * Zoom;
		}
		
		
		if (e.key.keysym.sym == SDLK_KP_PLUS)
		{
			Zoom = Zoom + 0.1;
			if (Zoom > 10) Zoom = 10;			
		}
		
		if (e.key.keysym.sym == SDLK_KP_MINUS)
		{
			Zoom = Zoom - 0.1;
			if (Zoom < 0.01) Zoom = 0.01;
		}
		
	}

	if (e.type == SDL_KEYUP)
	{
		if (e.key.keysym.sym == SDLK_2)
		{
			lit = false;
		}
		
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
	
	setRenderColor(80, 130, 240, 255);  //Blue (50, 160, 240, 255);
										//Orange (220, 140, 40, 255);
										
	FC_Draw(gFontAG, gRenderer, 0, 0, to_string(framsPerSec).c_str());
	
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
	
	if (StarMap->StarMap.find(count) != StarMap->StarMap.end())
	{
		if (StarMap->StarMap.find(count)->second->Name != nullptr)
		{
			FC_Draw(gFontAG, gRenderer, 100, 100, StarMap->StarMap.find(count)->second->Name);
		}
	}
	
	FC_Draw(gFontAG, gRenderer, 100, 100, to_string(parser->ConsolePotValue[0]).c_str());
	FC_Draw(gFontAG, gRenderer, 100, 120, to_string(parser->ConsolePotValue[1]).c_str());
	FC_Draw(gFontAG, gRenderer, 100, 140, to_string(parser->ConsolePotValue[2]).c_str());
	FC_Draw(gFontAG, gRenderer, 100, 160, to_string(parser->ConsolePotValue[3]).c_str());
	
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
	
	if (phraser->ConsoleButtons.LTog[0]) render_text(gRenderer, 0, 200, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[1]) render_text(gRenderer, 20, 200, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[2]) render_text(gRenderer, 40, 200, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[3]) render_text(gRenderer, 60, 200, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[4]) render_text(gRenderer, 0, 220, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[5]) render_text(gRenderer, 20, 220, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[6]) render_text(gRenderer, 40, 220, "0", gFontAG, &color);
	if (phraser->ConsoleButtons.LTog[7]) render_text(gRenderer, 60, 220, "0", gFontAG, &color);
	
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
	
	rect = {Scroll.x, Scroll.y, 850 * Zoom, 1250 * Zoom};
	SDL_SetTextureColorMod(gTexture, 255, 0, 0); 
	SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
	
	rect = {int(SWS.Ship->x) - 5, int(SWS.Ship->y) - 5, 10, 10};
	SDL_RenderDrawRect(gRenderer, &rect);
	
	rect = {50, 50, 100, 100};
	SDL_RenderDrawRect(gRenderer, &rect);
	rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	SDL_RenderCopy(gRenderer, UITexture, NULL, &rect);
	
	
	
	//SDL_Point * UIPoints = new SDL_Point[30];
	//SDL_Point p = {50, 50};
	
	//UIPoints[0] = SDL_Point{0, 0};
	
	//SDL_RenderDrawLines(gRenderer,  UIPoints, 7);
	
	dist1 += 0.000001;
	if (dist1 > 10000) dist1 = -10000;
	
	
	//q3Vec3 vec;
	//body->GetWorldVector(vec);
	//body->enableGravity(false);
	//Transform transform = body->getTransform();
	//Vector3 vec = transform.getPosition();
	//render_text(gRenderer, vec.x + SCREEN_WIDTH / 2, vec.y + SCREEN_HEIGHT / 2, "0", gFontAG, &color);
	
		
	SDL_RenderPresent(gRenderer);
}




void renderGalaxyMap(int renderX, int renderY)
{
	SDL_SetRenderDrawColor(gRenderer, 10, 10, 10, 255);
	SDL_RenderClear(gRenderer);
	
	setRenderColor(80, 130, 240, 255);	//Blue (50, 160, 240, 255);
										//Orange (220, 140, 40, 255);
	SDL_Color color = setColor(80, 130, 240, 255);
	color = setColor(220, 140, 40, 255);
	
	FC_Draw(gFontAG, gRenderer, 0, 0, to_string(framsPerSec).c_str());
	//render_text(gRenderer, 900, 0, to_string(framsPerSec).c_str(), gFontAG, &color);
	color = setColor(130, 60, 60, 255);
	
	for (pair<int, StarMapData_Type*> e : StarMap->StarMap)
	{
		//if (e.second->Grid)
		//if (strcmp(e.second->Grid, "L9") == 0)
		//{	
			double x, y;
			y = -e.second->y;
			x = e.second->x;
			x = x * Zoom + Scroll.x;
			y = y * Zoom + Scroll.y;
			
			if (x > 0 && y > 0 && x < 1920 && y < 1080)
			{
				SDL_Rect rect = {x, y, 10, 20};
				SDL_RenderDrawRect(gRenderer, &rect);				
				FC_Draw(gFontAG, gRenderer, x, y + 10, e.second->Name);			
			}
		//}	
		
	}
	
		
	SDL_RenderPresent(gRenderer);
}

bool init()
{
	//Init SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) { printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); return false; }
	

	gWindow = SDL_CreateWindow("Screen App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);
	if (gWindow == NULL) { printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); return false; }


	SDL_Rect DispayBounds;
	SDL_GetDisplayBounds(0, &DispayBounds);
	//SDL_SetWindowPosition( gWindow, DispayBounds.x + ( DispayBounds.w - 900 ) / 2, DispayBounds.y + ( DispayBounds.h - 1440 ) / 2 );

	SDL_SetWindowPosition( gWindow, DispayBounds.x + ( DispayBounds.w - 900 ) / 2, DispayBounds.y);

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) { printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError()); return false; }

	TTF_Init();

	gScreenSurface = SDL_GetWindowSurface(gWindow);
	
	//if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() ); return false;}	
	
	//Setup Network
	_net = new VTNetwork();
	_net->init_Network();
	//SDLNet_Init();
	
	//Diable Cursor
	SDL_ShowCursor(SDL_DISABLE);
	return true;
}

bool loadResources()
{
	bool success = true;
	//Load Fonts
	//gFontAure = TTF_OpenFont("Aurebesh.ttf", 22);
	//gFontAG = TTF_OpenFont("AG-Stencil.ttf", 22);
	gFontAure = FC_CreateFont();
	gFontAG = FC_CreateFont();
	
	FC_LoadFont(gFontAure, gRenderer, "Aurebesh.ttf", 22, FC_MakeColor(220, 140, 40, 255), TTF_STYLE_NORMAL);
	FC_LoadFont(gFontAG, gRenderer, "AG-Stencil.ttf", 22, FC_MakeColor(80, 130, 240, 255), TTF_STYLE_NORMAL);
	
	
	//Load Images
	//gXOut = imageLoader("x.png");
	gTexture = loadTexture("VT49.png");
	UITexture = loadTexture("UI.png");
	//gTexture = loadTexture("elf.png");
	//gTexture = loadTexture("elf.jpg");
	//if( gTexture == NULL ) {printf( "Unable to load image %s! SDL Error: %s\n", "x.png", SDL_GetError() ); success = false;}
	
	//Load Music/SFX
	//gMusic = Mix_LoadMUS( "BEEP.mp3" );
	sfx1 = Mix_LoadWAV( "BEEP.wav" );
	sfx2 = Mix_LoadWAV( "WELD2.wav" );
	
	
	
	//planetMap = new XMLDocument();
	//Load Map Files
	
	//planetMap->LoadFile("planets.kml");
	
	//XMLHandle * pRoot 
	//XMLNode * pRoot = planetMap.FirstChild();
	//if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
	
	//XMLElement * pElement = pRoot.FirstChildElement("planets");
	//const char* pName = planetMap.FirstChildElement( "Folder" )->FirstChildElement( "name" )->GetText();
	
	
	//XMLElement * pElement = planetMap.FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "Placemark" )->FirstChildElement( "name" )->GetText();
	//const char * name = planetMap.FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "name" )->GetText();
	
	//XMLText* textNode = planetMap->FirstChildElement( "kml" )->FirstChildElement( "Document" )->FirstChildElement( "Folder" )->FirstChildElement( "name" )->FirstChild()->ToText();	
	//pName = textNode->Value();
	StarMap = new VTMap();
	
	StarMap->LoadMapFile("planets.kml");
	
	
	//StarMap.StarMap.insert()
	
	//if (name)
		//strcpy(pName, name);
	//else
		//pName = "goose";
	
	
	//if (pElement) 
//		pName = "dood";
//	else
		//pName = "pood";
			
	//->FirstChildElement( "Placemark" )
	
	
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
	//net = NULL;

	Mix_FreeChunk(sfx1);
	Mix_FreeChunk(sfx2);
	sfx1 = NULL;
	sfx2 = NULL;
	gMusic = NULL;
	FC_FreeFont(gFontAure);
	FC_FreeFont(gFontAG);

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
		init_setup();
				
		int fps;
		
		fpsTicks = SDL_GetTicks();
		//While application is running
		
		//std::thread serialThread(Serial_Write);
		//SDL_Thread *serialThread = SDL_CreateThread(Serial_Write, "Serial_Write", (void *)NULL);
		
		
		
		
		btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
		btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
		btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
		btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
		btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
		dynamicsWorld->setGravity(btVector3(0, 0, 0));
		btAlignedObjectArray<btCollisionShape*> collisionShapes;
		
		{
			btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));

			collisionShapes.push_back(groundShape);
			
			btTransform groundTransform;
			groundTransform.setIdentity();
			groundTransform.setOrigin(btVector3(100, 100, 0));

			btScalar mass(0.);

			//rigidbody is dynamic if and only if mass is non zero, otherwise static
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				groundShape->calculateLocalInertia(mass, localInertia);

			//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
			btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
			
			btRigidBody* body = new btRigidBody(rbInfo);

			//add the body to the dynamics world
			dynamicsWorld->addRigidBody(body);
						
		}
		
		{
			//create a dynamic rigidbody

			btCollisionShape* colShape = new btBoxShape(btVector3(5, 5, 5));
			//btCollisionShape* colShape = new btSphereShape(btScalar(5.));
			collisionShapes.push_back(colShape);

			/// Create Dynamic Objects
			btTransform startTransform;
			startTransform.setIdentity();

			btScalar mass(1.f);

			//rigidbody is dynamic if and only if mass is non zero, otherwise static
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				colShape->calculateLocalInertia(mass, localInertia);

			startTransform.setOrigin(btVector3(0, 0, 0));

			//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
			btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
			btRigidBody* body = new btRigidBody(rbInfo);

			dynamicsWorld->addRigidBody(body);
			
			btHingeConstraint* hinge = new btHingeConstraint(*body, btVector3(1, 0, 0), btVector3(1, 0, 0), true);
			hinge->setAngularOnly(true);
			dynamicsWorld->addConstraint(hinge);
			
		}
				
				//b3BulletFile* fileloader = new b3BulletFile("VT49.bullet");
				//fileloader->parseData();
				//fileloader.m_rigidBodies[0];
				//fileloader.m_collisionObjects[]
				//btcol
				
				//btBulletWorldImporter* fileloader = new btBulletWorldImporter(dynamicsWorld);
				//fileloader->loadFile("VT49.bullet");
				

				//print positions of all objects
				btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[1];
				btRigidBody* body = btRigidBody::upcast(obj);
				btTransform trans;
				
				
				
				if (body && body->getMotionState())
				{
					body->getMotionState()->getWorldTransform(trans);
				}
				else
				{
					trans = obj->getWorldTransform();
				}
				printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
								

		while (!quit)
		{
			//startTicks = SDL_GetTicks();
						
			
			while (SDL_PollEvent(&e) != 0) { handleUI(e); }
			//scene->Step();
			//world->update( 1.0 / 60.0 );
			
			Serial_Read();
			
			//if (serialTicks + SERIAL_TICKS_PER_FRAME < SDL_GetTicks())
			//{
				
				Serial_Write();
			//	serialTicks = SDL_GetTicks();
			//}
			
			
						
			
				if (fpsTicks + SCREEN_TICKS_PER_FRAME < SDL_GetTicks())
				{
					dynamicsWorld->stepSimulation(1.f / 60.f, 10);
					body->setActivationState(DISABLE_DEACTIVATION);
					body->activate(true);
					
					_net->update_Network(SWS);
					//fpsTicks = SDL_GetTicks();
				
					
				
				//parser->ConsolePressed.insert((int)Typeof_ConsoleInputs::FlightStickUP);
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickUP)) Scroll.y = Scroll.y + 5 * Zoom;
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickDOWN)) Scroll.y = Scroll.y - 5 * Zoom;
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickLEFT)) Scroll.x = Scroll.x + 5 * Zoom;
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickRIGHT)) Scroll.x = Scroll.x - 5 * Zoom;
								
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickUP)) body->applyCentralImpulse(btVector3(0, 0.1, 0));
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickDOWN)) body->applyCentralImpulse(btVector3(0, -0.1, 0));
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickLEFT)) body->applyCentralImpulse(btVector3(0.1, 0, 0));
				if (parser->InputDown(Typeof_ConsoleInputs::FlightStickRIGHT)) body->applyCentralImpulse(btVector3(-0.1, 0, 0));
					
				SWS.Ship->UpdateConsole(parser);
				
				body->getMotionState()->getWorldTransform(trans);
				SWS.Ship->x = float(trans.getOrigin().getX());
				SWS.Ship->y = float(trans.getOrigin().getY());
				SWS.Ship->z = float(trans.getOrigin().getZ());
				
				//printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
				
				//printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));
				
				render();
				//renderGalaxyMap(0, 0);
				fps++;
				fpsTicks = SDL_GetTicks();
				
			}
			
			
			if (fpsStart + 1000 < SDL_GetTicks())
			{
				framsPerSec = fps;
				fps = 0;
				fpsStart = SDL_GetTicks();
			}
			
			
			//int frameTicks = SDL_GetTicks() - startTicks;
			//if (frameTicks < SCREEN_TICKS_PER_FRAME)
			//{
				//SDL_Delay(10);
			//}
		}
		//serialThread.join();
			
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


SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
		return NULL;
	
	newTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
	if (newTexture == NULL) {printf( "Unable to load image %s! SDL Error: %s\n", path.c_str() , SDL_GetError() ); SDL_FreeSurface(surface); return NULL;}
	
	SDL_FreeSurface(surface);
	
	return newTexture;
}