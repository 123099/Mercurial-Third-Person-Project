#include "StringUtils.hpp"
#include <sstream>

std::vector<std::string> StringUtils::Split(const std::string & str, const char delimiter)
{
	//Create a vector to store the separated tokens
	std::vector<std::string> splitString;

	//Create a string stream from which to read the words
	std::stringstream stream(str);

	//Create a variable to store each word
	std::string word;

	//As long as there are more words to read, keep reading
	while (std::getline(stream, word, delimiter))
	{
		//If the word returned wasn't an empty string, add it to the vector
		if (word.empty() == false)
		{
			splitString.push_back(word);
		}
	}

	//If no words were found according to the delimiter, return the original string
	if (splitString.size() == 0)
	{
		splitString.push_back(str);
	}

	return splitString;
}
