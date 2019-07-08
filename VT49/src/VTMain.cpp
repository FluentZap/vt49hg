#include "VTMain.h"

#include <unistd.h>
#include <string>
#include <tinyxml2.h>
#include <VTMap.h>
#include <thread>

using namespace std;
using namespace tinyxml2;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 1440;
const int SCREEN_FPS = 60;
const double SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
//const float SCREEN_TICKS_PER_FRAME = 0;
const double SERIAL_TICKS_PER_FRAME = 1000 / 60;

int TickTime = 0;

int FPS_Adjust = 0;

bool quit = false;
//int framsPerSec;
//int serialPerSec;

size_t fpsTicks;
size_t fpsStart;

size_t spsTicks;
size_t spsStart;

size_t serialTicks;
size_t serialStart;
VTNetwork *_net;

//DynamicsWorld* world;
//RigidBody* body;

//SDL_Rect rect1, rect2;
double dist1;

//VTSerialParser* parser;

//Current OS Windows Or Linux
enum OS_Types
{
	WIN,
	LINUX
};

OS_Types CurrentOS;
string buff;

SDL_Rect Scroll;
double Zoom = 1;

int count;
bool lit = false;
int speed = 0;

const char *pName;
VTMap *StarMap;
diceResult greendie;

void Serial_Connect()
{

	//serial::Serial console("/dev/ttyACM0", 9600, serial::Timeout::simpleTimeout(1000));
	//try
	//{

	//		if(CurrentOS == LINUX) console = new serial::Serial("/dev/ttyACM0", 28800, serial::Timeout::simpleTimeout(10));
	//	if(CurrentOS == WIN) console = new serial::Serial("COM4", 28800, serial::Timeout::simpleTimeout(10));
	//	if(CurrentOS == WIN) consolePot = new serial::Serial("COM6", 28800, serial::Timeout::simpleTimeout(10));

	//	if(CurrentOS == WIN) RS232_OpenComport(3, 28800, "8N1", 1)
	//	if(CurrentOS == WIN) RS232_OpenComport(5, 28800, "8N1", 1)

	//console->setTimeout(10, 10, 10, 10, 10);
	//}
	//catch(serial::IOException)
	//{

	//}
}

void Serial_Read()
{
	//	parser->ConsoleUpdate(console);
	//	parser->ConsolePotUpdate(consolePot);
	/*
	if (console->isOpen())
	{
		if (console->available() > 0 && console->available() >= 12)
		{
			//parser->DataBuffer = {};
			console->readline(buff, 100, "VT");
			console->read(parser->DataBuffer, 12);
			parser->ReadDataStream();

			//buff = "";

			//uint8_t holdb[12];
			//if (console->read(holdb, 13) == 13)
				//memcpy(tempb, holdb, 13);
		}

	}
	*/
}

//uint8_t ConsolePacketSend = 0;

int Serial_Write()
{
	//while (!quit)
	//{
	if (serialTicks + SERIAL_TICKS_PER_FRAME < SDL_GetTicks())
	{
		//		ConsoleSerialSend(1);
		serialTicks = SDL_GetTicks();
	}

	//		long currenttick = SDL_GetTicks();
	//			if ((serialTicks + SERIAL_TICKS_PER_FRAME) - currenttick > 0)
	//				SDL_Delay((serialTicks + SERIAL_TICKS_PER_FRAME) - currenttick);
	//}
}

