#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;

void copyFileContent(const char from[], const char to[]) {
	std::ifstream in(from);
	std::ofstream out(to);

	if (!in.is_open() || !out.is_open()) {
		std::cout << "Error";
		return;
	}

	while (!in.eof()) {
		char buffer[BUFFER_SIZE];
		in.getline(buffer, BUFFER_SIZE);
		out << buffer;
	}

	in.close();
	out.close();
}

int main() {
	// ...
}