#include "Car.hpp"
#include <iostream>

Car::Car(FuelTank fuelTank, Engine engine, Tyre tyre[4], Accumulator accumulator, double kmDrove, double weight)
{
	setFuelTank(fuelTank);
	setEngine(engine);
	setTyres(tyre);
	setAccumulator(accumulator);
	setKmDrove(kmDrove);
	setWeight(weight);
}

void Car::setFuelTank(FuelTank& fuelTank)
{
	this->fuelTank = fuelTank;
}

void Car::setEngine(Engine& engine)
{
	this->engine = engine;
}

void Car::setTyres(Tyre tyre[4])
{
	for (size_t i = 0; i < 4; i++)
	{
		this->tyre[i] = tyre[i];
	}
}

void Car::setAccumulator(Accumulator& accumulator)
{
	this->accumulator = accumulator;
}

void Car::setKmDrove(double kmDrove)
{
	if (kmDrove >= 0)
	{
		this->kmDrove = kmDrove;
	}
	else
	{
		throw std::logic_error("KM drove must be positive num");
	}
}

void Car::setWeight(double weight)
{
	if (weight > 0)
	{
		this->weight = weight;
	}
	else
	{
		throw std::logic_error("Weight must be positive num");
	}
}

const FuelTank& Car::getFuelTank()
{
	return this->fuelTank;
}

void Car::drive(double drive)
{
	double fuelNeed = drive;
	if (this->fuelTank.enoughFuel(fuelNeed))
	{
		this->fuelTank.use(fuelNeed);
	}
	this->kmDrove += drive;
}

Car* dragRace(Car* car1, Car* car2)
{
	if (!car1->fuelTank.enoughFuel(0.4))
	{
		std::cout << "Car1 has no fuel" << std::endl;
		return car2;
	}
	else if (!car2->fuelTank.enoughFuel(0.4))
	{
		std::cout << "Car2 has no fuel" << std::endl;
		return car2;
	}
	else if (!car1->fuelTank.enoughFuel(0.4) && !car2->fuelTank.enoughFuel(0.4))
	{
		std::cout << "Both cars have no fuel" << std::endl;
		return nullptr;
	}
	else
	{
		double car1Power = car1->weight / car1->engine.getHorsePower();
		double car2Power = car2->weight / car2->engine.getHorsePower();

		if (car1Power == car2Power)
		{
			std::cout << "Both cars have same power" << std::endl;
			return nullptr;
		}
		else if (car1Power > car2Power)
		{
			std::cout << "Car1 won" << std::endl;
			return car1;
		}
		else
		{
			std::cout << "Car2 won" << std::endl;
			return car2;
		}
	}
}