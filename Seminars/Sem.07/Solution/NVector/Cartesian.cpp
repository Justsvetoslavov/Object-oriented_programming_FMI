#include "Cartesian.h"

Cartesian2D::Cartesian2D(const Nvector& first, const Nvector& second) {
	this->first = first;
	this->second = second;
}

Nvector Cartesian2D::getVectorByCoordinates(const Nvector& other) const {
	double coordinates[2];
	coordinates[0] = other[0] * first[0] + other[1] * second[0];
	coordinates[1] = other[0] * first[1] + other[1] * second[1];
	Nvector temp(coordinates, 2);
	return temp;
}

Nvector Cartesian2D::getCoordinatesByVector(const Nvector& other) const {
	double coordinates[2];
	coordinates[1] = (first[0] * other[1] - first[1] * other[0]) / (first[0] * second[1] - first[1] * second[0]);
	coordinates[0] = (other[0] - (second[0] * coordinates[1]))/first[0];
	Nvector temp(coordinates,2);
	return temp;
}
