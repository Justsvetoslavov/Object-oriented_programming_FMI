#pragma once
#include "../CarPart.h"

class Engine:protected CarPart{

    unsigned short hp = 80;

public:

    Engine() = default;
    Engine(unsigned short _hp,unsigned int id);
    Engine(unsigned short _hp,unsigned int id,const char* brand,const char* description);

    const unsigned short getHp() const;
    Engine& setHp(unsigned short _hp);

    Engine& operator=(const Engine& other) = default;

    friend std::ostream& operator<<(std::ostream& os,const Engine& engine);

};
