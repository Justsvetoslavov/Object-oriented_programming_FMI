#include "Engine.h"

Engine::Engine(int id, const char *name, const char *description, unsigned int horsePower) : CarPart(id, name, description), horsePower(horsePower) {
}