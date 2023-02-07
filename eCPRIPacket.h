#include "Packet.h"
<<<<<<< HEAD
#pragma once
=======
>>>>>>> 33277d3b66368d8f82dd85506193f29c255317a9
class eCPRIPacket : Packet
{
public:
	eCPRIPacket(map <string , string> packet_info, map<string, string> eCPRI_packet_info);

private:
	string concatentaion_indicator_field, message_type_field, payload_size_field,
		protocol_version_field, RTC_ID_field, sequence_ID_field;
};

