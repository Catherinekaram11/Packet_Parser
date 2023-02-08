#include "Packet.h"
#include "eCPRIPacket.h"
#include <vector>
#pragma once
using namespace std;

//macro for constants
#define DESTINATION_ADDRESS_START 8
#define DESTINATION_ADDRESS_LENGTH 6
#define SOURCE_ADDRESS_START 14
#define SOURCE_ADDRESS_LENGTH 6
#define TYPE_START 20
#define TYPE_LENGTH 2
#define CRC_LENGTH 4
#define DATA_START 22
#define TOTAL_LENGTH_WITHOUT_DATA 26
#define BYTE_IN_HEXA 2 
#define PROTOCOL_VERSION_START 0
#define PROTOCOL_VERSION_LENGTH 1
#define CONCATENTAION_INDICATOR_START 1
#define CONCATENTAION_INDICATOR_LENGTH 1
#define MESSAGE_TYPE_START 2
#define MESSAGE_TYPE_LENGTH 2
#define PAYLOAD_SIZE_START 4
#define PAYLOAD_SIZE_LENGTH 4
#define RTC_ID_START 8
#define RTC_ID_LENGTH 4
#define SEQUENCE_ID_START 12
#define SEQUENCE_ID_LENGTH 4

class PacketParser
{
public:
	//calls parser for each line of file 
	string call_parser(int packet_line_number, string packet_line);
	//parse individual lines into packet info
	map<string, string> parse_packet_input (int packet_line_number, string input_packet);
	map <string, string> parse_packet_data(string input_packet_data_field);
	//create output string for each packet
	string parse_output_packet(map<string, string> packet_info);
};

