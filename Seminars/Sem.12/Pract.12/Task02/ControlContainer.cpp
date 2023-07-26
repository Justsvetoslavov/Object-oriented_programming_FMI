#include "ControlContainer.h"

#include <stdexcept>
#include <utility>

#include "ControlFactory.h"

void ControlContainer::free()
{
	for (size_t i = 0; i < this->capacity; i++)
	{
		delete this->controls[i];
	}
	delete[] this->controls;
	this->controls = nullptr;
}

void ControlContainer::copyFrom(const ControlContainer& other)
{
	Control** temp = new Control * [other.capacity];
	for (size_t i = 0; i < other.capacity; i++)
	{
		temp[i] = other.controls[i]->clone();
	}

	this->size = other.size;
	this->capacity = other.capacity;
}

void ControlContainer::moveFrom(ControlContainer&& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->controls = other.controls;
	other.controls = nullptr;

	other.size = 0;
	other.capacity = 0;
}

void ControlContainer::resize()
{
	Control** temp = new Control * [this->capacity*2];
	for (size_t i = 0; i < this->capacity; i++)
	{
		temp[i] = this->controls[i];
	}

	this->controls = temp;
	delete[] this->controls;

	this->capacity *= 2;
}

ControlContainer::ControlContainer()
{
	this->controls = new Control * [this->capacity];
}

ControlContainer::ControlContainer(const ControlContainer& other)
{
	copyFrom(other);
}

ControlContainer& ControlContainer::operator=(const ControlContainer other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ControlContainer::ControlContainer(ControlContainer&& other)
{
	moveFrom(std::move(other));
}

ControlContainer& ControlContainer::operator=(ControlContainer&& other)
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void ControlContainer::addControl(const ControlType controlType)
{
	if (this->size==this->capacity)
	{
		resize();
	}
	this->controls[this->size++] = ControlFactory::genControl(controlType);
}

void ControlContainer::change(const size_t index) const
{
	if (index >= this->size) throw std::range_error("Out of range.");
	this->controls[index]->setDataDialog();
}

Control& ControlContainer::operator[](const size_t index)
{
	return *this->controls[index];
}

ControlContainer::~ControlContainer()
{
	free();
}
