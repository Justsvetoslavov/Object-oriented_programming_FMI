#include "Engine.h"


Engine::Engine(unsigned int id, const MyString &name, const MyString &desc, unsigned hp):CarPart(id,name,desc) {
    setHp(hp);
}
unsigned int Engine::getHp() const {
    return hp;
}

void Engine::setHp(unsigned int hp) {
    Engine::hp = hp;
}

std::ostream & operator<<(std::ostream&os, const Engine& engine){
    os<<(CarPart&)engine<<"- ";
    os<<engine.hp<<" hp ";
    return os;
}




