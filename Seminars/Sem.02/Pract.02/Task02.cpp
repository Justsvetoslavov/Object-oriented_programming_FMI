#include <iostream>
#include <fstream>
using std::cin;
using std::cout; 
using std::endl;
using std::ifstream;
using std::ofstream; 
using std::fstream;

const char* FILE_NAME = "length.txt";

int lenghtOfFIle(fstream &file)
{
    int count = 0;
    char c;
    while(!file.eof())
    {
        file >> c;
        count++;
    }
    return count;
}

int main()
{
    fstream file(FILE_NAME);
    if(!file.is_open())
    {
        cout << "Error!!";
    }
    int lenght = lenghtOfFIle(file);
    cout << lenght;
    file.close();
    return 0;
}