#include "Engine.h"

Engine::Engine(unsigned short _hp,unsigned int id): CarPart(id){
    hp = _hp;
}
Engine::Engine(unsigned short _hp,unsigned int id,const char* brand,const char* description):CarPart(id,brand,description){
    hp = _hp;
}
const unsigned short Engine::getHp() const{
    return hp;
}
Engine& Engine::setHp(unsigned short _hp){
    hp = _hp;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Engine& engine){
    os  << "("<<engine.getId()<<") by "<< engine.getBrand() <<" - "
        <<engine.getDescription()<<" - "<<engine.getHp()<<" hp";
    return os;
}