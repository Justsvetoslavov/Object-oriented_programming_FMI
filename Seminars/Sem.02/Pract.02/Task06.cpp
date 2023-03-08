﻿#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const int MAX_SIZE = 1024;

int main()
{
    ofstream printFile("file_Task06.txt");
    ifstream myFile("Task06.cpp");
    if (!myFile.is_open())
    {
        cout << "Error";
        return -1;
    }
    char bufer[MAX_SIZE];
    while (!myFile.eof())
    {
    myFile.getline(bufer, MAX_SIZE);
    printFile << bufer << endl;
    cout << bufer << endl;
    }
    return 0;
}