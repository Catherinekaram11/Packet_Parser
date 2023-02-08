#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#pragma once
using namespace std;

class File
{
public:
	File();
	File(string input_file_name, string output_file_name);
	vector<string> get_packet_lines();
	void read_input_file();
	void write_output_file();

private:
	string input_file_name, output_file_name;
	vector<string> packet_lines;
};
