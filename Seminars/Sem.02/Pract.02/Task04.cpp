#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream, std::fstream;

const char *RELATIONS_FILE = "relations.txt";
const int max_relation_size = 25;

struct Pair {
    unsigned int x;
    unsigned int y;
};

struct Relation {
    Pair pairs[max_relation_size];
    unsigned int size;
};

void writeRelationToFile(const Relation &relation, fstream &file) {
    for (int i = 0; i < relation.size; i++) {
        file << relation.pairs[i].x << " " << relation.pairs[i].y << endl;
    }
}

void readRelationFromFile(Relation &relation, fstream &file) {
    int x, y;
    while (file >> x >> y) {
        cout << x << " " << y << endl;
        relation.pairs[relation.size].x = x;
        relation.pairs[relation.size].y = y;
        relation.size++;
    }
}

void createPair(Pair &pair, unsigned int x, unsigned int y) {
    pair.x = x;
    pair.y = y;
}

void addPairToRelation(Relation &relation, const Pair &pair) {
    if (relation.size < max_relation_size) {
        relation.pairs[relation.size] = pair;
        relation.size++;
    }
}

void readPairFromFile(Pair &pair, fstream &file) {
    int x, y;
    file >> x >> y;
    createPair(pair, x, y);
}

void writePairToFile(const Pair &pair, fstream &file) {
    file << pair.x << " " << pair.y << endl;
}

void printRelation(const Relation &relation) {
    cout << "Relation:" << endl;
    for (int i = 0; i < relation.size; i++) {
        cout << relation.pairs[i].x << " " << relation.pairs[i].y << endl;
    }
}

int main() {
    fstream relationsFile(RELATIONS_FILE);
    if (!relationsFile.is_open()) {
        cout << "Could not open file " << RELATIONS_FILE << endl;
        return -1;
    }

    Relation relation{};
    Pair pair{};
    createPair(pair, 1, 2);
    addPairToRelation(relation, pair);
    createPair(pair, 3, 4);
    addPairToRelation(relation, pair);

    writeRelationToFile(relation, relationsFile);

    readPairFromFile(pair, relationsFile);
    writePairToFile(pair, relationsFile);

    readRelationFromFile(relation, relationsFile);
    printRelation(relation);

    relationsFile.close();
    return 0;
}
