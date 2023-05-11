#ifndef PRACT010_FUELTANK_H
#define PRACT010_FUELTANK_H
#include "CarPart.h"

class FuelTank:CarPart {
    double liters;
    double capacity;
public:
    FuelTank(unsigned id,const MyString& name,const MyString& description,
             double capacity);

    double getLiters() const;
    void setLiters(double liters);

    double getCapacity() const;
    void setCapacity(double capacity);

    FuelTank& use(double liters);
    FuelTank& fill(double liters);

    friend std::ostream& operator<<(std::ostream& os,const FuelTank& ft);
};

std::ostream& operator<<(std::ostream& os,const FuelTank& ft);



#endif //PRACT010_FUELTANK_H
