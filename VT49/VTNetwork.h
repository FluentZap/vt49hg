#ifndef VTNETWORK_H
#define VTNETWORK_H

#include "SDL.h"
#include "SDL_net.h"

class VTNetwork
{
public:
	VTNetwork();
	~VTNetwork();

	void init_Network();

private:
IPaddress ip;
TCPsocket tcpsock;


};

#endif // VTNETWORK_H
