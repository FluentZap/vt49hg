#ifndef SWSIMULATION_H
#define SWSIMULATION_H
#include <stdio.h>
#include <string>
#include <unordered_set>
#include "SDL.h"

using namespace std;

struct Type_PowerDistribution
{
	int Engines = 0, Shields = 0, Weapons = 0, System = 0;
};

class PlayerStats {
public:

	string name;
	uint8_t brawn, agility, intelect, cunning, willpower, presence;
	uint8_t astrogation, athletics, brawl, charm, coercion, computers, cool, coordination, coreWorlds,
	deception, discipline, education, gunnery, leadership, lightsaber, lore, mechanics, medicine,
	melee, negotiation, outerRim, perception, pilotingPlanetary, pilotingSpace, rangedHeavy,
	rangedLight, resilience, skulduggery, stealth, streetwise, survival, underworld, vigilance,
	xenology, warfare, cybernetics;
};



class PCShip
{
public:
	// string Callsign;
	// string TransponderID;
	// Type_PowerDistribution PowerDistribution;
	float x, y, z;
	// void UpdateConsole(VTSerialParser * parser);
	// SDL_Point Sector_Location;
};


class SWSimulation
{	
public:
	SWSimulation();
	~SWSimulation();
	int FPS;
	int SPS;
	PCShip* Ship = new PCShip();
	bool testFlag;

	unordered_set<int> ConsolePressed;
	uint8_t ConsoleAnalogValue[4];
	unordered_set<int> ConsoleKeyPressed;
};

#endif // SWSIMULATION_H
