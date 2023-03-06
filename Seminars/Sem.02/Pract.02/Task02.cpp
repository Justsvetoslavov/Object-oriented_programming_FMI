#include <iostream>
#include <fstream>

int lengthOfFile(const char* name) {
	std::ifstream file(name);

	if (!file.is_open()) {
		std::cout << "ERROR!" << std::endl;
		return -1;
	}

	file.seekg(0, std::ios::end);
	int position = file.tellg();
	file.close();

	return position;
}