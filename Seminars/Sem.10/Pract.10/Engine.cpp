#include "Engine.h"

void Engine::setHorsePower(unsigned int horsePower) {
    this->horsePower = horsePower;
}

Engine::Engine(unsigned int horsePower, unsigned int indetificator,
               const char *proizvoditel, const char *description) : CarPart(indetificator, proizvoditel, description) {
    setHorsePower(horsePower);
}

std::ostream &operator<<(std::ostream &os, const Engine &engine) {
    os << (CarPart &) engine << " - " << engine.horsePower << " hp";
    return os;
}

unsigned Engine::getHorsePower() const {
    return this->horsePower;
}
