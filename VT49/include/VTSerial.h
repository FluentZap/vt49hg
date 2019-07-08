#ifndef VTSERIAL_H
#define VTSERIAL_H
#include <stdio.h>
#include <rs232.h>
#include <unordered_set>
#include <array>
#include <vector>
#include "SerialConnection.h"
#include "SWSimulation.h"

using namespace std;

enum class Typeof_ConsoleInputs : int
{
	DoubleTog1_UP,
	DoubleTog1_DOWN,
	DoubleTog2_UP,
	DoubleTog2_DOWN,
	DoubleTog3_UP,
	DoubleTog3_DOWN,
	DoubleTog4_UP,
	DoubleTog4_DOWN,
	LEDToggle1,
	LEDToggle2,
	LEDToggle3,
	LEDToggle4,
	LEDToggle5,
	TopLeftToggle1,
	TopLeftToggle2,
	TopRightToggle1,
	TopRightToggle2,
	PotButton1,
	PotButton2,
	LEDButton1,
	LEDButton2,
	LEDButton3,
	LEDButton4,
	LeftBoxTog1,
	LeftBoxTog2,
	LeftBoxTog3,
	LeftBoxTog4,
	LeftBoxTog5,
	LeftBoxTog6,
	LeftBoxTog7,
	LeftBoxTog8,
	RightBoxTog1,
	RightBoxTog2,
	RightBoxTog3,
	RightBoxTog4,
	RightBoxTog5,
	RightBoxTog6,
	RightBoxTog7,
	RightBoxTog8,
	FlightStickUP,
	FlightStickDOWN,
	FlightStickLEFT,
	FlightStickRIGHT
};

class VTSerial
{
public:
	VTSerial(SWSimulation *SWS);
	~VTSerial();
	void Init();
	void Update();

	uint8_t Marker = 0;
	const static size_t BufferSize = 256;

	//Console Serial Varables
	int ConsoleDataBufferIndex = 0;
	uint8_t ConsoleDataBuffer[BufferSize] = {};

	void ConsoleReadDataStream(vector<uint8_t> Buffer);

	void ConsoleUpdate();

	//	void ConsoleSend(serial::Serial* Stream, const uint8_t* Buffer, size_t Size);

	//Console Pot Serial Varables
	int ConsolePotDataBufferIndex = 0;
	uint8_t ConsolePotDataBuffer[BufferSize] = {};

	//void ConsolePotReadDataStream(uint8_t*);
	//void ConsolePotUpdate(serial::Serial*);

	struct ConsoleReceivedData_Type
	{
		uint8_t DoubleTog = 0;
		uint8_t LEDTog = 0;
		uint8_t TopTog = 0;
		uint8_t LEDButton = 0;
		uint8_t LeftBoxTog = 0;
		uint8_t RightBoxTog = 0;
		uint8_t FlightStick = 0;
	};

	ConsoleReceivedData_Type ConsoleReceivedData;

	uint8_t CylinderCode[15] = {};

	struct LedData
	{
		uint8_t r = 0, g = 0, b = 0;

		void Clear()
		{
			r = 0;
			g = 0;
			b = 0;
		}
	};

	struct ConsoleReceivedDataType
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

	struct ConsoleSendDataType
	{
		LedData LED[50] = {};
		bool BLED[50] = {};
		bool ContolButtons[4] = {};
		bool FlightStick = false;
		LedData OnColor = {};
		LedData OffColor = {};
	};

	//ConsoleReceivedDataType ConsoleData;
	ConsoleSendDataType ConsoleDataSend;

	//ConsoleReceivedDataType LastConsoleData;
	ConsoleSendDataType LastConsoleDataSend;

	unordered_set<int> ConsolePressed;
	uint8_t ConsolePotValue[4];

	//unordered_set<int> ConsoleKeyProcessed;
	unordered_set<int> ConsoleKeyPressed;

	bool InputDown(Typeof_ConsoleInputs key);
	bool InputPressed(Typeof_ConsoleInputs key, bool remove = true);
	void addToSet(unordered_set<int> &itemset, Typeof_ConsoleInputs item, bool pressed);
	void ConsolePressButton(Typeof_ConsoleInputs item);

private:
	SWSimulation *SWS;
	vector<SerialConnection> _panel;	
};

#endif // VTSERIAL_H
