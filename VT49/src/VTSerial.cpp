#include "VTSerial.h"
#include "COBS.h"
#include <unordered_set>

VTSerial::VTSerial(SWSimulation *SWS)
{
	VTSerial::SWS = SWS;
	//RecievedData_Type ConsoleReceivedData;
	//uint8_t ConsoleDataBuffer[12];
}

VTSerial::~VTSerial()
{
}

void VTSerial::Init()
{
	RS232_OpenComport(3, 28800, "8N1", 1);
	RS232_OpenComport(5, 28800, "8N1", 1);
	_panel.push_back(new SerialConnection(3, ListOf_DeviceTypes::Console));
	_panel.push_back(new SerialConnection(5, ListOf_DeviceTypes::ConsoleAnalog, 4));
	// if(CurrentOS == WIN) RS232_OpenComport(3, 28800, "8N1", 1);
	// if(CurrentOS == WIN) RS232_OpenComport(5, 28800, "8N1", 1);
}

void VTSerial::addToSet(unordered_set<int> &itemset, Typeof_ConsoleInputs item, bool pressed = true)
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

void VTSerial::ConsolePressButton(Typeof_ConsoleInputs item)
{
	if (SWS->ConsoleKeyPressed.find((int)item) == SWS->ConsoleKeyPressed.end())
		SWS->ConsoleKeyPressed.insert((int)item);
}

bool VTSerial::InputDown(Typeof_ConsoleInputs key)
{
	if (SWS->ConsolePressed.find((int)key) != SWS->ConsolePressed.end())
		return true;
	return false;
}

bool VTSerial::InputPressed(Typeof_ConsoleInputs key, bool remove)
{
	if (SWS->ConsoleKeyPressed.find((int)key) != SWS->ConsoleKeyPressed.end())
	{
		if (remove)
			SWS->ConsoleKeyPressed.erase((int)key);
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

void VTSerial::ConsoleReadDataStream(vector<uint8_t> Buffer)
{
	if (Buffer[0] == 1)
	{
		ConsoleReceivedData.DoubleTog = Buffer[1];
		ConsoleReceivedData.LEDTog = Buffer[2];
		ConsoleReceivedData.TopTog = Buffer[3];
		ConsoleReceivedData.LEDButton = Buffer[4];
		ConsoleReceivedData.LeftBoxTog = Buffer[5];
		ConsoleReceivedData.RightBoxTog = Buffer[6];
		ConsoleReceivedData.FlightStick = Buffer[7];

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog1_UP, (ConsoleReceivedData.DoubleTog & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog1_DOWN, (ConsoleReceivedData.DoubleTog & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog2_UP, (ConsoleReceivedData.DoubleTog & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog2_DOWN, (ConsoleReceivedData.DoubleTog & option3));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog3_UP, (ConsoleReceivedData.DoubleTog & option4));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog3_DOWN, (ConsoleReceivedData.DoubleTog & option5));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog4_UP, (ConsoleReceivedData.DoubleTog & option6));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::DoubleTog4_DOWN, (ConsoleReceivedData.DoubleTog & option7));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDToggle1, (ConsoleReceivedData.LEDTog & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDToggle2, (ConsoleReceivedData.LEDTog & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDToggle3, (ConsoleReceivedData.LEDTog & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDToggle4, (ConsoleReceivedData.LEDTog & option3));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDToggle5, (ConsoleReceivedData.LEDTog & option4));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::TopLeftToggle1, (ConsoleReceivedData.TopTog & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::TopLeftToggle2, (ConsoleReceivedData.TopTog & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::TopRightToggle1, (ConsoleReceivedData.TopTog & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::TopRightToggle2, (ConsoleReceivedData.TopTog & option3));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::PotButton1, (ConsoleReceivedData.TopTog & option4));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::PotButton2, (ConsoleReceivedData.TopTog & option5));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDButton1, (ConsoleReceivedData.LEDButton & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDButton2, (ConsoleReceivedData.LEDButton & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDButton3, (ConsoleReceivedData.LEDButton & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LEDButton4, (ConsoleReceivedData.LEDButton & option3));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog1, (ConsoleReceivedData.LeftBoxTog & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog2, (ConsoleReceivedData.LeftBoxTog & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog3, (ConsoleReceivedData.LeftBoxTog & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog4, (ConsoleReceivedData.LeftBoxTog & option3));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog5, (ConsoleReceivedData.LeftBoxTog & option4));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog6, (ConsoleReceivedData.LeftBoxTog & option5));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog7, (ConsoleReceivedData.LeftBoxTog & option6));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::LeftBoxTog8, (ConsoleReceivedData.LeftBoxTog & option7));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog1, (ConsoleReceivedData.RightBoxTog & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog2, (ConsoleReceivedData.RightBoxTog & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog3, (ConsoleReceivedData.RightBoxTog & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog4, (ConsoleReceivedData.RightBoxTog & option3));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog5, (ConsoleReceivedData.RightBoxTog & option4));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog6, (ConsoleReceivedData.RightBoxTog & option5));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog7, (ConsoleReceivedData.RightBoxTog & option6));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::RightBoxTog8, (ConsoleReceivedData.RightBoxTog & option7));

		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::FlightStickUP, (ConsoleReceivedData.FlightStick & option0));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::FlightStickDOWN, (ConsoleReceivedData.FlightStick & option1));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::FlightStickLEFT, (ConsoleReceivedData.FlightStick & option2));
		addToSet(SWS->ConsolePressed, Typeof_ConsoleInputs::FlightStickRIGHT, (ConsoleReceivedData.FlightStick & option3));
	}

	if (Buffer[0] == 2)
	{
		for (int x = 0; x < 15; x++)
		{
			CylinderCode[x] = Buffer[x + 1];
		}
	}
}

