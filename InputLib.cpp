#include "InputLibHeader.h"

std::tuple<int,int, std::vector<float>>	file_input(std::string &path)
{
	std::ifstream fin(path);
	int x_size, y_size;
	float current_value;
	std::stringstream ss; 
	std::string line;
	std::vector<float> input_values;
	while (!fin.eof())
	{
		std::getline(fin,line);
		ss << line;
		while (ss >> current_value)
		{
			input_values.push_back(current_value);
		}
		ss.clear();
	}
	fin.close();
	ss.clear();
	y_size = input_values[0];
	x_size = input_values[1];
	input_values.erase(input_values.begin());
	input_values.erase(input_values.begin());
	return std::make_tuple(y_size,x_size,input_values);
}
