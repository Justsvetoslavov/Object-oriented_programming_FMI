#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;

// the name should be the same as the current cpp!
const char FILE_NAME[] = "test.cpp";

void printSourceCode() {
	std::ifstream in(FILE_NAME);

	if (!in.is_open()) {
		std::cout << "Error";
		return;
	}

	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		std::cout << buffer;
	}

	in.close();
}

int main() {
	// ...
}