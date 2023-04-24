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

Monster::Monster(const Monster &monster) {
    copyFrom(monster);
}

Monster::~Monster() {
    free();
}

Monster &Monster::operator=(const Monster& monster) {
    if (this != &monster) {
        free();
        copyFrom(monster);
    }
    return *this;
}

void Monster::delMonster() {
    free();
    name = new char[1];
    name[0] = '\0';
}

void Monster::free() {
    delete[] name;
    hp = 0;
    damage = 0;
}

void Monster::copyFrom(const Monster &monster) {
    name = new char[strlen(monster.name) + 1];
    strcpy(name, monster.name);
    hp = monster.hp;
    damage = monster.damage;
}