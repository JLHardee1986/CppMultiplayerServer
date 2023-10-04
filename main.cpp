// may need #include "stdafx.h" in visual studio
#include "pch.h"

// used for multi-threading
#include <process.h>

void serverLoop(void*);
void clientLoop(void);

ServerGame* server;
ClientGame* client;

int main()
{

	// initialize the server
	server = new ServerGame();

	// bound socket managed on this program, the server-side,
	// should have the client loop connect to this first on the other side
	// then have the client bind their socket for incoming an then we bind to that socket from here
		// initialize the client
	client = new ClientGame();

	// create thread with arbitrary argument for the run function
	_beginthread(serverLoop, 0, (void*)12);
	

	clientLoop();
}

void serverLoop(void* arg)
{
	while (true)
	{
		server->update();
	}
}

void clientLoop()
{
	while (true)
	{
		//do game stuff
	   //will later run client->update();
		client->update();
	}
}