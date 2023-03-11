#include <iostream>
#include <fstream>

size_t getFileSize(const char* name)
{
	std::ifstream myfile(name);
	if (!myfile.is_open())
    {
        return -1;
    }

	size_t currentPos = myfile.tellg();
	myfile.seekg(0, std::ios::end);
	size_t sizeFile = myfile.tellg();
	myfile.seekg(currentPos);

	myfile.close();

	return sizeFile-1;
}

int main()
{
    std:: cout << "The size of the file is: " << getFileSize("result.txt") << std:: endl;
	
    return 0;
}