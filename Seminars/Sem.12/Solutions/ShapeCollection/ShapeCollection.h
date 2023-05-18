#pragma once

#include "Shape.h"

class ShapeCollection {
private:
	Shape** shapes;
	size_t shapesCount;
	size_t capacity;
public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);
	~ShapeCollection();

	void AddRectangle(int, int, int, int);
	void AddCircle(int, int, int );
	void AddTriangle(int, int, int, int, int, int);

	double GetPerOfFigureByIndex(size_t) const;
	double GetAreaOfFigureByIndex(size_t) const;
	double GetIfPointInShapeByIndex(size_t, int, int) const;
private:
	void Resize();
	void AddShape(const Shape* shape);
	
	void Free();
	void CopyFrom(const ShapeCollection& other);

};