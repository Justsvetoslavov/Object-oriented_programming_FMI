#include "Tier.h"

void Tier::isValid(unsigned short _width,unsigned short _profile,unsigned short _diameter){
    if(_width >  365 || _width < 155)throw std::invalid_argument("width is incorrect");
    if(_profile > 80 || _profile < 30)throw std::invalid_argument("profile is incorrect");
    if(_diameter > 21 || _profile < 13)throw std::invalid_argument("diameter is incorrect");
}

Tier::Tier(): CarPart(){

    width = VALID_WIDTH;
    profile = VALID_PROFILE;
    diameter = VALID_DIAMETER;

}
void Tier::copyFrom(const Tier& other){

    width = other.width;
    profile = other.profile;
    diameter = other.diameter;

}
Tier::Tier(unsigned short width,unsigned short profile,unsigned short diameter,
           unsigned int id)
           :width(width),profile(profile),diameter(diameter), CarPart(id){

    isValid(width,profile,diameter);
}
Tier::Tier(unsigned short width,unsigned short profile,unsigned short diameter,
     unsigned int id,
     const char* brand,
     const char* description )
     :width(width),profile(profile),diameter(diameter), CarPart(id,brand,description){

    isValid(width,profile,diameter);
}
Tier::Tier(const Tier& other): CarPart(other){
    copyFrom(other);
}
Tier::Tier(Tier&& other): CarPart(std::move(other)){}

const unsigned short Tier::getWidth() const{
    return width;
}
const unsigned short Tier::getProfile() const{
    return  profile;
}
const unsigned short Tier::getDiameter() const{
    return diameter;
}

Tier& Tier::setWidth(unsigned short _width){
    isValid(_width,VALID_PROFILE,VALID_DIAMETER);
    width = _width;
    return *this;
}
Tier& Tier::setProfile(unsigned short _profile){

    isValid(VALID_WIDTH,_profile,VALID_DIAMETER);
    profile=_profile;
    return *this;

}
Tier& Tier::setDiameter(unsigned short _diameter){
    isValid(VALID_WIDTH,VALID_PROFILE,_diameter);
    diameter = _diameter;
    return *this;
}

Tier& Tier::operator=(const Tier& other){

    if(this != &other){
       CarPart::operator=(other);
       width = other.width;
       profile = other.profile;
       diameter = other.diameter;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os,const Tier& tier){

    os  <<"("<< tier.getId()<<") by "<< tier.getBrand()
        <<" - "<<tier.getDescription()<<" - " <<tier.getWidth()
        <<"/"<<tier.getProfile()<<"R"<<tier.getDiameter();

    return os;
}