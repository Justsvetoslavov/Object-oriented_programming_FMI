#include <iostream>
#include <fstream>

const char DEFAULT_FILE_NAME[] = "result.txt";

void writeSumAndProductToFile(const char fileName[]) {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::ofstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error\n";
		return;
	}

	int sum = a + b + c;
	int product = a * b * c;

	file << sum << " ";
	file << product << "\n";

	file.close();
}

int findSumAndProductDiff(const char fileName[]) {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error\n";
		return -1;
	}

	int sum, product;
	file >> sum;

	//Skip the whitespace 
	file.get();

	file >> product;

	return sum - product;
}

int main()
{
	writeSumAndProductToFile(DEFAULT_FILE_NAME);
	std::cout << "Sum - product = " << findSumAndProductDiff(DEFAULT_FILE_NAME);
}
