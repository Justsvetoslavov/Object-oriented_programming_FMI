
#include "Tyre.h"

Tyre::Tyre(unsigned int id, const MyString &name, const MyString &desc,
           unsigned int width, unsigned int profile, unsigned int diameter): CarPart(id,name,desc) {
    setWidth(width);
    setDiameter(diameter);
    setProfile(profile);
}

Tyre::Tyre() {
    setWidth(0);
    setProfile(0);
    setDiameter(0);
}


void Tyre::setWidth(unsigned int width) {
    if(width<155||width>365){
        width=155;
    }
    this->width=width;
}

void Tyre::setProfile(unsigned int profile) {
    if(profile<30||profile>80){
        profile=30;
    }
    this->profile=profile;
}

void Tyre::setDiameter(unsigned int diam) {
    if(diam<13||diam>21){
        diam=13;
    }
    this->diameter=diam;
}

unsigned int Tyre::getWidth() const {
    return width;
}

unsigned int Tyre::getProfile() const {
    return profile;
}

unsigned int Tyre::getDiameter() const {
    return diameter;
}

std::ostream & operator<<(std::ostream&os, const Tyre& tyre){
    os<<(CarPart)tyre<<"- ";
    os<<tyre.width<<" \ "<<tyre.profile<<" R "<<tyre.diameter;
    return os;

}

