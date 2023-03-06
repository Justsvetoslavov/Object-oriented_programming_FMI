﻿#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const int MAX_SIZE = 1000000;

int main()
{
    ofstream printFile("file_Task06.txt");
    ifstream myFile("Task06.cpp");
    if (!myFile.is_open())
    {
        cout << "Error";
        return -1;
    }
    char bufer[1024];
    while (true)
    {
    if (myFile.eof())
        break;
    myFile.getline(bufer, 1024);
   
    printFile << bufer;
    printFile << endl;
    cout << bufer << endl;
        }
    return 0;
}