//void ConsoleSerialSend(byte ConsolePacketSend) {
//	bool change = false;
//	//console->flushOutput();
//	uint8_t Buffer[16] = {0};
//	Buffer[0] = ConsolePacketSend;
//
//	if(ConsolePacketSend == 1) {
//		if(parser->ConsoleDataSend.ContolButtons[0]) Buffer[1] |= 0x1 << 0;
//		if(parser->ConsoleDataSend.ContolButtons[1]) Buffer[1] |= 0x1 << 1;
//		if(parser->ConsoleDataSend.ContolButtons[2]) Buffer[1] |= 0x1 << 2;
//		if(parser->ConsoleDataSend.ContolButtons[3]) Buffer[1] |= 0x1 << 3;
//		if(parser->ConsoleDataSend.FlightStick) Buffer[1] |= 0x1 << 4;
//
//
//		for(int x=0; x < 50; x++) {
//			if(parser->ConsoleDataSend.BLED[x]) {
//				Buffer[2 + (x / 8)] |= 0x1 << (x % 8);
//			}
//		}
//		Buffer[9] = parser->ConsoleDataSend.OnColor.r;
//		Buffer[10] = parser->ConsoleDataSend.OnColor.g;
//		Buffer[11] = parser->ConsoleDataSend.OnColor.b;
//
//		Buffer[12] = parser->ConsoleDataSend.OffColor.r;
//		Buffer[13] = parser->ConsoleDataSend.OffColor.g;
//		Buffer[14] = parser->ConsoleDataSend.OffColor.b;
//		Buffer[15] = parser->ConsolePotValue[1];
//	}
//
//	change = true;
//
//	if(ConsolePacketSend > 99) {
//		int num = (ConsolePacketSend - 100) * 5;
//		for(int x = 0; x < 5; x++) {
//
//			if(parser->ConsoleDataSend.LED[num].r != parser->LastConsoleDataSend.LED[num].r) change = true;
//			if(parser->ConsoleDataSend.LED[num].g != parser->LastConsoleDataSend.LED[num].g) change = true;
//			if(parser->ConsoleDataSend.LED[num].b != parser->LastConsoleDataSend.LED[num].b) change = true;
//
//			Buffer[(x*3) + 1] = parser->ConsoleDataSend.LED[num].r;
//			Buffer[(x*3) + 2] = parser->ConsoleDataSend.LED[num].g;
//			Buffer[(x*3) + 3] = parser->ConsoleDataSend.LED[num].b;
//			num++;
//		}
//	}

//if (change)
//parser->ConsoleSend(console, Buffer, 16);

//	parser->ConsoleSend(console, Buffer, 16);

//memcpy(parser->LastConsoleDataSend.LED, parser->ConsoleDataSend.LED, 50);
//}

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

			//			parser->ConsoleDataSend.OnColor.g++;
		}
		if (e.key.keysym.sym == SDLK_2)
		{
			//Mix_PlayChannel( 1, sfx2, 0 );
			//Mix_SetPanning(1, 0, 120);

			//			parser->ConsoleDataSend.LED[count].r = 255;
			//			parser->ConsoleDataSend.LED[count].g = 0;
			//			parser->ConsoleDataSend.LED[count].b = 0;
			//			count--;
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
			if (Zoom > 10)
				Zoom = 10;
		}

		if (e.key.keysym.sym == SDLK_KP_MINUS)
		{
			Zoom = Zoom - 0.1;
			if (Zoom < 0.01)
				Zoom = 0.01;
		}
	}

	if (e.type == SDL_KEYUP)
	{
		if (e.key.keysym.sym == SDLK_2)
		{
			lit = false;
		}
	}

	if (e.type == SDL_KEYDOWN)
		if (e.key.keysym.sym == SDLK_ESCAPE)
			quit = true;

	//Quit if escape is detected
	if (e.type == SDL_QUIT)
		quit = true;
}

bool init()
{
	#ifdef _WIN32 || _WIN64
		CurrentOS = WIN;
	#endif
	#ifdef __linux__
		CurrentOS = LINUX;
	#endif

	_sws = new SWSimulation();
	_physics = new VTPhysics(_sws);
	_render = new VTRender(_sws);
	_serial = new VTSerial(_sws);
	_net = new VTNetwork();
	StarMap = new VTMap();

	StarMap->LoadMapFile("planets.kml");
	_physics->Init();
	_serial->Init();
	_render->Init(900, 1440, 3);
	_net->init_Network();
	//SDLNet_Init();
	return true;
}

void close()
{
	//Deallocate surface
	// SDL_DestroyTexture(gTexture);
	// gTexture = NULL;

	//Destroy window
	// SDL_DestroyRenderer(gRenderer);
	// SDL_DestroyWindow(gWindow);

	// gWindow = NULL;
	// gRenderer = NULL;
	//net = NULL;

	// Mix_FreeChunk(sfx1);
	// Mix_FreeChunk(sfx2);
	// sfx1 = NULL;
	// sfx2 = NULL;
	// gMusic = NULL;
	// FC_FreeFont(gFontAure);
	// FC_FreeFont(gFontAG);

	// //Quit SDL subsystems
	// Mix_Quit();
	// IMG_Quit();
	// TTF_Quit();
	// SDL_Quit();
}

