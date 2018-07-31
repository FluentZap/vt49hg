#ifndef SWSIMULATION_H
#define SWSIMULATION_H
#include <stdio.h>
#include <VTSerialPhraser.h>

struct Type_PowerDistrubution
{
	int Engines = 0, Shields = 0, Weapons = 0, System = 0;	
};


class PCShip
{	
public:
	string Callsign;
	string TransponderID;	
	Type_PowerDistrubution PowerDistrubution;
	
	void UpdateConsole(VTSerialPhraser * parser);	
};









class SWSimulation
{
public:
	SWSimulation();
	~SWSimulation();
	
	PCShip* Ship = new PCShip();	
	
	



};

#endif // SWSIMULATION_H
