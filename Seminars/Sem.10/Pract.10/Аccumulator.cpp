#include "Аccumulator.h"

Accumulator::Accumulator(size_t capacity, const String& batterId)
{
    SetCapacity(capacity);
    setBatterId(batterId);
}

size_t Accumulator::getCapacity() const
{
    return capacity;
}

const String& Accumulator::GetBatteryId() const
{
    return batteryId;
}

void Accumulator::SetCapacity(size_t capacity)
{
    if (capacity < 0) throw std::runtime_error("capacity can\'t be negative");
    this->capacity = capacity;
}

void Accumulator::setBatterId(const String& batterId)
{
    this->batteryId = batterId;
}

std::ostream& operator<<(std::ostream& os, const Accumulator& accumulator)
{
    operator<<(os, (CarPart&)accumulator);
    String output = " - " + String(accumulator.getCapacity()) + " Ah";
    os << output;
    return os;
}
