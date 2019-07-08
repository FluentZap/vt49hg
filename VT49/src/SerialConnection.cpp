#include "SerialConnection.h"

SerialConnection::SerialConnection(
    int port,
    ListOf_DeviceTypes type,
    size_t packetSize, uint8_t marker, size_t bufferSize)
{
    Port = port;
    Type = type;
    PacketSize = packetSize;
    Marker = marker;
    BufferSize = bufferSize;
}

SerialConnection::~SerialConnection()
{
}

vector<uint8_t> SerialConnection::ReadAvailable()
{
    int received = 0;
    do
    {
        uint8_t data[255] = {};
        received = RS232_PollComport(Port, data, 256);
        for (int i = 0; i < received; i++)
        {
            if (data[i] == Marker)
            {
                vector<uint8_t> DecodeBuffer (BufferIndex);
                size_t numDecoded = COBS::decode(Buffer, BufferIndex, &DecodeBuffer[0]);
                if (numDecoded == PacketSize)
                {
                    //Handle Good Packet
                    return DecodeBuffer;
                    BufferIndex = 0;
                }
                else
                    BufferIndex = 0;
            }
            else
            {
                //May need to change to packet size
                if ((BufferIndex + 1) < BufferSize)
                {
                    Buffer[BufferIndex++] = data[i];
                }
                else
                {
                    BufferIndex = 0;
                }
            }
        }
    } while (received > 0);
    vector<uint8_t> empty;
    return empty;
}
