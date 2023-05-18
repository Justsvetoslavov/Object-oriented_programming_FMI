#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	Circle(int x, int y, double radius);

	double GetArea() const override;
	double GetPer() const override; 
	bool IsPointIn(int x, int y) const override;
};