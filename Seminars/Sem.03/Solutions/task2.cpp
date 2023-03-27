#include <iostream>
#include <fstream>
#include <cstring>

size_t GetFileSize(std::ifstream& file) {
	size_t currentPosition = file.tellg();
	file.seekg(0, std::ios::end);
	size_t result = file.tellg();
	file.seekg(currentPosition);
	return result;
}

int main() {
	std::ifstream file("test.txt");
	
	if(!file.is_open()) {
		std::cout << "Error while opening the file!" << std::endl;
		return 1;
	}
		
	std::cout << GetFileSize(file) << " bytes" << std::endl;
	
	return 0;
}
