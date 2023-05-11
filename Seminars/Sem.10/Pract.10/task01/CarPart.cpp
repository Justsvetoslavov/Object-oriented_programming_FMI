#include "CarPart.h"

CarPart::CarPart() {
    id=0;
    name="";
    description="";
}

CarPart::CarPart(unsigned id, const MyString& name, const MyString& desc) {
    setID(id);
    setName(name);
    setDescription(desc);
}

void CarPart::setID(unsigned id) {
    this->id=id;
}

void CarPart::setName(const MyString& name) {
    this->name=name;
}

void CarPart::setDescription(const MyString& desc) {
    this->description=desc;
}

unsigned int CarPart::getID() const {
    return id;
}

const MyString &CarPart::getName() const {
    return name;
}

const MyString &CarPart::getDescription() const {
    return description;
}

std::ostream& operator<<(std::ostream &ost ,const CarPart& cp){
    ost<<cp.id<<" by "<<cp.name<<" - "<<cp.description<<' ';
    return ost;
}




