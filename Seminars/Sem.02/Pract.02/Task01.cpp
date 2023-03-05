#include <iostream>
#include <fstream>

const char FILE_NAME[] = "result.txt";
const int BUFFER_SIZE = 256;

int Sum(int firstNum, int secondNum, int thirdNum) {
	return firstNum + secondNum + thirdNum;
}

int Product(int firstNum, int secondNum, int thirdNum) {
	return firstNum * secondNum * thirdNum;
}

size_t StrLen(const char* str) {
	size_t count = 0;

	while (str[count] != '\0') {
		count++;
	}
	return count;
}

int ConvertToInt(const char* str, size_t strLen) {
	size_t strIter = 0;
	int converted = 0;
	
	while (str[strIter] != '\0') {
		converted += ((str[strIter] - '0') * std::pow(10, --strLen));
		strIter++;
	}

	return converted;
}

void PrintDifference(const char* fileName) {
	std::ifstream fileToRead(fileName);

	if (!fileToRead.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	char sum[BUFFER_SIZE];
	fileToRead.getline(sum, BUFFER_SIZE);
	char product[BUFFER_SIZE];
	fileToRead.getline(product, BUFFER_SIZE);

	size_t sumLen = StrLen(sum);
	size_t productLen = StrLen(product);

	std::cout << ConvertToInt(sum, sumLen) - ConvertToInt(product, productLen);


	fileToRead.close();
}

int main()
{
	int firstNum, secondNum, thirdNum;

	std::cout << "Enter first number: ";
	std::cin >> firstNum;
	std::cout << "Enter second number: ";
	std::cin >> secondNum;
	std::cout << "Enter third number: ";
	std::cin >> thirdNum;

	std::ofstream fileToWrite(FILE_NAME);

	if (!fileToWrite.is_open()) {
		std::cout << "Error!" << std::endl;
		return -1;
	}

	fileToWrite << Sum(firstNum, secondNum, thirdNum) << std::endl;
	fileToWrite << Product(firstNum, secondNum, thirdNum);

	fileToWrite.close();

	PrintDifference(FILE_NAME);
}
