#include <iostream>
#include <fstream>

const int MAX_PAIRS_COUNT = 25;
const char FILE_NAME[] = "relation.txt";
const char ERROR_MESSAGE[] = "Error";

struct Pair
{
	int a, b;
};

struct Relation
{
	Pair pairs[MAX_PAIRS_COUNT];
	unsigned int size = 0;
};

void InitPair(Pair& pair)
{
	std::cin >> pair.a >> pair.b;
}

void ReadPairFromFile(std::ifstream& src, Pair& pair)
{
	src >> pair.a >> pair.b;
}

void WritePairToFile(std::ofstream& dest, const Pair& pair)
{
	dest << pair.a << " " << pair.b << std::endl;
}

bool AddPairToRelation(Relation& relation, const Pair& pair)
{
	if (relation.size >= MAX_PAIRS_COUNT) {
		std::cout << "Max number of pairs reached\n";
		return false;
	}

	relation.pairs[relation.size++] = pair;
    return true;
}

void WriteRelationToFile(const char fileName[], const Relation& relation)
{
	std::ofstream file(fileName);
	if (!file.is_open()) {
		std::cout << ERROR_MESSAGE << std::endl;
		return false;
	}

	//Add the relation size on the first row
	file << relation.size << std::endl;
	for (size_t i = 0; i < relation.size; i++) {
		WritePairToFile(file, relation.pairs[i]);
	}

	file.close();
    return true;
}

bool ReadRelationFromFile(const char fileName[], Relation& relation)
{
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << ERROR_MESSAGE << std::endl;
		return false;
	}

	file >> relation.size;
	for (size_t i = 0; i < relation.size; i++) {
		ReadPairFromFile(file, relation.pairs[i]);
	}

	file.close();
    return true;
}

void PrintPair(const Pair& pair)
{
	std::cout << "a = " << pair.a << ", b = " << pair.b << std::endl;
}

void PrintRealtion(const Relation& relation) {
	std::cout << "Pairs:" << std::endl;
	for (size_t i = 0; i < relation.size; i++) {
		PrintPair(relation.pairs[i]);
	}
}

int main()
{
	const int RELATION_SIZE = 10;
	Relation myRelation;
	myRelation.size = RELATION_SIZE;

	for (size_t i = 0; i < RELATION_SIZE; i++) {
		InitPair(myRelation.pairs[i]);
	}

	PrintRealtion(myRelation);
	WriteRelationToFile(FILE_NAME, myRelation);

	Relation fileRelation;
	ReadRelationFromFile(FILE_NAME, fileRelation);
	PrintRealtion(fileRelation);
}