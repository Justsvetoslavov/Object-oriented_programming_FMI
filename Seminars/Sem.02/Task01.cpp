#include <iostream>
#include <fstream>

int main()
{
    const char FILE_NAME[] = "result.txt";

    double x = 0;
    double y = 0;
    double z = 0;

    std::cin >> x >> y >> z;

    if (std::cin.fail())
    {
        return 1;
    }

    std::ofstream file(FILE_NAME);

    if (!file.is_open())
    {
        return 1;
    }

    file << x * y * z << std::endl;

    file.close();

    return 0;
}