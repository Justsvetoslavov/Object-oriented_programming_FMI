#include "ShapeCollection.h"

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

ShapeCollection::ShapeCollection() {
	capacity = 8;
	shapesCount = 0;
	shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection& other) {
	CopyFrom(other);
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
ShapeCollection::~ShapeCollection() {
	Free();
}

void ShapeCollection::AddShape(const Shape* shape)
{
	if (shapesCount == capacity) {
		Resize();
    }

	shapes[shapesCount++] = shape; //we dont make a copy here (it's a private function, called from creation funcions)
}

void ShapeCollection::AddRectangle(int x1, int y1, int x3, int y3) {
	AddShape(new Rectangle(x1, y1, x3,y3));
}

void ShapeCollection::AddCircle(int x1, int y1, int r) {
	AddShape(new Circle(x1, y1, r));
}

void ShapeCollection::AddTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	AddShape(new Triangle(x1, y1, x2, y2, x3, y3));
}

double ShapeCollection::GetPerOfFigureByIndex(size_t ind) const {
	if (ind >= shapesCount) {
		throw std::out_of_range("Out of range in shapes collection");
    }

	return shapes[ind]->getPer();
}

double ShapeCollection::GetAreaOfFigureByIndex(size_t ind) const
{
	if (ind >= shapesCount) {
		throw std::out_of_range("Out of range in shapes collection");
    }

	return shapes[ind]->getArea();
}

double ShapeCollection::GetIfPointInShapeByIndex(size_t ind, int x, int y) const
{
	if (ind >= shapesCount) {
		throw std::out_of_range("Out of range in shapes collection");
    }

	return shapes[ind]->isPointIn(x, y);
}

void ShapeCollection::Resize() {
	Shape** newCollection = new Shape * [capacity *= 2];
	for (size_t i = 0; i < shapesCount; i++) {
		newCollection[i] = shapes[i]; // !!не правим клониране
    }
    
	delete[] shapes;
	shapes = newCollection;
}

void ShapeCollection::Free()
{
	for (size_t i = 0; i < shapesCount; ++i) {
		delete shapes[i];  
    }

	delete[] shapes;
}

void ShapeCollection::CopyFrom(const ShapeCollection& other) {
	shapes = new Shape* [other.shapesCount];
	shapesCount = other.shapesCount;
	capacity = other.capacity;

	for (size_t i = 0; i < shapesCount; ++i) {
		shapes[i] = other.shapes[i]->clone();
	}
}
