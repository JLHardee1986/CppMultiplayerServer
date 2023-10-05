// may need #include "stdafx.h" in visual studio
#include "pch.h"

// used for multi-threading
#include <process.h>

void serverLoop(void*);
void clientLoop(void);

ServerGame* server;
ClientGame* client;

Game* game{ nullptr };

int main(int argc, char* argv[])
{

	client = new ClientGame();


	// initialize the server
	server = new ServerGame();

	// bound socket managed on this program, the server-side,
	// should have the client loop connect to this first on the other side
	// then have the client bind their socket for incoming an then we bind to that socket from here
		// initialize the client
	

	game = new Game();

	// create thread with arbitrary argument for the run function
	_beginthread(serverLoop, 0, (void*)12);
	
	clientLoop();

	delete game;

	return 0;
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
	while (game->m_wnd->isOpen())
	{
		
		game->handle_Input();
		game->handle_Events();
		game->update_GameFrame();
		game->draw_GameFrame();	   

		client->update();
	}
}