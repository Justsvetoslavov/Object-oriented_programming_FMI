#include "../Vehicle.h"

class Tir : public Vehicle {
public:
    Tir(const Tires *_tires, unsigned countT, const EngineType &_type, unsigned countP, double averageS);
    void GetPermit() const override;
};