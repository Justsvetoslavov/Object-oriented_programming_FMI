#include <iostream>
#include <fstream>

int const MAX_RELATIONS = 25;

struct pair {
	int first;
	int second;
};

struct relation {
	size_t size;
	pair pairs[MAX_RELATIONS];
};

void initPair(pair& toInit, int first, int second);
void readPairFromFile(std::ifstream& file, pair& toRead);
void writePairToFile(std::ofstream& file, pair& toWrite);
void addPairToRelation(relation& r, pair& toAdd);
void writeRelationToFile(std::ofstream& file, relation& r);
size_t getFileSize(std::ifstream& file);
void readRelationFromFile(std::ifstream& file, relation& r);

int main() {
	pair pair1;
	initPair(pair1, 5, 3);
	pair pair2;
	initPair(pair2, 4, 6);
	relation r {0};
	addPairToRelation(r, pair1);
	addPairToRelation(r, pair2);
	std::ofstream fileWrite("relation.txt");
	if (!fileWrite.is_open())
	{
		std::cout << "Error";
	}
	writeRelationToFile(fileWrite, r);
	fileWrite.close();
	std::ifstream fileRead("relation.txt");
	relation r2;
	readRelationFromFile(fileRead, r2);
	std::cout << r2.pairs[0].first << r2.pairs[0].second << std::endl;
	std::cout << r2.pairs[1].first << r2.pairs[1].second << std::endl;
}

void initPair(pair& toInit, int first, int second) {
	toInit.first = first;
	toInit.second = second;
}

void readPairFromFile(std::ifstream& file, pair& toRead) {
	file.read((char*)& toRead, sizeof(toRead));
}

void writePairToFile(std::ofstream& file, pair& toWrite) {
	file.write((char*)& toWrite, sizeof(toWrite));
}

void addPairToRelation(relation& r, pair& toAdd) {
	if (r.size == MAX_RELATIONS)
	{
		return;
	}
	r.pairs[r.size++] = toAdd;
}

void writeRelationToFile(std::ofstream& file, relation& r) {
	for (size_t i = 0; i < r.size; i++)
	{
		writePairToFile(file, r.pairs[i]);
	}
}

size_t getFileSize(std::ifstream& file) {
	size_t current = file.tellg();
	file.seekg(0, std::ios::end);
	size_t toReturn = file.tellg();
	file.seekg(current, std::ios::beg);

	return toReturn;
}

void readRelationFromFile(std::ifstream& file, relation& r) {
	size_t fileSize = getFileSize(file);
	size_t size = fileSize / sizeof(pair);
	for (size_t i = 0; i < size; i++)
	{
		readPairFromFile(file, r.pairs[i]);
		r.size++;
	}
}