#include <iostream>
#include <fstream>

const char FILE_NAME[] = "results.txt";

bool WriteSumAndProductToFile(int num1, int num2, int num3)
{
    std::ofstream file(FILE_NAME);

    if (!file.is_open()) {
        return false;
    }

    file << num1 + num2 + num3 << " " << num1 * num2 * num3 << "\n";
    file.close();
	return true;
}

bool ReadSumAndProductFromFile()
{
    std::ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return false;
    }

    int sum, product;
    file >> sum >> product;
    std::cout << sum - product << std::endl;
    
    file.close();
	return true;
}

int main()
{
    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;

    WriteSumAndProductToFile(num1, num2, num3);
    ReadSumAndProductFromFile();
}