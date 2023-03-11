#include <iostream>
#include <fstream>

const int MAX_SIZE = 25;
struct Pair
{
    int a;
    int b;
};

struct Relation
{
    int numberOfPairs;
    Pair members[MAX_SIZE];
};

void createPair(Pair& myPair)
{
    std:: cout << "Type two numbers: ";
    std:: cin >> myPair.a >> myPair.b;
}

void createRelation(Relation& myRelation)
{
    std:: cout << "Number of pairs: ";
    std:: cin >> myRelation.numberOfPairs;
    for(int i = 0; i < myRelation.numberOfPairs; i++)
    {
        Pair myPair;
        createPair(myPair);
        myRelation.members[i] = myPair;
    }
}

void creatPairsForRelation(Relation myRelation, const int numberOfPairs)
{
    for(int i = 0; i < numberOfPairs; i++)
    {
        myRelation.members[i].a = 0;
        myRelation.members[i].b = 0;
    }
}

void readRelationFromFile(const char* nameFile, Relation& myRelation)
{
    std::ifstream myFile(nameFile, std::ios::in);
    if(myFile.is_open())
    {
        myFile >> myRelation.numberOfPairs;
        creatPairsForRelation(myRelation, myRelation.numberOfPairs);
        for(int i = 0; i < myRelation.numberOfPairs; i++)
        {  
            myFile >> myRelation.members[i].a;
            myFile >> myRelation.members[i].b;

        }
    }
    else
    {
        std:: cout << "Error";
    }
    
    myFile.close();
}

void writeRelationToFile(const char* nameFile, const Relation& myRelation)
{
    std::ofstream myFile(nameFile, std::ios::out);
    myFile << myRelation.numberOfPairs;
    myFile << '\n';
    for(int i = 0; i < myRelation.numberOfPairs; i++)
    {
        myFile << myRelation.members[i].a;
        myFile << " ";
        myFile << myRelation.members[i].b;
        myFile << '\n';
    }

    myFile.close();
}

void printRelation(const Relation& myRelation)
{
    std:: cout << "Number of pairs: " << myRelation.numberOfPairs << '\n';
    for(int i = 0; i < myRelation.numberOfPairs; i++)
    {
        std:: cout << myRelation.members[i].a << " " << myRelation.members[i].b << '\n';
    }
}

int main()
{
    Relation myRelation;
    createRelation(myRelation);
    writeRelationToFile("relation.txt", myRelation);
    Relation newRelation;
    readRelationFromFile("relation.txt", newRelation);
    printRelation(newRelation);
}