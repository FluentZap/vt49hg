#include "VTSerialPhraser.h"
#include "COBS.h"
#include <unordered_set>


void VTSerialPhraser::addToSet (unordered_set<int>& itemset, Typeof_ConsoleInputs item, bool pressed = true) {
	if (pressed) {
		if (itemset.find ( (int) item) == itemset.end()) {
			itemset.insert ( (int) item);
			ConsolePressButton (item);
		}

	} else {
		if (itemset.find ( (int) item) != itemset.end())
			itemset.erase ( (int) item);
	}
}

void VTSerialPhraser::ConsolePressButton (Typeof_ConsoleInputs item) {
	if (ConsoleKeyPressed.find ( (int) item) == ConsoleKeyPressed.end())
		ConsoleKeyPressed.insert ( (int) item);
}


bool VTSerialPhraser::InputDown (Typeof_ConsoleInputs key) {
	if (ConsolePressed.find ( (int) key) != ConsolePressed.end())
		return true;
	return false;
}

bool VTSerialPhraser::InputPressed (Typeof_ConsoleInputs key, bool remove) {
	if (ConsoleKeyPressed.find ( (int) key) != ConsoleKeyPressed.end()) {
		if (remove)
			ConsoleKeyPressed.erase ( (int) key);
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


void VTSerialPhraser::ConsoleReadDataStream (uint8_t* Buffer) {
	if (Buffer[0] == 1) {
		ConsoleRecievedData.DoubleTog = Buffer[1];
		ConsoleRecievedData.LEDTog = Buffer[2];
		ConsoleRecievedData.TopTog = Buffer[3];
		ConsoleRecievedData.LEDButton = Buffer[4];
		ConsoleRecievedData.LeftBoxTog = Buffer[5];
		ConsoleRecievedData.RightBoxTog = Buffer[6];
		ConsoleRecievedData.FlightStick = Buffer[7];

		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog1_UP, (ConsoleRecievedData.DoubleTog & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog1_DOWN, (ConsoleRecievedData.DoubleTog & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog2_UP, (ConsoleRecievedData.DoubleTog & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog2_DOWN, (ConsoleRecievedData.DoubleTog & option3));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog3_UP, (ConsoleRecievedData.DoubleTog & option4));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog3_DOWN, (ConsoleRecievedData.DoubleTog & option5));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog4_UP, (ConsoleRecievedData.DoubleTog & option6));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::DoubleTog4_DOWN, (ConsoleRecievedData.DoubleTog & option7));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDToggle1, (ConsoleRecievedData.LEDTog & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDToggle2, (ConsoleRecievedData.LEDTog & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDToggle3, (ConsoleRecievedData.LEDTog & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDToggle4, (ConsoleRecievedData.LEDTog & option3));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDToggle5, (ConsoleRecievedData.LEDTog & option4));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::TopLeftToggle1, (ConsoleRecievedData.TopTog & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::TopLeftToggle2, (ConsoleRecievedData.TopTog & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::TopRightToggle1, (ConsoleRecievedData.TopTog & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::TopRightToggle2, (ConsoleRecievedData.TopTog & option3));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::PotButton1, (ConsoleRecievedData.TopTog & option4));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::PotButton2, (ConsoleRecievedData.TopTog & option5));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDButton1, (ConsoleRecievedData.LEDButton & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDButton2, (ConsoleRecievedData.LEDButton & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDButton3, (ConsoleRecievedData.LEDButton & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LEDButton4, (ConsoleRecievedData.LEDButton & option3));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog1, (ConsoleRecievedData.LeftBoxTog & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog2, (ConsoleRecievedData.LeftBoxTog & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog3, (ConsoleRecievedData.LeftBoxTog & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog4, (ConsoleRecievedData.LeftBoxTog & option3));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog5, (ConsoleRecievedData.LeftBoxTog & option4));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog6, (ConsoleRecievedData.LeftBoxTog & option5));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog7, (ConsoleRecievedData.LeftBoxTog & option6));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog8, (ConsoleRecievedData.LeftBoxTog & option7));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog1, (ConsoleRecievedData.RightBoxTog & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog2, (ConsoleRecievedData.RightBoxTog & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog3, (ConsoleRecievedData.RightBoxTog & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog4, (ConsoleRecievedData.RightBoxTog & option3));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog5, (ConsoleRecievedData.RightBoxTog & option4));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog6, (ConsoleRecievedData.RightBoxTog & option5));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog7, (ConsoleRecievedData.RightBoxTog & option6));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::RightBoxTog8, (ConsoleRecievedData.RightBoxTog & option7));

		addToSet (ConsolePressed, Typeof_ConsoleInputs::FlightStickUP, (ConsoleRecievedData.FlightStick & option0));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::FlightStickDOWN, (ConsoleRecievedData.FlightStick & option1));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::FlightStickLEFT, (ConsoleRecievedData.FlightStick & option2));
		addToSet (ConsolePressed, Typeof_ConsoleInputs::FlightStickRIGHT, (ConsoleRecievedData.FlightStick & option3));
	}

	if (Buffer[0] == 2) {
		for (int x = 0; x < 15; x++) {
			CylinderCode[x] = Buffer[x + 1];
		}
	}
}

