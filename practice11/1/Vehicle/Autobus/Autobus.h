#include "../Vehicle.h"

class Autobus : public Vehicle {
public:
    Autobus(const Tires *_tires, unsigned countT, const EngineType &_type, unsigned countP, double averageS);
    void GetPermit() const override;
};
