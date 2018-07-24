#ifndef VTSERIALPHRASER_H
#define VTSERIALPHRASER_H
#include <stdio.h>
#include <serial/serial.h>

class VTSerialPhraser
{
public:
	VTSerialPhraser();
	~VTSerialPhraser();
	
	uint8_t Marker = 0;
	const static size_t BufferSize = 256;

	int DataBufferIndex = 0;
	uint8_t DataBuffer[BufferSize] = {};	
	
	
	
	void ReadDataStream(uint8_t*);
	void Update(serial::Serial*);
	
	void Send(serial::Serial* Stream, const uint8_t* Buffer, size_t Size);	
	
	
	struct RecievedData_Type
	{			
		uint8_t DoubleTog = 0;
		uint8_t LEDTog = 0;
		uint8_t TopTog = 0;		
		uint8_t LEDButton = 0;
		uint8_t LeftBoxTog = 0;		
		uint8_t RightBoxTog = 0;
		uint8_t FlightStick = 0;		
	};
	RecievedData_Type RecievedData;
	
	struct ConsoleDataType
	{	
		bool DoubleTog[8] = {};
		bool LEDTog[5] = {};
		bool TopTog[4] = {};
		bool RotButton[2] = {};
		bool LEDButton[4] = {};
		
		bool LeftBoxTog[8] = {};
		bool RightBoxTog[8] = {};
		bool FlightStick[4] = {};
	};		
	
ConsoleDataType ConsoleButtons;








};

#endif // VTSERIALPHRASER_H
