
#include "Engine.h"

Engine::Engine(short horsePower) : horsePower{horsePower} {}

double Engine::getHorsePower() const {
    return horsePower;
}

void Engine::setHorsePower(short horsePower) {
    this->horsePower = horsePower;
}

std::ostream &operator<<(std::ostream &os, const Engine &engine) {
    return os << (CarPart &) engine << engine.getHorsePower() << " hp";
}
