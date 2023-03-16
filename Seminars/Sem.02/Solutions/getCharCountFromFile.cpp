#include <iostream>
#include <fstream>

size_t GetCharCountFromFile(std::ifstream& ifs, const char ch)
{
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open()) {
		return 0;
    }

	size_t count = 0;
	while (!ifs.eof())
	{
		char current = ifs.get();
		if (current == ch) {
			count++;
        }
	}

	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}