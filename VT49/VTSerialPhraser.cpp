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
	
	ConsolePressed.DoubleTog1_UP = (RecievedData.DoubleTog & option0);
	ConsolePressed.DoubleTog1_DOWN   = (RecievedData.DoubleTog & option1);
	ConsolePressed.DoubleTog2_UP = (RecievedData.DoubleTog & option2);
	ConsolePressed.DoubleTog2_DOWN   = (RecievedData.DoubleTog & option3);
	ConsolePressed.DoubleTog3_UP = (RecievedData.DoubleTog & option4);
	ConsolePressed.DoubleTog3_DOWN   = (RecievedData.DoubleTog & option5);
	ConsolePressed.DoubleTog4_UP = (RecievedData.DoubleTog & option6);
	ConsolePressed.DoubleTog4_DOWN   = (RecievedData.DoubleTog & option7);
	
	ConsolePressed.LEDToggle1      = (RecievedData.LEDTog & option0);
	ConsolePressed.LEDToggle2      = (RecievedData.LEDTog & option1);
	ConsolePressed.LEDToggle3      = (RecievedData.LEDTog & option2);
	ConsolePressed.LEDToggle4      = (RecievedData.LEDTog & option3);
	ConsolePressed.LEDToggle5      = (RecievedData.LEDTog & option4);
	
	ConsolePressed.TopLeftToggle1  = (RecievedData.TopTog & option0);
	ConsolePressed.TopLeftToggle2  = (RecievedData.TopTog & option1);
	ConsolePressed.TopRightToggle1 = (RecievedData.TopTog & option2);
	ConsolePressed.TopRightToggle2 = (RecievedData.TopTog & option3);
	
	ConsolePressed.PotButton1      = (RecievedData.TopTog & option4);
	ConsolePressed.PotButton2      = (RecievedData.TopTog & option5);
	
	ConsolePressed.LEDButton1	   = (RecievedData.LEDButton & option0);
	ConsolePressed.LEDButton2	   = (RecievedData.LEDButton & option1);
	ConsolePressed.LEDButton3	   = (RecievedData.LEDButton & option2);
	ConsolePressed.LEDButton4	   = (RecievedData.LEDButton & option3);
	
	ConsolePressed.LeftBoxTog1	   = (RecievedData.LeftBoxTog & option0);
	ConsolePressed.LeftBoxTog2	   = (RecievedData.LeftBoxTog & option1);
	ConsolePressed.LeftBoxTog3	   = (RecievedData.LeftBoxTog & option2);
	ConsolePressed.LeftBoxTog4	   = (RecievedData.LeftBoxTog & option3);
	ConsolePressed.LeftBoxTog5	   = (RecievedData.LeftBoxTog & option4);
	ConsolePressed.LeftBoxTog6	   = (RecievedData.LeftBoxTog & option5);
	ConsolePressed.LeftBoxTog7	   = (RecievedData.LeftBoxTog & option6);
	ConsolePressed.LeftBoxTog8	   = (RecievedData.LeftBoxTog & option7);
	
	ConsolePressed.RightBoxTog1	   = (RecievedData.RightBoxTog & option0);
	ConsolePressed.RightBoxTog2	   = (RecievedData.RightBoxTog & option1);
	ConsolePressed.RightBoxTog3	   = (RecievedData.RightBoxTog & option2);
	ConsolePressed.RightBoxTog4	   = (RecievedData.RightBoxTog & option3);
	ConsolePressed.RightBoxTog5	   = (RecievedData.RightBoxTog & option4);
	ConsolePressed.RightBoxTog6	   = (RecievedData.RightBoxTog & option5);
	ConsolePressed.RightBoxTog7	   = (RecievedData.RightBoxTog & option6);
	ConsolePressed.RightBoxTog8	   = (RecievedData.RightBoxTog & option7);
	
	ConsolePressed.FlightStickUP   = (RecievedData.FlightStick & option0);
	ConsolePressed.FlightStickDOWN = (RecievedData.FlightStick & option1);
	ConsolePressed.FlightStickLEFT = (RecievedData.FlightStick & option2);
	ConsolePressed.FlightStickRIGHT= (RecievedData.FlightStick & option3);	
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



