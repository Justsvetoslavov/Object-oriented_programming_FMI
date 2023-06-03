#include "Engine.h"

const size_t Engine::getHorsePower() const
{
    return horsePower;
}

void Engine::setHorsePower(const size_t horsePower)
{
    if (horsePower <= 0)
    {
        std::cout << ERROR_MESSAGE << std::endl;
        return;
    }
    else
    {
        this->horsePower = horsePower;
    }
}

std::ostream& operator<<(std::ostream& stream, const Engine& engine)
{
    return stream << (CarPart&)engine;
    return stream << engine.horsePower << "hp" << std::endl;
}