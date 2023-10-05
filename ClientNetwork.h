#pragma once
// Networking libraries
#define NOMINMAX
#include <ws2tcpip.h>
#include <winsock2.h>
#include <Windows.h>

// size of our buffer
#define DEFAULT_BUFLEN 512
// port to connect sockets through 
#define OUT_PORT "12346"
#define LISTEN_PORT "12345"
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class ClientNetwork
{

public:
	int receivePackets(char*);
	// for error checking function calls in Winsock library
	int iResult;

	// socket for client to connect to server
	SOCKET ConnectSocket;

	// ctor/dtor
	ClientNetwork(void);
	~ClientNetwork(void);
};