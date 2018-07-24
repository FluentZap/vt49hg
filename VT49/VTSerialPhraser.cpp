#include "VTSerialPhraser.h"
#include "COBS.h"

const unsigned char option0 = 0b00000001; // represents bit 0
const unsigned char option1 = 0b00000010; // represents bit 1
const unsigned char option2 = 0b00000100; // represents bit 2 
const unsigned char option3 = 0b00001000; // represents bit 3
const unsigned char option4 = 0b00010000; // represents bit 4
const unsigned char option5 = 0b00100000; // represents bit 5
const unsigned char option6 = 0b01000000; // represents bit 6
const unsigned char option7 = 0b10000000; // represents bit 7

//#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

void VTSerialPhraser::ReadDataStream(uint8_t* Buffer)
{		
	RecievedData.DoubleTog = Buffer[0];
	RecievedData.LEDTog = Buffer[1];
	RecievedData.TopTog = Buffer[2];
	RecievedData.LEDButton = Buffer[3];
	RecievedData.LeftBoxTog = Buffer[4];
	RecievedData.RightBoxTog = Buffer[5];
	RecievedData.FlightStick = Buffer[6];
		
		
	ConsoleButtons.DoubleTog[0] = (RecievedData.DoubleTog & option0);
	ConsoleButtons.DoubleTog[1] = (RecievedData.DoubleTog & option1);
	ConsoleButtons.DoubleTog[2] = (RecievedData.DoubleTog & option1);	
	ConsoleButtons.DoubleTog[3] = (RecievedData.DoubleTog & option1);	
	ConsoleButtons.DoubleTog[4] = (RecievedData.DoubleTog & option1);	
	ConsoleButtons.DoubleTog[5] = (RecievedData.DoubleTog & option1);	
	ConsoleButtons.DoubleTog[6] = (RecievedData.DoubleTog & option1);	
	ConsoleButtons.DoubleTog[7] = (RecievedData.DoubleTog & option1);
	
	ConsoleButtons.LEDTog[0] = (RecievedData.LEDTog & option0);
	ConsoleButtons.LEDTog[1] = (RecievedData.LEDTog & option1);
	ConsoleButtons.LEDTog[2] = (RecievedData.LEDTog & option2);
	ConsoleButtons.LEDTog[3] = (RecievedData.LEDTog & option3);
	ConsoleButtons.LEDTog[4] = (RecievedData.LEDTog & option4);
	
	ConsoleButtons.TopTog[0] = (RecievedData.TopTog & option0);
	ConsoleButtons.TopTog[1] = (RecievedData.TopTog & option1);
	ConsoleButtons.TopTog[2] = (RecievedData.TopTog & option2);
	ConsoleButtons.TopTog[3] = (RecievedData.TopTog & option3);
	
	ConsoleButtons.RotButton[0] = (RecievedData.TopTog & option4);
	ConsoleButtons.RotButton[1] = (RecievedData.TopTog & option5);
	
	ConsoleButtons.LEDButton[0] = (RecievedData.LEDButton & option0);
	ConsoleButtons.LEDButton[1] = (RecievedData.LEDButton & option1);
	ConsoleButtons.LEDButton[2] = (RecievedData.LEDButton & option2);
	ConsoleButtons.LEDButton[3] = (RecievedData.LEDButton & option3);
	
	ConsoleButtons.LeftBoxTog[0] = (RecievedData.LeftBoxTog & option0);
	ConsoleButtons.LeftBoxTog[1] = (RecievedData.LeftBoxTog & option1);
	ConsoleButtons.LeftBoxTog[2] = (RecievedData.LeftBoxTog & option2);
	ConsoleButtons.LeftBoxTog[3] = (RecievedData.LeftBoxTog & option3);
	ConsoleButtons.LeftBoxTog[4] = (RecievedData.LeftBoxTog & option4);
	ConsoleButtons.LeftBoxTog[5] = (RecievedData.LeftBoxTog & option5);
	ConsoleButtons.LeftBoxTog[6] = (RecievedData.LeftBoxTog & option6);
	ConsoleButtons.LeftBoxTog[7] = (RecievedData.LeftBoxTog & option7);
	
	ConsoleButtons.RightBoxTog[0] = (RecievedData.RightBoxTog & option0);
	ConsoleButtons.RightBoxTog[1] = (RecievedData.RightBoxTog & option1);
	ConsoleButtons.RightBoxTog[2] = (RecievedData.RightBoxTog & option2);
	ConsoleButtons.RightBoxTog[3] = (RecievedData.RightBoxTog & option3);
	ConsoleButtons.RightBoxTog[4] = (RecievedData.RightBoxTog & option4);
	ConsoleButtons.RightBoxTog[5] = (RecievedData.RightBoxTog & option5);
	ConsoleButtons.RightBoxTog[6] = (RecievedData.RightBoxTog & option6);
	ConsoleButtons.RightBoxTog[7] = (RecievedData.RightBoxTog & option7);
	
	ConsoleButtons.FlightStick[0] = (RecievedData.FlightStick & option0);
	ConsoleButtons.FlightStick[1] = (RecievedData.FlightStick & option1);
	ConsoleButtons.FlightStick[2] = (RecievedData.FlightStick & option2);
	ConsoleButtons.FlightStick[3] = (RecievedData.FlightStick & option3);
	
	
}




void VTSerialPhraser::Update(serial::Serial* stream)
{	
	if (stream->isOpen())
	{
		while (stream->available() > 0)
		{
			uint8_t data[1] = {};
			stream->read(data, 1);			
			
			if (data[0] == Marker)
			{
				uint8_t DecodeBuffer[DataBufferIndex];
				size_t numDecoded = COBS::decode(DataBuffer, DataBufferIndex, DecodeBuffer);				
				ReadDataStream(DecodeBuffer);
				DataBufferIndex = 0;
			}
			else
			{
				if ((DataBufferIndex + 1) < BufferSize)
				{
					DataBuffer[DataBufferIndex++] = data[0];
				}
				else
				{
					//Error
				}				
			}
		}

	}
	
	
	
}




VTSerialPhraser::VTSerialPhraser()
{
	RecievedData_Type RecievedData;
	uint8_t DataBuffer[12];
}

VTSerialPhraser::~VTSerialPhraser()
{
}



