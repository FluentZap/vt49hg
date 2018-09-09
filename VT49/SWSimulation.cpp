#include "SWSimulation.h"

SWSimulation::SWSimulation()
{
}

SWSimulation::~SWSimulation()
{
}

uint8_t inc;

void PCShip::UpdateConsole(VTSerialPhraser* parser)
{

	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog1_UP, true)) PowerDistrubution.Weapons++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog1_DOWN, true)) PowerDistrubution.Weapons--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog2_UP, true)) PowerDistrubution.Engines++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog2_DOWN, true)) PowerDistrubution.Engines--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog3_UP, true)) PowerDistrubution.Shields++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog3_DOWN, true)) PowerDistrubution.Shields--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog4_UP, true)) PowerDistrubution.System++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog4_DOWN, true)) PowerDistrubution.System--;
	
	
	inc++;		
	for (int x = 0; x < 10; x++)
		parser->ConsoleDataSend.LED[x].Clear();
	
	for (int x = 20; x < 30; x++)
		parser->ConsoleDataSend.LED[x].Clear();
	
	for (uint8_t x = 0; x < 50; x++)
	{
		//parser->ConsoleDataSend.LED[x].r = inc;;
		//parser->ConsoleDataSend.LED[x].g = 127;;
		parser->ConsoleDataSend.LED[x].b = inc;;
	}
		
	
	for (int x = 4; x > 4 - PowerDistrubution.System; x--)
		parser->ConsoleDataSend.LED[x].g = 127;
		
	for (int x = 0; x < PowerDistrubution.Shields; x++)
		parser->ConsoleDataSend.LED[x + 5].g = 127;
		
	
	for (int x = 4; x > 4 - PowerDistrubution.Engines; x--)
		parser->ConsoleDataSend.LED[x + 20].g = 127;
		
	for (int x = 0; x < PowerDistrubution.Weapons; x++)
		parser->ConsoleDataSend.LED[x + 25].g = 127;
		
}