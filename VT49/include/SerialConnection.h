#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H
#include <stdio.h>
#include <stdint.h>

using namespace std;

class SerialConnection
{
public:
	SerialConnection();
	~SerialConnection();
//	const uint8_t Marker = 0;
//	const size_t BufferSize = 256;
//	const int Port;
//
//	int BufferIndex{0};
//	uint8_t Buffer[];
//	static Read(uint8_t*);
//	static Send(const uint8_t* Buffer, size_t Size);
};

#endif // SERIALCONNECTION_H