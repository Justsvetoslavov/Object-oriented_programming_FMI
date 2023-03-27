#include <iostream>
#include <fstream>

size_t GetFileSize(std::ifstream& file) {
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

int main()
{
	std::ifstream ifs("myfile.dat", std::ios::in | std::ios::binary);
	
	if(!ifs.is_open()) {
		return 1;
    }
	
	size_t fileSize = GetFileSize(ifs);
	size_t arrSize = fileSize / sizeof(int);
	int* arr = new int[arrSize];

	ifs.read((char*)arr, fileSize);

	for (size_t i = 0; i < arrSize; ++i) {
		std::cout << arr[i] << " ";
    }

	delete[] arr;
	ifs.close();
}