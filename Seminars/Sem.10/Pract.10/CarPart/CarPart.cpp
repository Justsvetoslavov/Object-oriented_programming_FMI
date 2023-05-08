#include "CarPart.h"

void CarPart::free(){
    delete[] brand;
    delete[] description;
}


CarPart::CarPart(){
    brand = new char[0];
    description = new char[0];
    id = 0;
}
void CarPart::copyFrom(const CarPart& other){

    brand = new char[0];
    description = new char[0];
    this->setId(other.id)
    .setBrand(other.brand)
    .setDescription(other.description);

}

CarPart::CarPart(unsigned int id) {

    this->id = id;
    brand = new char[DEFAULT_BRAND_LENGTH];
    description = new char[DEFAULT_DESCRIPTION_LENGTH];

}

CarPart::CarPart(unsigned int newId,const char* newBrand, const char* newDescription){
    brand = new char[1];
    description  = new char[1];
    this->setId(newId)
    .setBrand(newBrand)
    .setDescription(newDescription);
}
CarPart::CarPart(CarPart&& other):brand(other.brand),description(other.description),id(other.id){
    other.brand = nullptr;
    other.description = nullptr;
}
CarPart::CarPart(const CarPart &other) {
    copyFrom(other);
}
CarPart::~CarPart() {
    free();
}
const unsigned int CarPart::getId() const{
    return id;
}
const char* CarPart::getBrand()const{
    return brand;
}
const char* CarPart::getDescription()const{
    return description;
}

CarPart& CarPart::setId(unsigned int newId){
    id = newId;
    return *this;
}
CarPart& CarPart::setBrand(const char *newBrand) {

    if(newBrand == nullptr)throw std::invalid_argument("str (newBrand) is nullptr");
    delete[] brand;
    brand = new char[strlen(newBrand) + 1];
    strcpy(brand,newBrand);
    return *this;

}
CarPart& CarPart::setDescription(const char *newDescription) {

    if(newDescription == nullptr)throw std::invalid_argument("str (newDescription) is nullptr");
    delete[] description;
    description = new char[strlen(newDescription) + 1];
    strcpy(description,newDescription);
    return *this;

}

CarPart& CarPart::operator=(const CarPart& other){

    if(this != &other){
        free();
        copyFrom(other);
    }

    return *this;
}

CarPart& CarPart::operator=(CarPart&& other){

    if(this != &other){
       free();
       id = other.id;
       brand = other.brand;
       description = other.description;

       other.brand = nullptr;
       other.description = nullptr;
    }

    return *this;

}

