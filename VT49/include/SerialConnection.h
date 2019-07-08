#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H
#include <stdio.h>
#include <stdint.h>
#include <rs232.h>
#include <unordered_set>
#include "COBS.h"
#include <vector>

using namespace std;

enum ListOf_DeviceTypes
{
	Console,
	ConsoleAnalog,
	FullPanel,
	FullPanelAnalog
};

class SerialConnection
{
public:
	SerialConnection(int port, ListOf_DeviceTypes type, size_t packetSize = 16, uint8_t marker = 0, size_t bufferSize = 256);
	~SerialConnection();
	uint8_t Marker;
	size_t BufferSize;
	size_t PacketSize;
	int Port;
	ListOf_DeviceTypes Type;
	int BufferIndex = 0;
	uint8_t Buffer[];
	void Send(const vector<uint8_t> data);
	vector<uint8_t> ReadAvailable();
};

#endif // SERIALCONNECTION_H