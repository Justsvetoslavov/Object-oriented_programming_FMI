#ifndef PRACT010_CARPART_H
#define PRACT010_CARPART_H
#include <iostream>
#include "MyString.h"

class CarPart {
    unsigned id;
    MyString name;
    MyString description;
public:
    CarPart();
    CarPart(unsigned ,const MyString&,const MyString&);

    void setID(unsigned );
    void setName(const MyString&);
    void setDescription(const MyString&);

    unsigned getID()const;
    const MyString& getName()const;
    const MyString& getDescription()const;

    friend std::ostream& operator<<(std::ostream &os ,const CarPart&);
};
std::ostream& operator<<(std::ostream& os,const CarPart&);



#endif //PRACT010_CARPART_H
