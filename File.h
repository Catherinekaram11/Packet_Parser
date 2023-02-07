#include <fstream>
#include <string>
#include <vector>
using namespace std;
#pragma once	

class File
{
public:
	void read_file(string input_file_name);
	vector<string> get_packet_lines();


private:
	vector<string> packet_lines;
};

