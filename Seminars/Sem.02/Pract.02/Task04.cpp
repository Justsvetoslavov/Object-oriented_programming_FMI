#include <iostream>
#include <fstream>

const char FILE_NAME[] = "relations.txt";
const int PAIRS_MAX_SIZE = 25;
const int PAIR_FIELD_SIZE = 7;
const int BUFFER_SIZE = 256;

const int FIRST_NUMBER_IN_PAIR_ID = 1;
const int SECOND_NUMBER_IN_PAIR_ID = 3;

struct Pair {
	int a;
	int b;
};

struct Relation {
	Pair pairs[PAIRS_MAX_SIZE];
	size_t currentSize = 0;
};

Pair InitPair(int a, int b) {
	Pair pair;
	pair.a = a;
	pair.b = b;

	return pair;
}

void AddPairToRelation(const Pair& pair, Relation& relation) {
	size_t relationCurrentSize = relation.currentSize;

	if (relationCurrentSize > PAIRS_MAX_SIZE) {
		std::cout << "You exceeded the maximum size!" << std::endl;
		return;
	}

	relation.pairs[relationCurrentSize] = pair;
	relation.currentSize++;
}


void WritePairToFile(std::ofstream& writeFile, const Pair& pair) {
	writeFile << "(" << pair.a << "," << pair.b << ")" << std::endl;
}


void WriteRelationToFile(const char* fileName, const Relation& relaton) {
	std::ofstream writeFile(fileName);

	size_t relationSize = relaton.currentSize;

	for (size_t i = 0; i < relationSize; i++)
	{
		WritePairToFile(writeFile, relaton.pairs[i]);
	}
	writeFile.close();
}


Pair ReadPairFromFile(const char* fileName, size_t pairId) {
	Pair pair;
	std::ifstream readFile(fileName);
	readFile.seekg(pairId * PAIR_FIELD_SIZE, std::ios::beg);
	char buffer[BUFFER_SIZE];
	readFile.getline(buffer, BUFFER_SIZE);

	pair.a = (int)buffer[FIRST_NUMBER_IN_PAIR_ID];
	pair.b = (int)buffer[SECOND_NUMBER_IN_PAIR_ID];

	readFile.close();
	return pair;
}

int main()
{
	Pair pair1 = InitPair(2, 3);
	Pair pair2 = InitPair(3, 4);
	Pair pair3 = InitPair(4, 5);
	Pair pair4 = InitPair(5, 6);

	Relation relation;

	AddPairToRelation(pair1, relation);
	AddPairToRelation(pair2, relation);
	AddPairToRelation(pair3, relation);

	std::cout << "Relation current size: " << relation.currentSize << std::endl;

	WriteRelationToFile(FILE_NAME, relation);

	Pair pair5 = ReadPairFromFile(FILE_NAME, 2);
	std::cout << "(" << (char)pair5.a << "," << (char)pair5.b << ")" << std::endl;

}
