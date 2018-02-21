#include "VTSerialPhraser.h"

const unsigned char option0 = 0b0000'0001; // represents bit 0
const unsigned char option1 = 0b0000'0010; // represents bit 1
const unsigned char option2 = 0b0000'0100; // represents bit 2 
const unsigned char option3 = 0b0000'1000; // represents bit 3
const unsigned char option4 = 0b0001'0000; // represents bit 4
const unsigned char option5 = 0b0010'0000; // represents bit 5
const unsigned char option6 = 0b0100'0000; // represents bit 6
const unsigned char option7 = 0b1000'0000; // represents bit 7



void VTSerialPhraser::ReadDataStream()
{	
	RecievedData.ID = DataBuffer[0];
	RecievedData.DoubleTog = DataBuffer[1];
	RecievedData.LeftTogBox = DataBuffer[2];
	RecievedData.RightTogBox = DataBuffer[3];
	RecievedData.TopTog = DataBuffer[4];
	RecievedData.BottomTog = DataBuffer[5];
	RecievedData.FightStick = DataBuffer[6];
	RecievedData.LeftRot = DataBuffer[7];
	RecievedData.RightRot = DataBuffer[8];
	RecievedData.Pot1 = DataBuffer[9];
	RecievedData.Pot2 = DataBuffer[10];
	RecievedData.Pot3 = DataBuffer[11];
	RecievedData.Pot4 = DataBuffer[12];
	RecievedData.ID = DataBuffer[13];
	
	
	//ConsoleButtons.DoubleTog1 = (RecievedData.DoubleTog & option0)
	//ConsoleButtons.DoubleTog1 = (RecievedData.DoubleTog & option0)
	ConsoleButtons.LTog[0] = (RecievedData.LeftTogBox & option0);
	ConsoleButtons.LTog[1] = (RecievedData.LeftTogBox & option1);
	ConsoleButtons.LTog[2] = (RecievedData.LeftTogBox & option2);
	ConsoleButtons.LTog[3] = (RecievedData.LeftTogBox & option3);
	ConsoleButtons.LTog[4] = (RecievedData.LeftTogBox & option4);
	ConsoleButtons.LTog[5] = (RecievedData.LeftTogBox & option5);
	ConsoleButtons.LTog[6] = (RecievedData.LeftTogBox & option6);
	ConsoleButtons.LTog[7] = (RecievedData.LeftTogBox & option7);
	
}









VTSerialPhraser::VTSerialPhraser()
{
	RecievedData_Type RecievedData;
	uint8_t DataBuffer[12];
}

VTSerialPhraser::~VTSerialPhraser()
{
}



