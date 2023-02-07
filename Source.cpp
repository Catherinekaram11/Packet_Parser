#include "Packet.h"
#include "eCPRIPacket.h"
#include "PacketParser.h"

int main()
{
	map <string, string> map1;
	map1["packet_id"] = "1";
	map1["destination_address_field"] = "55";
	map1["packet_content"] = "kfkfkf";
	map1["source_address_field"] = "kfkfk";
	map1["type_field"] = "jfjjfjfff";
	map1["CRC_field"] = "hfhhff";
	map1["data_field"] = "fjjfjf";

	map <string, string> map2;
	map2["concatentaion_indicator_field"] = "hddhd";
	map2["payload_size_field"] = "dhdhhhdd";
	map2["message_type_field"] = "ueuueue";
	map2["protocol_version_field"] = "hfhfhfh";
	
	map2["RTC_ID_field"] = "hhfhfhfhf";
	int x = 1;
	map2["sequence_ID_field"] =to_string(x);


	eCPRIPacket fffff(map1, map2);
	PacketParser parser;
	map<string, string> mapppp = parser.parse_packet_input(5 , "FB555555555555D50000000000C1ECCD655507D9AEFE1002001480680080900000000101D10000100000FFFE7E0400000000000000000000000000000000000000000000B329AA60");
	Packet nn;
	nn.create_packet(mapppp);



}