#include <iostream>
#include <fstream>

const char* FILE_NAME = "result.txt";

int getLengthOfStream(std::ifstream& stream)
{
	if (!stream.is_open())
	{
		return -1;
	}

	int precPos = stream.tellg();
	stream.seekg(0, std::ios::end);
	int streamLength = stream.tellg();

	stream.seekg(precPos);

	return streamLength;
}

int main()
{
	// 2
	std::ifstream myFile(FILE_NAME);

	std::cout << getLengthOfStream(myFile);
}