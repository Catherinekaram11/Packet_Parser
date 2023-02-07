#include "Packet.h"
#include "PacketParser.h"
Packet::Packet()
{
}

Packet::Packet(map<string, string> packet_info)
{
	this->packet_id = packet_info.find("packet_id")->second;
	this->packet_content = packet_info.find("packet_content")->second;
	this->destination_address_field = packet_info.find("destination_address_field")->second;
	this->source_address_field = packet_info.find("source_address_field")->second;
	this->type_field = packet_info.find("type_field")->second;
	this->data_field = packet_info.find("data_field")->second;
	this->CRC_field = packet_info.find("CRC_field")->second;
}


string Packet::get_packet_id()
{
	return this->packet_id;
}

string Packet::get_packet_content()
{
	return this->packet_content;
}

string Packet::get_destination_address_field()
{
	return this->destination_address_field;
}

string Packet::get_source_address_field()
{
	return this->source_address_field;
}

string Packet::get_type_field()
{
	return this->type_field;
}

string Packet::get_data_field()
{
	return this->data_field;
}

string Packet::get_CRC_field()
{
	return this->CRC_field;
}



