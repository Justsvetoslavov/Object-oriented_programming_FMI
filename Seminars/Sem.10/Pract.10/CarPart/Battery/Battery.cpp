#include "Battery.h"

Battery::Battery(const char* _id, unsigned int id):capacity(1600), CarPart(id){
    this->id = new char[1];
    setId(_id);
}

Battery::Battery(const char* _id,unsigned short capacity, unsigned int id):capacity(capacity), CarPart(id){
    this->id = new char[1];
    setId(_id);
}
Battery::Battery(const char* _id):CarPart(0){
    this->id = new char[1];
    setId(id);
}
Battery::Battery(const Battery& other): CarPart(other){
    this->id = new char[1];
    copyFrom(other);
}
Battery::Battery(Battery&& other): CarPart(std::move(other)){
    this->id = new char[1];
    capacity = other.capacity;
    free();
    id = other.id;
    other.id = nullptr;
}

void Battery::copyFrom(const Battery& other){
    setId(other.id);
    setCapacity(other.capacity);
}

void Battery::free(){
    delete[] id;
}
const char * Battery::getId() const{
    return id;
}
unsigned short Battery::getCapacity() const{
    return capacity;
}
unsigned short Battery::setCapacity(const unsigned short _capacity){
    return capacity;
}
Battery& Battery::setId(const char * _id){


    if(_id == nullptr)throw std::invalid_argument("str (_id) is nullptr");
    free();

    id = new char[strlen(_id)];
    strcpy(id,_id);
    return *this;

}

Battery& Battery::operator=(const Battery& other){

    if(this != &other){
        CarPart::operator=(other);
        copyFrom(other);
    }

    return *this;

}

Battery& Battery::operator=(Battery&& other){
    if(this != &other){
        free();
        CarPart::operator=(std::move(other));
        id = other.id;
        other.id = nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Battery& battery){

    os  <<"(" << battery.getId() <<") by "<< battery.getBrand()<<" - "
        <<battery.getDescription()<< " - "<<battery.getCapacity()<<" Ah";
    return os;

}

Battery::Battery(const char *_id, unsigned short capacity,
                 unsigned int id,
                 const char *brand,
                 const char *description
                 ): CarPart(id,brand,description) {

    this->id = new char[1];
    setId(_id);
    this->capacity  = capacity;

}
