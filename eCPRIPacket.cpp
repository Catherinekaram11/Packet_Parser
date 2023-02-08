#include "eCPRIPacket.h"

eCPRIPacket::eCPRIPacket()
{
}

eCPRIPacket::eCPRIPacket(map<string, string> packet_info, map<string, string> eCPRI_packet_info) : Packet(packet_info)
{
	this->concatentaion_indicator_field = eCPRI_packet_info.find("concatentaion_indicator_field")->second;
	this->message_type_field = eCPRI_packet_info.find("message_type_field")->second;
	this->payload_size_field = eCPRI_packet_info.find("payload_size_field")->second;
	this->protocol_version_field = eCPRI_packet_info.find("protocol_version_field")->second;
	this->RTC_ID_field = eCPRI_packet_info.find("RTC_ID_field")->second;
	this->sequence_ID_field = eCPRI_packet_info.find("sequence_ID_field")->second;
}

string eCPRIPacket::get_concatentaion_indicator_field()
{
	return concatentaion_indicator_field;
}

string eCPRIPacket::get_message_type_field()
{
	return message_type_field;
}

string eCPRIPacket::get_payload_size_field()
{
	return payload_size_field;
}

string eCPRIPacket::get_protocol_version_field()
{
	return protocol_version_field;
}

string eCPRIPacket::get_RTC_ID_field()
{
	return RTC_ID_field;
}

string eCPRIPacket::get_sequence_ID_field()
{
	return sequence_ID_field;
}

string eCPRIPacket::get_packet_data()
{
	return "Packet # " + get_packet_id() + ":\n" +
		   get_packet_content() + "\n" +
		   "CRC: " + get_CRC_field() + "\n" +
		   "Concatenation Indicator: " + get_concatentaion_indicator_field() + "\n" +
		   "Destination Address: " + get_destination_address_field() + "\n" +
		   "Message Type: " + get_message_type_field() + "\n" +
		   "Payload Size: " + get_payload_size_field() + "\n" +
		   "Protocol Version: " + get_protocol_version_field() + "\n" +
		   "RTC ID: " + get_RTC_ID_field() + "\n" +
		   "Sequence ID: " + get_sequence_ID_field() + "\n" +
		   "Source Address: " + get_source_address_field() + "\n" +
		   "Type: " + get_type_field() + "\n";
}
