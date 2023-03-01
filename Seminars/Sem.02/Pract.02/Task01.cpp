#include <fstream>
#include <iostream>

void printFromFile()
{
    std::ifstream file("results.txt");
    if (!file.is_open())
        return;

    int product, sum;
    file >> sum;
    file >> product;

    std::cout << (sum - product);
}

int main()
{
    int a, b, c;

    std::cin >> a >> b >> c;

    std::ofstream file("results.txt");
    if (!file.is_open())
        return -1;

    file << (a + b + c) << std::endl << (a * b * c);

    file.close();

    printFromFile();

    return 0;
}