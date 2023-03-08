#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const char FILE_NAME[] = "result_Task02.txt";
const int MAX_SIZE = 1024;

int lengthOfFile(const char* fileName)
{
    ifstream readFile(fileName);
    int counter = 0;

    if (!readFile.is_open())
    {
        cout << "Error";
        return -1;
    }

    while (!readFile.eof())
    {
        char buff[100000];
        readFile.getline(buff, MAX_SIZE);
        int i = 0;
        while (buff[i] != '\0')
        {
            counter++;
            i++;
        }
    }

    readFile.close();

    return counter;
}

int main()
{
    cout << lengthOfFile(FILE_NAME);
}

