#ifndef VTNETWORK_H
#define VTNETWORK_H

#include "SDL.h"
#include "SDL_net.h"
#include "SWSimulation.h"

class VTNetwork
{
public:
	VTNetwork();
	~VTNetwork();

	void init_Network();
	
	void update_Network(SWSimulation SWS);

private:
IPaddress ip;
TCPsocket server = NULL;
TCPsocket client = NULL;
SDLNet_SocketSet socket_set;

};

#endif // VTNETWORK_H
