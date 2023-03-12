#include <iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

void printCode(const char* name) {
	std::ifstream file(name);
	if (!file.is_open()) {
		cout << "Error";
		return;
	}
	while (!file.eof()) {
		char buff [1024];
		file.getline(buff, 1024);
		cout << buff << endl;

	}

	file.close();

}

int main() {
	printCode("Task 06.cpp");

}
