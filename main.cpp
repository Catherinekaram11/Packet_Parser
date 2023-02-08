#include "File.h"
#include "Packet.h"
#include "eCPRIPacket.h"
#include "PacketParser.h"

int main()
{
	File file("input_packets", "output_packets");
	file.read_input_file();
	file.write_output_file();
}