void VTSerial::ConsoleAnalogReadDataStream(vector<uint8_t> Buffer)
{
	SWS->ConsoleAnalogValue[0] = Buffer[0];
	SWS->ConsoleAnalogValue[1] = Buffer[1];
	SWS->ConsoleAnalogValue[2] = Buffer[2];
	SWS->ConsoleAnalogValue[3] = Buffer[3];
}

//void VTSerial::ConsoleSend(const int port, const uint8_t* buffer, size_t size) {
//	uint8_t EncodeBuffer[COBS::getEncodedBufferSize(size)];
//	size_t numEncoded = COBS::encode(buffer, size, EncodeBuffer);
//	//EncodeBuffer[numEncoded] = Marker;
//	RS232_SendBuf(port, EncodeBuffer, numEncoded);
////		stream->write(EncodeBuffer, numEncoded);
//
////		uint8_t data[1];
////		data[0] = Marker;
//	RS232_SendByte(port, Marker)
////		stream->write(data, 1);
//}

//void VTSerial::ConsoleUpdate(const int port) {
//
//	do {
//		uint8_t data[255] = {};
//		int received = RS232_PollComport(port, data, 256);
//		for(int i = 0; i < received; i++) {
//			if(data[i] == Marker) {
//				//if (ConsoleDataBufferIndex == 13)
//				//{
//				uint8_t DecodeBuffer[ConsoleDataBufferIndex];
//				size_t numDecoded = COBS::decode(ConsoleDataBuffer, ConsoleDataBufferIndex, DecodeBuffer);
//				if(numDecoded == 16) {
//					ConsoleReadDataStream(DecodeBuffer);
//					ConsoleDataBufferIndex = 0;
//				} else
//					ConsoleDataBufferIndex = 0;
//				//if (ConsoleDataBufferIndex > 13) ConsoleDataBufferIndex = 0;
//			} else {
//				if((ConsoleDataBufferIndex + 1) < BufferSize) {
//					ConsoleDataBuffer[ConsoleDataBufferIndex++] = data[i];
//				} else {
//					ConsoleDataBufferIndex = 0;
//				}
//
//			}
//		}
//
//	} while(received > 0)
//	}

//void VTSerial::ConsolePotUpdate(serial::Serial* stream) {
//	if(stream->isOpen()) {
//		while(stream->available() > 0) {
//			uint8_t data[1] = {};
//			stream->read(data, 1);
//
//			if(data[0] == Marker) {
//				uint8_t DecodeBuffer[ConsolePotDataBufferIndex];
//				size_t numDecoded = COBS::decode(ConsolePotDataBuffer, ConsolePotDataBufferIndex, DecodeBuffer);
//				if(numDecoded == 4) {
//					ConsolePotReadDataStream(DecodeBuffer);
//					ConsolePotDataBufferIndex = 0;
//				} else
//					ConsolePotDataBufferIndex = 0;
//			} else {
//				if((ConsolePotDataBufferIndex + 1)  < BufferSize) {
//					ConsolePotDataBuffer[ConsolePotDataBufferIndex++] = data[0];
//				} else {
//					ConsolePotDataBufferIndex = 0;
//				}
//
//			}
//
//		}
//	}
//}

void VTSerial::Update()
{
	//check all panels and decode buffers
	vector<uint8_t> buffer;
	for (size_t i = 0; i < _panel.size(); i++)
	{
		do
		{
			buffer = _panel[i]->ReadAvailable();
			if (buffer.size() > 0)
			{
				switch (_panel[i]->Type)
				{
				case ListOf_DeviceTypes::Console:
					ConsoleReadDataStream(buffer);
					break;

				case ListOf_DeviceTypes::ConsoleAnalog:
					ConsoleAnalogReadDataStream(buffer);
					break;

				default:
					break;
				}

			}
		} while (buffer.size() > 0);
	}

		vector<uint8_t> sendBuffer (16);
		sendBuffer[0] = 1;
		if (true) sendBuffer[1] |= 0x1 << 0;
		if(false) sendBuffer[1] |= 0x1 << 1;
		if (true) sendBuffer[1] |= 0x1 << 2;
		if (true) sendBuffer[1] |= 0x1 << 3;

		//flight stick
		if(true) sendBuffer[1] |= 0x1 << 4;


		for(int x=0; x < 50; x++) {
			if(true) {
				sendBuffer[2 + (x / 8)] |= 0x1 << (x % 8);
			}
		}

		sendBuffer[9] = SWS->ConsoleAnalogValue[0];
		sendBuffer[10] = SWS->ConsoleAnalogValue[1];
		sendBuffer[11] = SWS->ConsoleAnalogValue[2];

		sendBuffer[12] = 30;
		sendBuffer[13] = 0;
		sendBuffer[14] = 0;

		///sendBuffer[9] = parser->ConsoleDataSend.OnColor.r;
		///sendBuffer[10] = parser->ConsoleDataSend.OnColor.g;
		// sendBuffer[11] = parser->ConsoleDataSend.OnColor.b;

		// sendBuffer[12] = parser->ConsoleDataSend.OffColor.r;
		// sendBuffer[13] = parser->ConsoleDataSend.OffColor.g;
		// sendBuffer[14] = parser->ConsoleDataSend.OffColor.b;
		sendBuffer[15] = SWS->ConsoleAnalogValue[0];
		_panel[0]->Send(sendBuffer);
}