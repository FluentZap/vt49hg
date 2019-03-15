#include "SWSimulation.h"

SWSimulation::SWSimulation()
{
}

SWSimulation::~SWSimulation()
{
}

int inc;
uint8_t col;


void PCShip::UpdateConsole(VTSerialPhraser* parser)
{
	
	uint8_t color = parser->ConsolePotValue[0];

	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog1_UP)) PowerDistrubution.Weapons++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog1_DOWN)) PowerDistrubution.Weapons--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog2_UP)) PowerDistrubution.Engines++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog2_DOWN)) PowerDistrubution.Engines--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog3_UP)) PowerDistrubution.Shields++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog3_DOWN)) PowerDistrubution.Shields--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog4_UP)) PowerDistrubution.System++;
	if (parser->InputPressed(Typeof_ConsoleInputs::DoubleTog4_DOWN)) PowerDistrubution.System--;
	
	if (parser->InputPressed(Typeof_ConsoleInputs::LEDButton1)) parser->ConsoleDataSend.ContolButtons[0] = !parser->ConsoleDataSend.ContolButtons[0];
	//if (parser->InputPressed(Typeof_ConsoleInputs::LEDButton2, true)) parser->ConsoleDataSend.ContolButtons[1] = !parser->ConsoleDataSend.ContolButtons[1];
	//if (parser->InputPressed(Typeof_ConsoleInputs::LEDButton3, true)) parser->ConsoleDataSend.ContolButtons[2] = !parser->ConsoleDataSend.ContolButtons[2];
	//if (parser->InputPressed(Typeof_ConsoleInputs::LEDButton4, true)) parser->ConsoleDataSend.ContolButtons[3] = !parser->ConsoleDataSend.ContolButtons[3];
	
	
	parser->ConsoleDataSend.OnColor.r = 0;
	parser->ConsoleDataSend.OnColor.g = 0;
	parser->ConsoleDataSend.OnColor.b = color;
	
	parser->ConsoleDataSend.OffColor.r = 0;
	parser->ConsoleDataSend.OffColor.g = 0;
	parser->ConsoleDataSend.OffColor.b = 0;
	
	col++;
	inc++;
	//set all lights blank
	for (int x = 0; x < 50; x++)
		parser->ConsoleDataSend.BLED[x] = false;
	
	
	for (int x = 0; x < 10; x++)
		parser->ConsoleDataSend.BLED[x] = false;
	for (int x = 20; x < 30; x++)
		parser->ConsoleDataSend.BLED[x] = false;
	
	//Set lights for power
	for (int x = 4; x > 4 - PowerDistrubution.System; x--)
		parser->ConsoleDataSend.BLED[x] = true;
		
	for (int x = 0; x < PowerDistrubution.Shields; x++)
		parser->ConsoleDataSend.BLED[x + 5] = true;
	
	for (int x = 4; x > 4 - PowerDistrubution.Engines; x--)
		parser->ConsoleDataSend.BLED[x + 20] = true;
		
	for (int x = 0; x < PowerDistrubution.Weapons; x++)
		parser->ConsoleDataSend.BLED[x + 25] = true;
	
	
	if (parser->InputDown(Typeof_ConsoleInputs::TopLeftToggle1))
			parser->ConsoleDataSend.BLED[32] = true;
		else
			parser->ConsoleDataSend.BLED[31] = true;
			
	if (parser->InputDown(Typeof_ConsoleInputs::TopLeftToggle2))
			parser->ConsoleDataSend.BLED[33] = true;
		else
			parser->ConsoleDataSend.BLED[30] = true;
	
	
	if (parser->InputDown(Typeof_ConsoleInputs::TopRightToggle1))
			parser->ConsoleDataSend.BLED[41] = true;
		else
			parser->ConsoleDataSend.BLED[42] = true;
			
	if (parser->InputDown(Typeof_ConsoleInputs::TopRightToggle2))
			parser->ConsoleDataSend.BLED[40] = true;
		else
			parser->ConsoleDataSend.BLED[43] = true;
			
	//if (parser->InputPressed(Typeof_ConsoleInputs::TopLeftToggle2)) parser->ConsoleDataSend.BLED[42] = true;
	
	//if (parser->InputPressed(Typeof_ConsoleInputs::TopRightToggle1)) parser->ConsoleDataSend.BLED[41] = true;
	//if (parser->InputPressed(Typeof_ConsoleInputs::TopRightToggle2)) parser->ConsoleDataSend.BLED[40] = true;
	
	
	
	if (inc >= 40)
	{
		if (parser->ConsoleDataSend.ContolButtons[0])
		{
			parser->ConsoleDataSend.ContolButtons[2] = !parser->ConsoleDataSend.ContolButtons[2];
			parser->ConsoleDataSend.ContolButtons[3] = !parser->ConsoleDataSend.ContolButtons[3];
		}
		inc = 0;
	}
}





