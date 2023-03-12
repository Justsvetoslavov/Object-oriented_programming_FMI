#include <iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

const int MAX = 25;
struct Pair {
    int first;
    int second;
};


struct Relation {
    Pair pairs[MAX];
    int size;
};

Pair CreatePair(int first, int sec) {
    Pair p;
    p.first = first;
    p.second = sec;
    return p;
}
Relation createRelation() {
    Relation r;
    r.size = 0;
    return r;
}
void addPairToRelation(Relation& r, Pair p) {
    if (r.size < MAX) {
        r.pairs[r.size] = p;
        r.size++;
    }
    else {
        cout << "Error: Relation is already at maximum size." << endl;
    }
}
void writeRelationToFile(Relation& r) {
    std::ofstream file("relation.txt");
    if (!file.is_open()) {
        cout << "error";
        return;
    }
    for (int i = 0; i < r.size; i++) {
        file << r.pairs[i].first << "," << r.pairs[i].second << endl;

    }
    file.close();

}
Relation readRelationFromFile() {
    Relation r = createRelation();
    std::ifstream file("relation.txt");
    if (!file.is_open()) {
        cout << "error";
        return r;
    }
    int first, second;
    while (file >> first >> second) {
        Pair p = CreatePair(first, second);
        addPairToRelation(r, p);
       
    }
    file.close();

    return r;

}
int main() {
    Relation r = createRelation();
    addPairToRelation(r, CreatePair(5, 10));
    addPairToRelation(r, CreatePair(22, 33));
    addPairToRelation(r, CreatePair(35 ,45));
    writeRelationToFile(r);
    Relation r2 = readRelationFromFile();
    for (int i = 0; i < r2.size; i++) {
        cout << "(" << r2.pairs[i].first << ", " << r2.pairs[i].second << ")" << endl;
    }
    return 0;

}
