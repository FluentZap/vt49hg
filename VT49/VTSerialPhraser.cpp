#include "VTSerialPhraser.h"
#include "COBS.h"
#include <unordered_set>


void VTSerialPhraser::addToSet(unordered_set<int>& itemset, Typeof_ConsoleInputs item, bool pressed = true)
{
	if (pressed)
	{
		if (itemset.find((int)item) == itemset.end())
		{
			itemset.insert((int)item);
			ConsolePressButton(item);
		}
			
	}
	else
	{
		if (itemset.find((int)item) != itemset.end())
			itemset.erase((int)item);
	}	
}
	
void VTSerialPhraser::ConsolePressButton(Typeof_ConsoleInputs item)
{
	if (ConsoleKeyPressed.find((int)item) == ConsoleKeyPressed.end())
		ConsoleKeyPressed.insert((int)item);
}


bool VTSerialPhraser::InputDown(Typeof_ConsoleInputs key)
{
	if (ConsolePressed.find((int)key) != ConsolePressed.end())
		return true;
	return false;	
}

bool VTSerialPhraser::InputPressed(Typeof_ConsoleInputs key, bool remove)
{
	if (ConsoleKeyPressed.find((int)key) != ConsoleKeyPressed.end())
	{
		if (remove)
			ConsoleKeyPressed.erase((int)key);
		return true;
	}		
	return false;	
}


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
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog1_UP, (RecievedData.DoubleTog & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog1_DOWN, (RecievedData.DoubleTog & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog2_UP, (RecievedData.DoubleTog & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog2_DOWN, (RecievedData.DoubleTog & option3));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog3_UP, (RecievedData.DoubleTog & option4));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog3_DOWN, (RecievedData.DoubleTog & option5));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog4_UP, (RecievedData.DoubleTog & option6));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::DoubleTog4_DOWN, (RecievedData.DoubleTog & option7));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDToggle1, (RecievedData.LEDTog & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDToggle2, (RecievedData.LEDTog & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDToggle3, (RecievedData.LEDTog & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDToggle4, (RecievedData.LEDTog & option3));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDToggle5, (RecievedData.LEDTog & option4));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::TopLeftToggle1, (RecievedData.TopTog & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::TopLeftToggle2, (RecievedData.TopTog & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::TopRightToggle1, (RecievedData.TopTog & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::TopRightToggle2, (RecievedData.TopTog & option3));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::PotButton1, (RecievedData.TopTog & option4));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::PotButton2, (RecievedData.TopTog & option5));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDButton1, (RecievedData.LEDButton & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDButton2, (RecievedData.LEDButton & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDButton3, (RecievedData.LEDButton & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LEDButton4, (RecievedData.LEDButton & option3));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog1, (RecievedData.LeftBoxTog & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog2, (RecievedData.LeftBoxTog & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog3, (RecievedData.LeftBoxTog & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog4, (RecievedData.LeftBoxTog & option3));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog5, (RecievedData.LeftBoxTog & option4));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog6, (RecievedData.LeftBoxTog & option5));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog7, (RecievedData.LeftBoxTog & option6));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog8, (RecievedData.LeftBoxTog & option7));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog1, (RecievedData.RightBoxTog & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog2, (RecievedData.RightBoxTog & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog3, (RecievedData.RightBoxTog & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog4, (RecievedData.RightBoxTog & option3));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog5, (RecievedData.RightBoxTog & option4));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog6, (RecievedData.RightBoxTog & option5));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog7, (RecievedData.RightBoxTog & option6));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::RightBoxTog8, (RecievedData.RightBoxTog & option7));
	
	addToSet(ConsolePressed, Typeof_ConsoleInputs::FlightStickUP, (RecievedData.FlightStick & option0));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::FlightStickDOWN, (RecievedData.FlightStick & option1));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::FlightStickLEFT, (RecievedData.FlightStick & option2));
	addToSet(ConsolePressed, Typeof_ConsoleInputs::FlightStickRIGHT, (RecievedData.FlightStick & option3));
	
}

void VTSerialPhraser::Send(serial::Serial* stream, const uint8_t* buffer, size_t size)
{
	if (stream->isOpen())
	{
		uint8_t EncodeBuffer[COBS::getEncodedBufferSize(size) + 1];
		size_t numEncoded = COBS::encode(buffer, size, EncodeBuffer);
		EncodeBuffer[numEncoded + 1] = Marker;
		stream->write(EncodeBuffer, numEncoded + 1);
		//uint8_t data[1];
		//data[0] = Marker;
		//stream->write(data, 1);
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



