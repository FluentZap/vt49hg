#include "SWSimulation.h"

SWSimulation::SWSimulation()
{
}

SWSimulation::~SWSimulation()
{
}


void PCShip::UpdateConsole(VTSerialPhraser* parser)
{		
	if (parser->ConsolePressed.DoubleTog1_UP == true && parser->ConsoleKeyProcessed.DoubleTog1_UP == false)
	{PowerDistrubution.Weapons++; parser->ConsoleKeyProcessed.DoubleTog1_UP = true;}		
	if (parser->ConsolePressed.DoubleTog1_DOWN == true && parser->ConsoleKeyProcessed.DoubleTog1_DOWN == false)
	{PowerDistrubution.Weapons--; parser->ConsoleKeyProcessed.DoubleTog1_DOWN = true;}
	
	if (parser->ConsolePressed.DoubleTog2_UP == true && parser->ConsoleKeyProcessed.DoubleTog2_UP == false)
	{PowerDistrubution.Engines++; parser->ConsoleKeyProcessed.DoubleTog2_UP = true;}
	if (parser->ConsolePressed.DoubleTog2_DOWN == true && parser->ConsoleKeyProcessed.DoubleTog2_DOWN == false)
	{PowerDistrubution.Engines--; parser->ConsoleKeyProcessed.DoubleTog2_DOWN = true;}
	
	if (parser->ConsolePressed.DoubleTog3_UP == true && parser->ConsoleKeyProcessed.DoubleTog3_UP == false)
	{PowerDistrubution.Shields++; parser->ConsoleKeyProcessed.DoubleTog3_UP = true;}		
	if (parser->ConsolePressed.DoubleTog3_DOWN == true && parser->ConsoleKeyProcessed.DoubleTog3_DOWN == false)
	{PowerDistrubution.Shields--; parser->ConsoleKeyProcessed.DoubleTog3_DOWN = true;}
	
	if (parser->ConsolePressed.DoubleTog4_UP == true && parser->ConsoleKeyProcessed.DoubleTog4_UP == false)
	{PowerDistrubution.System++; parser->ConsoleKeyProcessed.DoubleTog4_UP = true;}		
	if (parser->ConsolePressed.DoubleTog4_DOWN == true && parser->ConsoleKeyProcessed.DoubleTog4_DOWN == false)
	{PowerDistrubution.System--; parser->ConsoleKeyProcessed.DoubleTog4_DOWN = true;}
	
	//need to automate this
	if (parser->ConsolePressed.DoubleTog1_UP == false) parser->ConsoleKeyProcessed.DoubleTog1_UP = false;
	if (parser->ConsolePressed.DoubleTog1_DOWN == false) parser->ConsoleKeyProcessed.DoubleTog1_DOWN = false;
	
	if (parser->ConsolePressed.DoubleTog2_UP == false) parser->ConsoleKeyProcessed.DoubleTog2_UP = false;
	if (parser->ConsolePressed.DoubleTog2_DOWN == false) parser->ConsoleKeyProcessed.DoubleTog2_DOWN = false;
	
	if (parser->ConsolePressed.DoubleTog3_UP == false) parser->ConsoleKeyProcessed.DoubleTog3_UP = false;
	if (parser->ConsolePressed.DoubleTog3_DOWN == false) parser->ConsoleKeyProcessed.DoubleTog3_DOWN = false;
	
	if (parser->ConsolePressed.DoubleTog4_UP == false) parser->ConsoleKeyProcessed.DoubleTog4_UP = false;
	if (parser->ConsolePressed.DoubleTog4_DOWN == false) parser->ConsoleKeyProcessed.DoubleTog4_DOWN = false;
	
	
	for (int x = 0; x < 10; x++)
		parser->ConsoleDataSend.LED[x].Clear();
	
	for (int x = 20; x < 30; x++)
		parser->ConsoleDataSend.LED[x].Clear();
	
	for (int x = 4; x > 4 - PowerDistrubution.System; x--)
		parser->ConsoleDataSend.LED[x].b = 127;
		
	for (int x = 0; x < PowerDistrubution.Shields; x++)
		parser->ConsoleDataSend.LED[x + 5].b = 127;
		
	
	for (int x = 4; x > 4 - PowerDistrubution.Engines; x--)
		parser->ConsoleDataSend.LED[x + 20].b = 127;		
		
	for (int x = 0; x < PowerDistrubution.Weapons; x++)
		parser->ConsoleDataSend.LED[x + 25].b = 127;
		
}
