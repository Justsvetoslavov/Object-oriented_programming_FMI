#ifndef PRACT010_ENGINE_H
#define PRACT010_ENGINE_H
#include "CarPart.h"

class Engine:CarPart {
    unsigned hp;

public:
    Engine(unsigned id, const MyString& name,const MyString&desc,unsigned hp);

    unsigned getHp() const;

    void setHp(unsigned hp);

    friend std::ostream & operator<<(std::ostream&os, const Engine& engine);
};

std::ostream & operator<<(std::ostream&os, const Engine& engine);



#endif //PRACT010_ENGINE_H
