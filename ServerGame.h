#pragma once

#include "ServerNetwork.h"

class ServerGame
{
	// IDs for the clients connecting for table in ServerNetwork 
	static unsigned int client_id;

	// The ServerNetwork obj
	ServerNetwork* network;

	char network_data[MAX_PACKET_SIZE];

public:




	void receiveFromClients();

	ServerGame(void);
	~ServerGame(void);

	void update();
	void sendActionPackets();


private:

};