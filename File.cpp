#include "File.h"
#include "PacketParser.h"

File::File()
{
	input_file_name = " ";
	output_file_name = " ";
}
File::File(string input_file_name, string output_file_name)
{
	this->input_file_name = input_file_name;
	this->output_file_name = output_file_name;
}
vector<string> File::get_packet_lines()
{
	return packet_lines;
}
void File::read_input_file()
{
	fstream input_file;
	input_file.open(input_file_name, ios::in);
	if (input_file.is_open())
	{
		string packet_content;
		while (getline(input_file, packet_content))
		{
			if (packet_content != "")
			{
				packet_lines.push_back(packet_content);
			}
		}
	}
	input_file.close();
}
void File::write_output_file()
{
	fstream output_file;
	output_file.open(output_file_name, ios::out);
	if (output_file.is_open())
	{
		PacketParser parser;
		for (int i = 0; i < packet_lines.size(); i++)
		{
			output_file << parser.call_parser(i, packet_lines[i]);
			output_file << "\n";
			output_file << setfill('*') << setw(230) << "\n";
			output_file << "\n";
		}
	}
	output_file.close();
}
