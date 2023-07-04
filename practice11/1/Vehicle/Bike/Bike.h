#include "../Vehicle.h"

class Bike : public Vehicle {
public:
    Bike(const Tires *_tires, unsigned countT, const EngineType &_type, unsigned countP, double averageS);
    void GetPermit() const override;
};
