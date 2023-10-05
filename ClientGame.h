#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "ClientNetwork.h"

class Game;

class ClientGame
{
	
public:

	ClientGame();
	~ClientGame(void);

	void sendActionPackets();

	char network_data[MAX_PACKET_SIZE];

	void update();

	ClientNetwork* network;
};