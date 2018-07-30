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
		
		
	ConsoleData.DoubleTog[0] = (RecievedData.DoubleTog & option0);
	ConsoleData.DoubleTog[1] = (RecievedData.DoubleTog & option1);
	ConsoleData.DoubleTog[2] = (RecievedData.DoubleTog & option2);	
	ConsoleData.DoubleTog[3] = (RecievedData.DoubleTog & option3);	
	ConsoleData.DoubleTog[4] = (RecievedData.DoubleTog & option4);	
	ConsoleData.DoubleTog[5] = (RecievedData.DoubleTog & option5);	
	ConsoleData.DoubleTog[6] = (RecievedData.DoubleTog & option6);	
	ConsoleData.DoubleTog[7] = (RecievedData.DoubleTog & option7);
	
	ConsoleData.LEDTog[0] = (RecievedData.LEDTog & option0);
	ConsoleData.LEDTog[1] = (RecievedData.LEDTog & option1);
	ConsoleData.LEDTog[2] = (RecievedData.LEDTog & option2);
	ConsoleData.LEDTog[3] = (RecievedData.LEDTog & option3);
	ConsoleData.LEDTog[4] = (RecievedData.LEDTog & option4);
	
	ConsoleData.TopTog[0] = (RecievedData.TopTog & option0);
	ConsoleData.TopTog[1] = (RecievedData.TopTog & option1);
	ConsoleData.TopTog[2] = (RecievedData.TopTog & option2);
	ConsoleData.TopTog[3] = (RecievedData.TopTog & option3);
	
	ConsoleData.RotButton[0] = (RecievedData.TopTog & option4);
	ConsoleData.RotButton[1] = (RecievedData.TopTog & option5);
	
	ConsoleData.LEDButton[0] = (RecievedData.LEDButton & option0);
	ConsoleData.LEDButton[1] = (RecievedData.LEDButton & option1);
	ConsoleData.LEDButton[2] = (RecievedData.LEDButton & option2);
	ConsoleData.LEDButton[3] = (RecievedData.LEDButton & option3);
	
	ConsoleData.LeftBoxTog[0] = (RecievedData.LeftBoxTog & option0);
	ConsoleData.LeftBoxTog[1] = (RecievedData.LeftBoxTog & option1);
	ConsoleData.LeftBoxTog[2] = (RecievedData.LeftBoxTog & option2);
	ConsoleData.LeftBoxTog[3] = (RecievedData.LeftBoxTog & option3);
	ConsoleData.LeftBoxTog[4] = (RecievedData.LeftBoxTog & option4);
	ConsoleData.LeftBoxTog[5] = (RecievedData.LeftBoxTog & option5);
	ConsoleData.LeftBoxTog[6] = (RecievedData.LeftBoxTog & option6);
	ConsoleData.LeftBoxTog[7] = (RecievedData.LeftBoxTog & option7);
	
	ConsoleData.RightBoxTog[0] = (RecievedData.RightBoxTog & option0);
	ConsoleData.RightBoxTog[1] = (RecievedData.RightBoxTog & option1);
	ConsoleData.RightBoxTog[2] = (RecievedData.RightBoxTog & option2);
	ConsoleData.RightBoxTog[3] = (RecievedData.RightBoxTog & option3);
	ConsoleData.RightBoxTog[4] = (RecievedData.RightBoxTog & option4);
	ConsoleData.RightBoxTog[5] = (RecievedData.RightBoxTog & option5);
	ConsoleData.RightBoxTog[6] = (RecievedData.RightBoxTog & option6);
	ConsoleData.RightBoxTog[7] = (RecievedData.RightBoxTog & option7);
	
	ConsoleData.FlightStick[0] = (RecievedData.FlightStick & option0);
	ConsoleData.FlightStick[1] = (RecievedData.FlightStick & option1);
	ConsoleData.FlightStick[2] = (RecievedData.FlightStick & option2);
	ConsoleData.FlightStick[3] = (RecievedData.FlightStick & option3);
	
	
}

void VTSerialPhraser::Send(serial::Serial* stream, const uint8_t* buffer, size_t size)
{
	if (stream->isOpen())
	{
		uint8_t EncodeBuffer[COBS::getEncodedBufferSize(size)];
		size_t numEncoded = COBS::encode(buffer, size, EncodeBuffer);
		stream->write(EncodeBuffer, numEncoded);
		uint8_t data[1];
		data[0] = Marker;
		stream->write(data, 1);
	}
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
				if (DataBufferIndex == 14)
				{
					uint8_t DecodeBuffer[DataBufferIndex];
					size_t numDecoded = COBS::decode(DataBuffer, DataBufferIndex, DecodeBuffer);
					ReadDataStream(DecodeBuffer);
					DataBufferIndex = 0;
				}
				if (DataBufferIndex > 14) DataBufferIndex = 0;
			}
			else
			{
				if ((DataBufferIndex + 1) < BufferSize)
				{
					DataBuffer[DataBufferIndex++] = data[0];
				}
				else
				{
					DataBufferIndex = 0;
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



