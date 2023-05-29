#pragma once
#include "String.h"

class CarPart {
	static size_t nextId;
	size_t id = GetNextId();
	String manifacturerName;
	String description;

	static size_t GetNextId();

public:
	size_t getId() const;
	const String& getManifacturerName() const;
	const String& getDescription() const;

	void SetManifacturerName(const String& name);
	void SetDescription(const String& desc);

	friend std::ostream& operator<<(std::ostream& os, const CarPart& carPart);
};