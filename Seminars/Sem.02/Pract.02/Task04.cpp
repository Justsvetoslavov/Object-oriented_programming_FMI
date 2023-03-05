#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 256,
		  MAX_PAIRS = 25;
char ofpath[MAX_SIZE] = "C:\\Users\\boris\\OneDrive\\Desktop\\relation.txt";

struct Pair
{
	unsigned Nat1, Nat2;
};

struct Relation
{
	unsigned size = 0;
	Pair pairs[MAX_PAIRS];
};

void copyElements(Relation& rel, Pair rels[MAX_PAIRS], int size)
{
	for (int i = 0; i < size; ++i)
		rel.pairs[i] = rels[i];
	rel.size = size;
}

Pair initPair(void)
{
	unsigned a, b;
	Pair p;
	cin >> a >> b;
	p.Nat1 = a; p.Nat2 = b;

	return p;
}

void addPairToRelation(Relation& rel, Pair& pair)
{
	if (rel.size < MAX_PAIRS)
		rel.pairs[rel.size] = pair;
	rel.size++;
}

void writeRelationToFile(Relation& relations)
{
	ofstream streamWriter(ofpath);

	for (int i = 0; i < relations.size; ++i)
		streamWriter << relations.pairs[i].Nat1 << '\n' << relations.pairs[i].Nat2 << '\n';
}

void readRelationFromFile(Relation& rel)
{
	ifstream streamReader(ofpath);

	Pair pairs[MAX_SIZE];

	int i = 0;
	while (!streamReader.eof())
	{
		streamReader >> pairs[i  ].Nat1;
		streamReader >> pairs[i++].Nat2;
	}

	rel.size = i - 1;
	copyElements(rel, pairs, i - 1);
}

int main()
{
	int N;
	do {
		cout << "Enter the amount of pairs: ";
	} while (N <= 0 || N > 25);

	Relation rel;
	rel.size = N;

	for (int i = 0; i < N; ++i)
		rel.pairs[i] = initPair();

	writeRelationToFile(rel);

	Relation rel_again;
	readRelationFromFile(rel_again);

	for (int i = 0; i < N; ++i)
		cout << '(' << rel.pairs[i].Nat1 << ", " << rel.pairs[i].Nat2 << ")\n";

	return 0;
}