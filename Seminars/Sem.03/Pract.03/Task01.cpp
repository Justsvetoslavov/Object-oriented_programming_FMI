#include <iostream>
#include <fstream>

using namespace std;

char ifpath[] = "C:\\Users\\boris\\OneDrive\\Desktop\\inFile.csv";
char ofpath[] = "C:\\Users\\boris\\OneDrive\\Desktop\\outFile.csv";

const int MAX_SIZE = 256;

enum Hair
{
    Brown, Black, Blond, Red, White
};

struct Student
{
    char name[2][17];
    unsigned short fn;
    float avgGrade;
    Hair hair;
};

Student muchenitsi[1024];

void writeStudent(Student& student, int index)
{
    if (index < 1024)
        muchenitsi[index] = student;
}

void writeToFile()
{
    ofstream streamWriter(ofpath);

    for (int i = 0; i < 1024 && streamWriter.is_open() && muchenitsi[i].fn != 0; ++i)
    {
        streamWriter << muchenitsi[i].name[0]  << ','
                     << muchenitsi[i].name[1]  << ','
                     << muchenitsi[i].fn       << ','
                     << muchenitsi[i].avgGrade << ','
                     << muchenitsi[i].hair;
    }

    streamWriter.close();
}

void readFromFile()
{
    ifstream streamReader(ifpath);

    int index = 0;
    while (streamReader.is_open() && !streamReader.eof())
    {
        int temp;
        char tempChar;
        streamReader.getline(muchenitsi[index].name[0], 16, ',');
        streamReader.getline(muchenitsi[index].name[1], 16, ',');
        streamReader >> muchenitsi[index].fn;
        tempChar = streamReader.get();
        streamReader >> muchenitsi[index].avgGrade;
        tempChar = streamReader.get();
        streamReader >> temp;
        muchenitsi[index++].hair = (Hair)temp;
    }

    streamReader.close();
}

int main()
{
    readFromFile();

    int i = 0;
    while (muchenitsi[i].fn != 0)
    {
        cout << muchenitsi[i].name[0]  << ','
             << muchenitsi[i].name[1]  << ','
             << muchenitsi[i].fn       << ','
             << muchenitsi[i].avgGrade << ','
             << muchenitsi[i].hair;
        i++;
    }

    writeToFile();

    return 0;
}