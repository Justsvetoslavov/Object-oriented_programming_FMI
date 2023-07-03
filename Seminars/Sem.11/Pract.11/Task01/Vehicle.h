#pragma once

#include "CarPart.h"
#include "TireConstants.h"

typedef unsigned short ushort;

enum class EngineType {
	petrol,
	diesel,
	electric,
	unknown,
	none
};

enum class TravelRights {
	city,
	highways, 
	rural,
	all
};

class Vehicle {
public:

	struct Point {
		double x = 0;
		double y = 0;

		Point() = default;
		Point(int x, int y);
		double getDist(const Point& other) const;
	};

	class Tire : public CarPart {
		ushort _width = MIN_WIDTH;
		ushort _profile = MIN_PROFILE;
		ushort _rim = MIN_RIM_SIZE;

		static bool isValidWidth(ushort width);
		static bool isValidProfile(ushort profile);
		static bool isValidDiameter(ushort diameter);

	public:
		Tire() = default;
		Tire(unsigned ID, MyString manufacturer, MyString description, ushort width, ushort profile, ushort diameter);

		ushort getWidth() const;
		bool setWidth(ushort width);

		ushort getProfile() const;
		bool setProfile(ushort profile);

		ushort getRimSize() const;
		bool setRimSize(ushort diameter);
	};

	// Big 6 
	Vehicle() = default;
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);

	Vehicle& operator=(Vehicle&& other) noexcept;
	Vehicle(Vehicle&& other) noexcept;

	// Virtual functions => virtual destructor
	virtual ~Vehicle();

	Vehicle(const Tire* tires, unsigned numberOfTires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed);

	// The following  functions have the same behavior for 
	// all derived classes:
	void setEngineType(const EngineType& engineType);
	double getTravelTime(const Point& A, const Point& B) const;
	void changeTireAtIndex(const Tire& tire, unsigned ind);

	// The travel rights for all derived classes are different
	// Pure virtual function
	virtual TravelRights getTravelRights() = 0;

private:
	// Array of tires => Big 4 / Big 6
	Tire* _tires = nullptr;
	unsigned _numberOfTires = 0;
	EngineType _engineType = EngineType::unknown;
	unsigned _numberOfPassengers = 0;
	double _averageSpeed = 0;

	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other);
	void free();
	void copyTires(const Tire* tires, unsigned numberOfTires);
};
