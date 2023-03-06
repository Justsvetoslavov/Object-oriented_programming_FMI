#include <iostream>
#include <fstream>

const char RELATION_PATH[] =
        "C:\\Users\\nikol\\Documents\\"
        "GitHub\\Object-oriented_programming_FMI_2023\\"
        "Seminars\\Sem.02\\Pract.02\\"
        "relation.txt";

struct Pair{

    size_t x = 0;
    size_t y = 0;

};

struct Relation{

    const size_t max_size = 35;
    Pair* pairs = new Pair[max_size];
    int size = 0;

};

Pair createPair(){
    Pair pair;
    return pair;
}

void printPair(Pair pair){
    std::cout<<pair.x<<" "<<pair.y<<"\n";
}

Pair initPair(Pair pair,size_t x, size_t y){

    pair.x = x;
    pair.y = y;

    return pair;

}

bool addPairToRelation(Relation &relation,Pair pair){

    if(relation.max_size == relation.size + 1) return false;

    relation.pairs[relation.size++] = pair;

    return true;

}

Pair readPairFromFile(std::ifstream& file){

    Pair pair;

    if(file.is_open()) {

        file >> pair.x >> pair.y;
        return pair;

    }
    else return pair;
}

bool writePairToFile(std::ofstream& file,Pair pair){

    if(file.is_open()){
        file<<std::endl<<pair.x<<" "<<pair.y;
        return true;
    }
    else return false;
}

bool writeRelationToFile(std::ofstream &file,Relation relation){

    if(!file.is_open())return false;

    for(int i = 0 ; i < relation.size;i++ ){
        writePairToFile(file,relation.pairs[i]);
    }

    return true;

}

Relation readRelationFromFile(std::ifstream &file){


    Relation relation;

    if(!file.is_open())return relation;

    for(int i = 0; !file.eof();i++){
        addPairToRelation(relation,readPairFromFile(file));
    }

    return relation;

}

int main(){

    Relation relation;

    for(int i = 0 ; i < 32;i++){
        addPairToRelation(relation,initPair(createPair(),i,i+1));
    }

    std::ofstream relationOUT(RELATION_PATH,std::ios::out);

    writeRelationToFile(relationOUT,relation);

    relationOUT.close();

    std::ifstream relationIN(RELATION_PATH,std::ios::in);

    Relation relation1 = readRelationFromFile(relationIN);

    for(int i = 0; i < relation1.size;i++){

        printPair(relation1.pairs[i]);

    }

    relationIN.close();

}