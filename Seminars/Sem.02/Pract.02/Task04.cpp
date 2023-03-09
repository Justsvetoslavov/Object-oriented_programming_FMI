//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>
#include <fstream>

const int MAXELEMENTS = 25;
const char FILENAME[] = "relations.txt";

struct Pair
{
    int firstNumber;
    int secondNumber;
};

struct Relation
{
    Pair pairs[MAXELEMENTS];
    int numberOfPairs;
};

Pair initPair(int firstNumber, int secondNumber)
{
    Pair newPair;
    
    newPair.firstNumber = firstNumber;
    newPair.secondNumber = secondNumber;

    return newPair;
}

Relation initRelation()
{
    Relation newRelation;

    newRelation.numberOfPairs = 0;

    return newRelation;
}

void addPairToRelation(Relation& newRelation, const Pair& newPair)
{
    if (newRelation.numberOfPairs < MAXELEMENTS)
    {
        newRelation.pairs[newRelation.numberOfPairs] = newPair;
        ++newRelation.numberOfPairs;
    }
    else
    {
        std::cout << "The relation already reached its max size!";
    }
}

void writeRelationToFile(Relation &newRelation)
{
    std::ofstream writeToFile(FILENAME, std::ios::app);
    if (!writeToFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened!";
        return;
    }

    for (int i = 0; i < newRelation.numberOfPairs; ++i)
    {
        writeToFile << newRelation.pairs[i].firstNumber << " , "
            << newRelation.pairs[i].secondNumber << std::endl;
    }

    writeToFile.close();
}

Relation readRelationFromFile()
{
    Relation newRelation = initRelation();

    std::ifstream readFromFile(FILENAME);
    if (!readFromFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened!";
        return newRelation;
    }

    int firstNumber;
    int secondNumber;

    while (readFromFile >> firstNumber >> secondNumber)
    {
        Pair newPair = initPair(firstNumber, secondNumber);
        addPairToRelation(newRelation, newPair);
    }

    readFromFile.close();

    return newRelation;
}

int main()
{
    Relation newRelation = initRelation();

    Pair pair1 = initPair(2, 4);
    Pair pair2 = initPair(7, 4);
    Pair pair3 = initPair(10, 2);
    Pair pair4 = initPair(12, 5);

    addPairToRelation(newRelation, pair1);
    addPairToRelation(newRelation, pair2);
    addPairToRelation(newRelation, pair3);
    addPairToRelation(newRelation, pair4);

    writeRelationToFile(newRelation);

    Relation readPairs = readRelationFromFile();

    for (int i = 1; i <= newRelation.numberOfPairs; ++i)
    {
        std::cout << i << " relation: "
            <<"( " << newRelation.pairs[i - 1].firstNumber << " , "
            << newRelation.pairs[i - 1].secondNumber << " )" << std::endl;
    }

    return 0;
}
