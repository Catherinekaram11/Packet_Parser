#include "Packet.h"
#pragma once
class eCPRIPacket : public Packet
{
public:
	eCPRIPacket();
	eCPRIPacket(map <string , string> packet_info, map<string, string> eCPRI_packet_info);
	string get_concatentaion_indicator_field();
	string get_message_type_field();
	string get_payload_size_field();
	string get_protocol_version_field();
	string get_RTC_ID_field();
	string get_sequence_ID_field();
	string get_packet_data();
private:
	string concatentaion_indicator_field, message_type_field, payload_size_field,
		protocol_version_field, RTC_ID_field, sequence_ID_field;
};

