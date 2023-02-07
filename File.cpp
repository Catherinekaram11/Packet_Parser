#include "File.h"


void File::read_file(string input_file_name)
{
	fstream input_file;
	input_file.open(input_file_name, ios::in);
	if (input_file.is_open())
	{
		string packet_content;
		while (getline(input_file, packet_content))
		{
			packet_lines.push_back(packet_content);
		}
	}

}

vector<string> File::get_packet_lines()
{
	return packet_lines;
}
