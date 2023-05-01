#pragma once
#include <iostream>
#pragma warning(disable : 4996)

class MonsterCard
{
    char* name;
    size_t attackPoints;
    size_t defensePoints;

    void copyFrom(const MonsterCard& other);

    void free();

public:

    MonsterCard();

    MonsterCard(const char* name, size_t attackPoints, size_t defensePoints);

    MonsterCard(const MonsterCard& other);

    MonsterCard& operator=(const MonsterCard& other);

    ~MonsterCard();

    const char* getName() const;

    const size_t getAttackPoints() const;

    const size_t getDefensePoints() const;

    void setName(char* name);

};
