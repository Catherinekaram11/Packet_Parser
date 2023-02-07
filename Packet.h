#include <string>
#include <map>
#pragma once
using namespace std;

//this class defines the packet with all its fields
class Packet
{
public:
	Packet();
	Packet(map <string, string> packet_info);
	string get_packet_id();
	string get_packet_content();
	string get_destination_address_field();
	string get_source_address_field();
	string get_type_field();
	string get_data_field();
	string get_CRC_field();

private:
	//packet fields
	string packet_id;
	string packet_content;
	string destination_address_field, source_address_field,
		type_field, data_field, CRC_field;
};

