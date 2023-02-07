#include "eCPRIPacket.h"

eCPRIPacket::eCPRIPacket(map<string, string> packet_info , map<string, string> eCPRI_packet_info) : Packet(packet_info)
{
	this->concatentaion_indicator_field = eCPRI_packet_info.find("concatentaion_indicator_field")->second;
	this->message_type_field = eCPRI_packet_info.find("message_type_field")->second;
	this->payload_size_field = eCPRI_packet_info.find("payload_size_field")->second;
	this->protocol_version_field = eCPRI_packet_info.find("protocol_version_field")->second;
	this->RTC_ID_field = eCPRI_packet_info.find("RTC_ID_field")->second;
	this->sequence_ID_field = eCPRI_packet_info.find("sequence_ID_field")->second;
}
