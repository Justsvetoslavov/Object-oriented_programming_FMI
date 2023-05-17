#include "Vehicle.h"

void Vehicle::copyTires(const Tire* tires, unsigned numberOfTires) {
	// Deleting the old _tires array(if such exists) should be done elsewhere 
	// Create an array to store the copied objects 
	_tires = new Tire[numberOfTires];
 
	// Copy
	for (int i = 0; i < numberOfTires; i++) {
		_tires[i] = tires[i];
	}
}

void Vehicle::copyFrom(const Vehicle& other) {
	_numberOfTires = other._numberOfTires;

	copyTires(other._tires, other._numberOfTires);

	_engineType = other._engineType;
	_numberOfPassengers = other._numberOfPassengers;
	_averageSpeed = other._averageSpeed;
}

void Vehicle::moveFrom(Vehicle&& other){
	// "Steal" the dynamically allocated array 
	_tires = other._tires;
	other._tires = nullptr;

	// Copy all other class members 
	_numberOfTires = other._numberOfTires;
	_engineType = other._engineType;
	_numberOfPassengers = other._numberOfPassengers;
	_averageSpeed = other._averageSpeed;
}

void Vehicle::free() {
	delete[] _tires;
	_tires = nullptr;

	_numberOfTires = _numberOfPassengers = 0;
	_engineType = EngineType::unknown;
	_averageSpeed = 0;
}

Vehicle::Vehicle(const Vehicle& other) {
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept{
	moveFrom(std::move(other));
}

Vehicle::~Vehicle() {
	free();
}

Vehicle::Vehicle(const Tire* tires, unsigned numberOfTires, const EngineType& engineType, unsigned numberOfPassengers, double averageSpeed){
	// Validation
	if (numberOfTires == 0 || tires == nullptr || averageSpeed <= 0) {
		return;
	}

	_numberOfTires = numberOfTires;

	copyTires(tires, numberOfTires);

	_engineType = engineType;
	_numberOfPassengers = numberOfPassengers;
	_averageSpeed = averageSpeed;
}

void Vehicle::setEngineType(const EngineType& engineType) {
	_engineType = engineType;
}

double Vehicle::getTravelTime(const Point& A, const Point& B) const{
	// Use formula S = v.t
	return A.getDist(B) / _averageSpeed;
}

void Vehicle::changeTireAtIndex(const Tire& tire, unsigned ind) {
	if (ind >= _numberOfTires) {
		return;
	}

	_tires[ind] = tire;
}

bool Vehicle::Tire::isValidWidth(ushort width) {
	return width >= MIN_WIDTH && width <= MAX_WIDTH;
}

bool Vehicle::Tire::isValidProfile(ushort profile) {
	return profile >= MIN_PROFILE && profile <= MAX_PROFILE;
}

bool Vehicle::Tire::isValidDiameter(ushort diameter) {
	return diameter >= MIN_RIM_SIZE && diameter <= MAX_RIM_SIZE;
}

Vehicle::Tire::Tire(unsigned ID, MyString manufacturer, MyString description, ushort width, ushort profile, ushort diameter) : CarPart(ID, manufacturer, description) {
	setWidth(width);
	setProfile(profile);
	setRimSize(diameter);
}

ushort Vehicle::Tire::getWidth() const {
	return _width;
}

bool Vehicle::Tire::setWidth(ushort width) {
	if (!isValidWidth(width)) {
		return false;
	}

	_width = width;
	return true;
}

ushort Vehicle::Tire::getProfile() const {
	return _profile;
}

bool Vehicle::Tire::setProfile(ushort profile) {
	if (!isValidProfile(profile)) {
		return false;
	}

	_profile = profile;
	return true;
}

ushort Vehicle::Tire::getRimSize() const {
	return _rim;
}

bool Vehicle::Tire::setRimSize(ushort diameter) {
	if (!isValidDiameter(diameter)) {
		return false;
	}

	_rim = diameter;
	return true;
}

std::ostream& operator << (std::ostream& os, const Vehicle::Tire& t) {
	os << (CarPart)t;
	return os << " - " << t.getWidth() << " / " << t.getProfile() << "R" << t.getRimSize();
}


Vehicle::Point::Point(int x, int y) : x(x), y(y){

}

double Vehicle::Point::getDist(const Point& other) const{
	int dx = x - other.x;
	int dy = y - other.y;

	return sqrt(dx * dx + dy * dy);
}