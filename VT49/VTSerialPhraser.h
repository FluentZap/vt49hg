#ifndef VTSERIALPHRASER_H
#define VTSERIALPHRASER_H
#include <stdio.h>
#include <serial/serial.h>

class VTSerialPhraser
{
public:
	VTSerialPhraser();
	~VTSerialPhraser();
	uint8_t DataBuffer[12];
	void ReadDataStream();
	
	struct RecievedData_Type
	{	
		uint8_t ID;
		uint8_t DoubleTog;
		uint8_t LeftTogBox;
		uint8_t RightTogBox;
		uint8_t TopTog;
		uint8_t BottomTog;
		uint8_t FightStick;
		uint8_t LeftRot;
		uint8_t RightRot;
		uint8_t Pot1;
		uint8_t Pot2;
		uint8_t Pot3;
		uint8_t Pot4;
	};
	RecievedData_Type RecievedData;
	
	struct ConsoleDataType
	{	
		bool LTog[7],
			 RTog[7];
		bool TTog[3];
		bool CTog[4];
		int DoubleTog[3];
		bool Button[3];
		int Rot1, Rot2;
		bool Rot1B, Rot2B;
		int Poot[3];
		bool FightUP, FightDN, FightLT, FightRT;		
	};		
	
ConsoleDataType ConsoleButtons;








};

#endif // VTSERIALPHRASER_H
