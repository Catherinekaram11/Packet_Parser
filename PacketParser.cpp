#include "PacketParser.h"

string PacketParser::call_parser(int packet_line_number, string packet_line)
{
	map<string, string> packet_info = parse_packet_input(packet_line_number, packet_line);
	return parse_output_packet(packet_info);
}

map<string, string> PacketParser::parse_packet_input(int packet_line_number, string packet_input)
{
	int line_length = packet_input.length();
	map<string, string> packet_info;
	packet_info["packet_id"] = to_string(packet_line_number);
	packet_info["packet_content"] = packet_input;
	packet_info["destination_address_field"] = packet_input.substr(DESTINATION_ADDRESS_START * BYTE_IN_HEXA, DESTINATION_ADDRESS_LENGTH * BYTE_IN_HEXA);
	packet_info["source_address_field"] = packet_input.substr(SOURCE_ADDRESS_START * BYTE_IN_HEXA, SOURCE_ADDRESS_LENGTH * BYTE_IN_HEXA);
	packet_info["type_field"] = packet_input.substr(TYPE_START * BYTE_IN_HEXA, TYPE_LENGTH * BYTE_IN_HEXA);
	packet_info["CRC_field"] = packet_input.substr(line_length - (CRC_LENGTH * BYTE_IN_HEXA), CRC_LENGTH * BYTE_IN_HEXA);
	packet_info["data_field"] = packet_input.substr(DATA_START * BYTE_IN_HEXA, line_length - (TOTAL_LENGTH_WITHOUT_DATA * BYTE_IN_HEXA));
	return packet_info;
}

map<string, string> PacketParser::parse_packet_data(string input_packet_data_field)
{
	map<string, string> eCPRI_packet_info;
	eCPRI_packet_info["concatentaion_indicator_field"] = input_packet_data_field.substr(CONCATENTAION_INDICATOR_START, CONCATENTAION_INDICATOR_LENGTH);
	eCPRI_packet_info["message_type_field"] = input_packet_data_field.substr(MESSAGE_TYPE_START, MESSAGE_TYPE_LENGTH);
	eCPRI_packet_info["payload_size_field"] = input_packet_data_field.substr(PAYLOAD_SIZE_START, PAYLOAD_SIZE_LENGTH);
	eCPRI_packet_info["protocol_version_field"] = input_packet_data_field.substr(PROTOCOL_VERSION_START, PROTOCOL_VERSION_LENGTH);
	eCPRI_packet_info["RTC_ID_field"] = input_packet_data_field.substr(RTC_ID_START, RTC_ID_LENGTH);
	eCPRI_packet_info["sequence_ID_field"] = input_packet_data_field.substr(SEQUENCE_ID_START, SEQUENCE_ID_LENGTH);
	return eCPRI_packet_info;
}

string PacketParser::parse_output_packet(map<string, string> packet_info)
{
	if (packet_info.find("type_field")->second == "AEFE")
	{
		eCPRIPacket created_packet(packet_info, parse_packet_data(packet_info.find("data_field")->second));
		return created_packet.get_packet_data();
	}
	else
	{
		Packet created_packet(packet_info);
		return created_packet.get_packet_data();
	}
}
