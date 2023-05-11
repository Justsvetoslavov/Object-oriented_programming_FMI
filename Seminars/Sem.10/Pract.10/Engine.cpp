#include "Engine.h"

size_t Engine::getHorsePower() const
{
    return horsePower;
}

void Engine::SetHorsePower(size_t horsePower)
{
    this->horsePower = horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
    operator<<(os, (CarPart&)engine);
    String output = " - " + String(engine.getHorsePower()) + " hp";
    os << output;
    return os;
}
