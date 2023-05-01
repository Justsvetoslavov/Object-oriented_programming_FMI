#include <iostream>
#include "MonsterCard.h"

void MonsterCard::copyFrom(const MonsterCard& other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

void MonsterCard::free()
{
    delete[] name;
    name = nullptr;

    attackPoints = 0;
    defensePoints = 0;
}

MonsterCard::MonsterCard()
{
    name[0] = '\0';
    attackPoints = 0;
    defensePoints = 0;
}

MonsterCard::MonsterCard(const char* name, size_t attackPoints, size_t defensePoints)
{
    strcpy(this->name, name);
    this->attackPoints = attackPoints;
    this->defensePoints = defensePoints;
}

MonsterCard::MonsterCard(const MonsterCard& other)
{
    copyFrom(other);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

MonsterCard::~MonsterCard()
{
    free();
}

const char* MonsterCard::getName() const
{
    return name;
}

const size_t MonsterCard::getAttackPoints() const
{
    return attackPoints;
}

const size_t MonsterCard::getDefensePoints() const
{
    return defensePoints;
}

void MonsterCard::setName(char* name)
{
    if (this->name == nullptr || this->name == name)
    {
        return;
    }

    delete this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

