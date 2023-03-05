#include <iostream>
#include <fstream>

struct Pair {
	int a;
	int b;
};

const int MAX_PAIRS_COUNT = 25;

struct Relation {
	Pair pairs[MAX_PAIRS_COUNT];
	unsigned int size;
};

void initPair(Pair& pair) {
	std::cin >> pair.a >> pair.b;
}

Pair* createPair() {
	Pair* myPair = new Pair();
	initPair(*myPair);
	return myPair;
}

//In the file, each pair will be on one line
//The values a and b will be seperated by a space
void readPairFromFile(std::ifstream& src, Pair& pair) {
	src >> pair.a;
	//Skip whitespace
	src.get();
	src >> pair.b;
}

void writePairToFile(std::ofstream& dest, const Pair& pair) {
	dest << pair.a;
	dest << " ";
	dest << pair.b;
	dest << std::endl;
}

void addPairToRelation(Relation& relation, const Pair& pair) {
	if (relation.size >= MAX_PAIRS_COUNT) {
		std::cout << "Max number of pairs reached\n";
		return;
	}

	relation.pairs[relation.size] = pair;
	relation.size++;
}

void writeRelationToFile(const char fileName[], const Relation& relation) {
	std::ofstream file(fileName);

	if (!file.is_open()) {
		std::cout << "Error\n";
		return;
	}

	//Add the relation size on the first row
	file << relation.size << std::endl;

	for (int i = 0; i < relation.size; i++) {
		writePairToFile(file, relation.pairs[i]);
	}

	file.close();
}

void readRelationFromFile(const char fileName[], Relation& relation) {
	std::ifstream file(fileName);
	
	if (!file.is_open()) {
		std::cout << "Error\n";
		return;
	}

	int size;
	file >> size;
	file.get();
	relation.size = size;

	for (int i = 0; i < size; i++) {
		readPairFromFile(file, relation.pairs[i]);
	}

	file.close();
}

void printPair(const Pair& pair) {
	std::cout << "a = " << pair.a << ", b = " << pair.b << "\n";
}

void printRealtion(const Relation& relation) {
	std::cout << "Pairs:\n";
	for (int i = 0; i < relation.size; i++) {
		printPair(relation.pairs[i]);
	}
}

int main()
{
	const int RELATION_SIZE = 10;
	Relation myRelation;
	myRelation.size = RELATION_SIZE;

	for (int i = 0; i < RELATION_SIZE; i++) {
		initPair(myRelation.pairs[i]);
	}

	printRealtion(myRelation);
	writeRelationToFile("relation.txt", myRelation);

	Relation fileRelation;
	readRelationFromFile("relation.txt", fileRelation);
	printRealtion(fileRelation);
}
