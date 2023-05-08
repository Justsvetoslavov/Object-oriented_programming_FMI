#include "TirePack.h"
TirePack::TirePack(const unsigned short amount){
    tires = new Tier[amount];
    this->amount = amount;
}

TirePack::TirePack(const TirePack& other){
    copyFrom(other);
}
TirePack::TirePack(TirePack&& other){
    tires = other.tires;
    amount = other.amount;
    other.tires = nullptr;
}

Tier& TirePack::at(const unsigned short index){
    if(index - 1 > amount)throw std::out_of_range("index out of bounds");
    return tires[index];
}
void TirePack::free(){
    delete[] tires;
}
TirePack::~TirePack(){
    free();
}

void TirePack::setTiersTo(const Tier &tier) {

    for(int i = 0 ; i < amount; i++){
        tires[i] = tier;
    }
}

bool TirePack::operator==(const TirePack &rhs) const {
    return tires == rhs.tires &&
           amount == rhs.amount;
}

bool TirePack::operator!=(const TirePack &rhs) const {
    return !(rhs == *this);
}

TirePack &TirePack::operator=(const TirePack &other) {

    if(this != &other){
        free();
        copyFrom(other);
    }
}

void TirePack::copyFrom(const TirePack &other) {
    tires = new Tier[other.amount];
    for(int i = 0 ; i < other.amount;i++){
        tires[i] = other.tires[i];

    }
    amount = other.amount;
}
