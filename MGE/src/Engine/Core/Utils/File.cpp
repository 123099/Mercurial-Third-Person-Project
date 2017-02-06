#include "File.hpp"
#include <fstream>
#include <iostream>

std::string File::GetContents(const std::string & fileName)
{
	//Open the specified file
	std::ifstream file;
	file.open(fileName.c_str());

	std::string output;
	std::string line;

	//Check that the file opened successfully
	if (file.is_open())
	{
		//As long as the stream has data to read from
		while (file.good())
		{
			//Get the next line from the file
			getline(file, line);
			//Add it to the output
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to open file: " << fileName << '\n';
	}

	return output;
}
