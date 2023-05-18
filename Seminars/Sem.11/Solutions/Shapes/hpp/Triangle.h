#pragma once

#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

	double GetArea() const override;
	double GetPer() const override;
	bool IsPointIn(int x, int y) const override;
};