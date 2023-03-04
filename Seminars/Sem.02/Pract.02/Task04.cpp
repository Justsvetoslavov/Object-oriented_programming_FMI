#include <iostream>
#include <fstream>

const int RELATION_PAIRS_MAX_COUNT = 25;
const int NUMBER_MAX_LENGTH = 11;
const int BUFF_SIZE = 1024;
const char* FILE_NAME = "relation.txt";

struct Pair
{
	unsigned int a;
	unsigned int b;
};

struct Relation
{
	unsigned int pairsCount;
	Pair pairs[RELATION_PAIRS_MAX_COUNT];
};

void convertStringToInt(const char* str, int& num, const int numLength)
{
	int helpingNum = 1;
	for (int i = numLength - 1; i >= 0; i--)
	{
		num += ((int)str[i]) * helpingNum;
		helpingNum *= 10;
	}
}

Pair* CreatePair(unsigned int a, unsigned int b)
{
	Pair pair{ a,b };
	return &pair;
}

void initPair(Pair& pair)
{
	std::cin >> pair.a >> pair.b;
}

void readPairFromFile(std::ifstream& file, Pair& pair)
{
	int prevPos = file.tellg();

	int firstNumIndex = 0;
	char firstNum[NUMBER_MAX_LENGTH];
	char secondNum[NUMBER_MAX_LENGTH];
	int buffIndex = 0;
	char buff[BUFF_SIZE];

	file.getline(buff, BUFF_SIZE, '\n');

	while (buff[buffIndex] != ' ')
	{
		firstNum[firstNumIndex++] = buff[buffIndex++];
	}
	firstNum[firstNumIndex] = '\0';
	buffIndex++;

	int secondNumIndex = 0;
	while (buff[buffIndex] != '\0')
	{
		secondNum[secondNumIndex++] = buff[buffIndex++];
	}
	secondNum[secondNumIndex] = '\0';

	int firstNumAsInt = 0;
	int secondNumAsInt = 0;

	convertStringToInt(firstNum, firstNumAsInt, firstNumIndex);
	convertStringToInt(secondNum, secondNumAsInt, secondNumIndex);

	pair.a = (unsigned int)firstNumAsInt;
	pair.b = (unsigned int)secondNumAsInt;

	file.seekg(prevPos);
}

void writePairToFile(std::ofstream& file, const Pair& pair)
{
	file << pair.a << " " << pair.b << std::endl;
}

void addPairToRelation(Relation& relation, const Pair& pair)
{
	if (relation.pairsCount < RELATION_PAIRS_MAX_COUNT)
	{
		relation.pairs[relation.pairsCount++] = pair;
	}
}

int main()
{
	Pair pair1 = *CreatePair(4, 6);
	std::cout << pair1.a << pair1.b;

	Pair pair2;
	initPair(pair2);

	Pair pair3 = { 3,4 };
	std::ofstream fileToWrite(FILE_NAME);
	if (fileToWrite.is_open())
	{
		writePairToFile(fileToWrite, pair3);
	}
	fileToWrite.close();

	Pair pair4;
	std::ifstream fileToRead(FILE_NAME);
	if (fileToRead.is_open())
	{
		readPairFromFile(fileToRead, pair4);
	}
	fileToRead.close();

	Relation relation;
	relation.pairsCount = 0;
	addPairToRelation(relation, pair1);
	addPairToRelation(relation, pair2);
	addPairToRelation(relation, pair3);
	addPairToRelation(relation, pair4);
}