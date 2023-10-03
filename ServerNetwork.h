#pragma once
#include <map>


class ServerNetwork
{

public:

	// receive incoming data
	int receiveData(unsigned int client_id, char* recvbuf);
	// send data to all clients
	void sendToAll(char* packets, int totalSize);
	bool acceptNewClient(unsigned int& id);

	ServerNetwork(void);
	~ServerNetwork(void);

	// Socket to listen for new connections
	SOCKET ListenSocket;

	// Socket to give to the clients
	SOCKET ClientSocket;

	// for error checking return values
	int iResult;

	// table to keep track of each client's socket
	std::map<unsigned int, SOCKET> sessions;
};