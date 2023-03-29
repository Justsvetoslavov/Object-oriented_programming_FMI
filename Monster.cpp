#include "Monster.h"

Monster::Monster() {
    name = new char[1];
    name[0] = '\0';
    damage = 0;
    hp = 0;
}

Monster::Monster(const char *name, const unsigned int enemies, const unsigned int defenders) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->damage = enemies;
    this->hp = defenders;
}

Monster::~Monster() {
    delete[] name;
}

Monster &Monster::operator=(const Monster& monster) {
    delete[] name;
    name = new char[strlen(monster.name) + 1];
    strcpy(this->name, monster.name);
    this->hp = monster.hp;
    this->damage = monster.damage;
    return *this;
}

void Monster::delMonster() {
    delete[] name;
    name = new char[1];
    name[0] = '\0';
    hp = 0;
    damage = 0;
}