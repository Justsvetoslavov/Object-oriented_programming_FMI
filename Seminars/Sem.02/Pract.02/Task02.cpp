#include <iostream>
#include <fstream>

using namespace std;

const char* FILE_PATH = "C:\\Users\\grade\\Desktop\\result.txt";

int lengthOfFile(void)
{
    int totalLen = 0;

    ifstream fileReader(FILE_PATH);

    char c;
    while (fileReader.is_open() && !fileReader.eof())
    {
        fileReader >> c;
        totalLen++;
    }
    fileReader.close();

    return totalLen;
}

int main()
{
    cout << lengthOfFile();

    return 0;
}