#include <iostream>
#include <fstream>
#include <cassert>

const char PATH_REL[] = "relation.txt";

struct Pair {
    int a = 0, b = 0;
};

struct Relation {
    int size = 0;
    Pair pairs[25];
};

Pair createPair(const int &a = 0, const int &b = 0) {
    Pair res{a, b};
    return res;
}

void initPair(Pair &pair, const int &a, const int &b) {
    pair.a = a;
    pair.b = b;
}

void writePairToFile(std::fstream &file, const Pair &pair) {
    file << pair.a << " " << pair.b << " ";
}

Pair readPairFromFile(std::fstream &file, const int &mode = 0) {
    size_t curr_pos;
    if (mode == 0) {
        curr_pos = file.tellg();
        file.seekg(std::ios::beg);
    }
    Pair res;
    char rotator;
    int number = 0, time = 1;
    while (file.get(rotator)) {
        if (rotator == ' ') {
            if (time == 1)
                res.a = number;
            else {
                res.b = number;
                break;
            }
            number = 0;
            time++;
            continue;
        }
        number = number * 10 + (int) rotator - 48;
    }
    if (mode == 0) {
        file.clear();
        file.seekg(curr_pos);
    }
    return res;
}

void addPairToRelation(Relation &rel, const Pair &pair) {
    rel.pairs[rel.size] = pair;
    rel.size++;
}

void writeRelationToFile(const Relation &rel) {
    std::fstream file(PATH_REL, std::ios::out);
    assert(file.is_open());
    for (int i = 0; i < rel.size; ++i) {
        writePairToFile(file, rel.pairs[i]);
    }
    file.close();
}

Relation readRelationFromFile(std::fstream &file) {
    size_t curr_pos = file.tellg();
    file.seekg(0, std::ios::beg);
    Relation res;
    int i = -1;
    while (file.tellg() != EOF) {
        res.pairs[++i] = readPairFromFile(file, 1);
    }
    res.size = i;
    file.clear();
    file.seekg(curr_pos);
    return res;
}

int main() {
    std::fstream file("test1.txt", std::ios::in | std::ios::out | std::ios::app);
    Pair ex = createPair(4, 3);
    ex = readPairFromFile(file);
    std::cout << ex.a << " " << ex.b << std::endl;
    initPair(ex, 4, 6);
    ex = readPairFromFile(file);
    writePairToFile(file, ex);
    file.close();
    Relation rel;
    addPairToRelation(rel, ex);
    addPairToRelation(rel, {3, 5});
    writeRelationToFile(rel);
    file.open("test1.txt", std::ios::in);
    Relation ex1 = readRelationFromFile(file);
    std::cout << std::endl << ex1.pairs[0].a << " " << ex1.pairs[0].b << " - " << ex1.size;
    file.close();
}