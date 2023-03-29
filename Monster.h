#pragma once
#include <cstring>

class Monster {
    char* name;
    unsigned int damage;
    unsigned int hp;

public:

    Monster();

    Monster(const char* name, const unsigned int enemies, const unsigned int defenders);

    ~Monster();

    Monster& operator=(const Monster& monster);

    void delMonster();
};
