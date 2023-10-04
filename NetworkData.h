#include <string.h>

#define MAX_PACKET_SIZE 1000000
#define IP_ADDRESS_BUFFER_LENGTH_C_STR 10
#define IP_ADDRESS_BUFFER_LENGTH_STR 9
#define PORT_MINE 12345


enum PacketTypes {

	INIT_CONNECTION = 0,

	ACTION_EVENT = 1,

};



struct Packet {

	unsigned int packet_type;

	void serialize(char* data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char* data) {
		memcpy(this, data, sizeof(Packet));
	}
};