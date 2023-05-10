#include "Engine.h"

Engine::Engine(int id, const char *name, const char *description, unsigned int horsePower) : CarPart(id, name, description), horsePower(horsePower) {
}

std::ostream& operator<<(std::ostream& os, const Engine& engine) {
    os << (CarPart)engine << " - " << engine.horsePower << " hp";
    return os;
}