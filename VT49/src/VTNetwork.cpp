#include "VTNetwork.h"
#include "SDL.h"
#include "SDL_net.h"
#include <stdio.h>

VTNetwork::VTNetwork() {

}

VTNetwork::~VTNetwork() {
	SDLNet_Quit();
}

void VTNetwork::init_Network() {

	if(SDLNet_Init() == -1) {
		printf("Network Error!: %s\n", SDL_GetError());
		exit(-1);
	}

	if(SDLNet_ResolveHost(&ip, NULL, 4949) == -1) {
		printf("Network Error!: %s\n", SDL_GetError());
		exit(-1);
	}

	server = SDLNet_TCP_Open(&ip);


}

void VTNetwork::update_Network(SWSimulation SWS) {
	int floatsize = sizeof(float);
	uint8_t data[floatsize * 3];

	if(server) {
		if(client == NULL)
			client = SDLNet_TCP_Accept(server);

		if(client) {
			unsigned char const * x = reinterpret_cast<unsigned char const *>(&SWS.Ship->x);
			unsigned char const * y = reinterpret_cast<unsigned char const *>(&SWS.Ship->y);
			unsigned char const * z = reinterpret_cast<unsigned char const *>(&SWS.Ship->z);

			for(std::size_t i = 0; i != sizeof(float); ++i) {
				data[i + floatsize * 0] = x[i];
				data[i + floatsize * 1] = y[i];
				data[i + floatsize * 2] = z[i];
			}
			if(SDLNet_TCP_Send(client, data, floatsize * 3) < floatsize * 3)
				client = NULL;
		}
	}

}
