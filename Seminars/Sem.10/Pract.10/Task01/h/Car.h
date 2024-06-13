#pragma once
#include "Accumulators.h"
#include"Engines.h"
#include"FuelTank.h"
#include"Tires.h"

const int num_of_tires = 4;
const double distance = 0.4;//km
const  double fuel_per_km = 1.0;//1 l/km

class Car
{
	FuelTank reservoir;
	Engines engine;
	Tires tires[num_of_tires];
	Accumulators accumulator;
	double km;
	double weight;

public:
	Car(double fuel, const Engines& engines, const Tires& tires, const Accumulators& accumulator, double km, double weight);
	
	const FuelTank& getFuelTank()const;
	double getkm()const;
	double getWeight()const;
	const Engines& getEngine()const;

	void drive(double km);
	
};

Car* dragRace(Car* car1, Car* car2);
