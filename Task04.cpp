#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const char FILE_NAME[] = "file_Task04.txt";
const int MAX_SIZE = 25;

struct Pair {
    int a;
    int b;
};

void InitPair(Pair& pair)
{
    cout << "First number: ";
    cin >> pair.a;
    cout << "Second number: ";
    cin >> pair.b;
}

Pair CreatePair()
{
    Pair pair;
    InitPair(pair);
    return pair;
}

struct Relation {
    Pair pairs[MAX_SIZE];
    unsigned int count = 0;
};

void WritePairToFile(Pair& pair, ofstream& writeFile)
{
    if (!writeFile.is_open())
    {
        cout << "Error";
        return;
    }
    writeFile << "<" << pair.a << "," << pair.b << ">" << endl;
}

void ReadPairFromFile(Pair& pair, ifstream& readFile)
{
    if (!readFile.is_open())
    {
        cout << "Error";
        return;
    }
    readFile >> pair.a;
    readFile >> pair.b;
    cout << "<" << pair.a << "," << pair.b << ">" << endl;
}

void AddPairToRelation(Relation& relation)
{
    if (relation.count < MAX_SIZE)
    {
        cout << "Pair " << relation.count + 1 << ":";
        relation.pairs[relation.count] = CreatePair();
        relation.count++;
    }
}

void WriteRelationToFile(Relation& relation, const char* fileName)
{
    ofstream writeFile(fileName);
    if (!writeFile.is_open())
    {
        cout << "Error";
        return;
    }
    for (size_t i = 0; i < relation.count; i++)
    {
        writeFile << "Pair" << i + 1 << ": ";
        WritePairToFile(relation.pairs[i], writeFile);
    }
    writeFile.close();
}

void ReadRelationFromFile(Relation& relation, const char* fileName)
{
    ifstream readFile(fileName);
    if (!readFile.is_open())
    {
        cout << "Error";
        return;
    }
    for (size_t i = 0; i < relation.count; i++)
    {
        cout << "Pair" << i + 1 << ": ";
        ReadPairFromFile(relation.pairs[i], readFile);
    }
    readFile.close();
}

int main()
{
    Relation relation;
    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
    AddPairToRelation(relation);
    }
    WriteRelationToFile(relation, FILE_NAME);
    ReadRelationFromFile(relation, FILE_NAME);
}

