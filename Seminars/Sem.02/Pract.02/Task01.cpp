#include <iostream>
#include <fstream>

const int MAX_SIZE = 1024;

int main() {
	double a, b, c;
	std::cin >> a >> b >> c;

	double sum = a + b + c;
	double product = a * b * c;

	double diff = sum - product;
	std::cout << diff;

	std::ofstream file("result.txt");

	if (!file.is_open()) {
		std::cout << "ERROR!" << std::endl;
		return -1;
	}

	file << "sum = " << sum << " ; product = " << product;

	file.close();
	
}