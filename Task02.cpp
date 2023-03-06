#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int lengthOfFile(ifstream& myFile)
{
    int counter = 0;
    while (!myFile.eof())
    {
        char buff[100000];
        myFile.getline(buff, 100000);
        int i = 0;
        while (buff[i] != '\0')
        {
            counter++;
            i++;
        }
    }
    return counter;
}

int main()
{
    ifstream myFile("file.txt");
    if (!myFile.is_open())
    {
        cout << "Error";
        return -1;
    }
    cout << lengthOfFile(myFile);
    myFile.close();
}

