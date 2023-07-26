#pragma once
#include "Control.h"

class ControlContainer
{
	Control** controls = nullptr;

	size_t size = 0;
	size_t capacity = 4;

	void free();
	void copyFrom(const ControlContainer& other);
	void moveFrom(ControlContainer&& other);
	void resize();

public:
	ControlContainer();

	ControlContainer(const ControlContainer& other);
	ControlContainer& operator=(const ControlContainer& other);
	ControlContainer(ControlContainer&& other);
	ControlContainer& operator=(ControlContainer&& other);

	void addControl(ControlType controlType);

	void change(size_t index) const;

	Control& operator[](size_t index);

	~ControlContainer();
};