int main(int argc, char **argv)
{
	if (init())
	{
		int fps;
		int sps;
		fpsTicks = SDL_GetTicks();
		spsTicks = SDL_GetTicks();
		//std::thread serialThread(Serial_Write);
		//SDL_Thread *serialThread = SDL_CreateThread(Serial_Write, "Serial_Write", (void *)NULL);

		float frameTime;

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				handleUI(e);
			}

			if (serialTicks + SERIAL_TICKS_PER_FRAME <= SDL_GetTicks())
			{
				_serial->Update();
				//Serial_Write();
				serialTicks = SDL_GetTicks();
				sps++;
				spsTicks = SDL_GetTicks();
			}

			if (fpsTicks + SCREEN_TICKS_PER_FRAME <= SDL_GetTicks())
			{
				if (_serial->InputDown(Typeof_ConsoleInputs::FlightStickUP))
				{
					_sws->testFlag = true;
				}
				else
				{
					_sws->testFlag = false;
				}

				//				_net->update_Network(SWS);
				//fpsTicks = SDL_GetTicks();

				//parser->ConsolePressed.insert((int)Typeof_ConsoleInputs::FlightStickUP);
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickUP)) Scroll.y = Scroll.y + 5 * Zoom;
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickDOWN)) Scroll.y = Scroll.y - 5 * Zoom;
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickLEFT)) Scroll.x = Scroll.x + 5 * Zoom;
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickRIGHT)) Scroll.x = Scroll.x - 5 * Zoom;
				//
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickUP)) body->applyCentralImpulse(btVector3(0, -0.1, 0));
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickDOWN)) body->applyCentralImpulse(btVector3(0, 0.1, 0));
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickLEFT)) body->applyCentralImpulse(btVector3(0, 0, -0.1));
				//				if(parser->InputDown(Typeof_ConsoleInputs::FlightStickRIGHT)) body->applyCentralImpulse(btVector3(0, 0, 0.1));
				//
				//				if(parser->InputDown(Typeof_ConsoleInputs::LEDButton3)) body->applyCentralImpulse(btVector3(0, 0, 1));
				//
				//
				//				if(parser->InputDown(Typeof_ConsoleInputs::LEDButton1)) {
				//					printf(to_string(DiceRoller::diceRoll(10, 0, 0, 0, 0, 0, 0).success).c_str());
				//
				//					//printf(to_string(rollGreen().success).c_str());
				//
				//				}
				//
				//				if(parser->InputPressed(Typeof_ConsoleInputs::LEDButton4, true)) {
				////					ConsoleSerialSend(2);
				//				}

				//				SWS.Ship->UpdateConsole(parser);


				//				SWS.Ship->x = float (trans.getOrigin().getX());
				//				SWS.Ship->y = float (trans.getOrigin().getY());
				//				SWS.Ship->z = float (trans.getOrigin().getZ());

				//trans.getRotation()

				//printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));

				//printf("world pos object %d = %f,%f,%f\n", float(trans.getOrigin().getX()), float(trans.getOrigin().getY()), float(trans.getOrigin().getZ()));

				//render();
				_physics->Update();
				_render->Render();
				//renderGalaxyMap(0, 0);
				fps++;
				fpsTicks = SDL_GetTicks();
			}

			//if((fpsTicks + SCREEN_TICKS_PER_FRAME) - currenttick > 0)
			//SDL_Delay((fpsTicks + SCREEN_TICKS_PER_FRAME) - currenttick);

			if (fpsStart + 1000 < SDL_GetTicks())
			{

				//if (FPS_Adjust > SCREEN_TICKS_PER_FRAME * 100)
				//FPS_Adjust = SCREEN_TICKS_PER_FRAME * 100;

				//if (FPS_Adjust < 0)
				//FPS_Adjust = 0;

				_sws->FPS = fps;
				fps = 0;

				_sws->SPS = sps;				
				sps = 0;

				fpsStart = SDL_GetTicks();
			}


			//if (frameTicks < SCREEN_TICKS_PER_FRAME)
			//{
			//SDL_Delay(10);
			//}
		}

		quit = true;
	}
	else
		printf("Failed to initialize!\n");

	close();
	return 0;
}