void VTSerialPhraser::ConsolePotReadDataStream (uint8_t* Buffer) {
	ConsolePotValue[0] = Buffer[0];
	ConsolePotValue[1] = Buffer[1];
	ConsolePotValue[2] = Buffer[2];
	ConsolePotValue[3] = Buffer[3];
}



void VTSerialPhraser::ConsoleSend (serial::Serial* stream, const uint8_t* buffer, size_t size) {
	if (stream->isOpen()) {
		uint8_t EncodeBuffer[COBS::getEncodedBufferSize (size)];
		size_t numEncoded = COBS::encode (buffer, size, EncodeBuffer);
		//EncodeBuffer[numEncoded] = Marker;
		stream->write (EncodeBuffer, numEncoded);

		uint8_t data[1];
		data[0] = Marker;
		stream->write (data, 1);
	}
}

void VTSerialPhraser::ConsoleUpdate (serial::Serial* stream) {
	if (stream->isOpen()) {
		while (stream->available() > 0) {
			uint8_t data[1] = {};
			stream->read (data, 1);

			if (data[0] == Marker) {
				//if (ConsoleDataBufferIndex == 13)
				//{
				uint8_t DecodeBuffer[ConsoleDataBufferIndex];
				size_t numDecoded = COBS::decode (ConsoleDataBuffer, ConsoleDataBufferIndex, DecodeBuffer);
				if (numDecoded == 16) {
					ConsoleReadDataStream (DecodeBuffer);
					ConsoleDataBufferIndex = 0;
				} else
					ConsoleDataBufferIndex = 0;
				//if (ConsoleDataBufferIndex > 13) ConsoleDataBufferIndex = 0;
			} else {
				if ( (ConsoleDataBufferIndex + 1)  < BufferSize) {
					ConsoleDataBuffer[ConsoleDataBufferIndex++] = data[0];
				} else {
					ConsoleDataBufferIndex = 0;
				}

			}

		}
	}
}



void VTSerialPhraser::ConsolePotUpdate (serial::Serial* stream) {
	if (stream->isOpen()) {
		while (stream->available() > 0) {
			uint8_t data[1] = {};
			stream->read (data, 1);

			if (data[0] == Marker) {
				uint8_t DecodeBuffer[ConsolePotDataBufferIndex];
				size_t numDecoded = COBS::decode (ConsolePotDataBuffer, ConsolePotDataBufferIndex, DecodeBuffer);
				if (numDecoded == 4) {
					ConsolePotReadDataStream (DecodeBuffer);
					ConsolePotDataBufferIndex = 0;
				} else
					ConsolePotDataBufferIndex = 0;
			} else {
				if ( (ConsolePotDataBufferIndex + 1)  < BufferSize) {
					ConsolePotDataBuffer[ConsolePotDataBufferIndex++] = data[0];
				} else {
					ConsolePotDataBufferIndex = 0;
				}

			}

		}
	}
}



VTSerialPhraser::VTSerialPhraser() {
	//RecievedData_Type ConsoleRecievedData;
	//uint8_t ConsoleDataBuffer[12];
}

VTSerialPhraser::~VTSerialPhraser() {
}
