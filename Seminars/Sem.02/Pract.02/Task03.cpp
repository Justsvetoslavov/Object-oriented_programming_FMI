#include <iostream>
#include <fstream>
using std::cin;
using std::cout; 
using std::endl;
using std::ifstream;
using std::ofstream; 
using std::fstream;

const char* FILE_NAME = "placeholder.txt";

void inputInfo(fstream &file)
{
    char title[12];
    char recipientName[30];
    char message[255];
    char senderName[30];
    cin.getline(title, 10);
    cin.getline(recipientName, 30);
    cin.getline(message, 255);
    cin.getline(senderName, 30);
    file << "Dear," << title << " " << recipientName << "\n" << message << "\n" << "Sinceerely, \n" << senderName;
}

void printPlaceHolder(fstream &file)
{
    file.seekg(0); 
    char message[1024];
    while(!file.eof())
    {
        file.getline(message, 1024);
        cout << message << endl;
    }
}

int main()
{
    fstream file(FILE_NAME);
    if(!file.is_open())
    {
        cout << "Error";
        return -1;
    }
    inputInfo(file);
    printPlaceHolder(file);
    file.close();
    return 0;
}