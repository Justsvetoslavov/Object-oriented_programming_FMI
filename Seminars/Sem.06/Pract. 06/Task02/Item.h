#pragma once
#include <fstream>
class Item
{
private:
	char* name = nullptr;
	bool isAvailable = false;
	double price = 0;

public:
	Item() = default;
	Item(const char* name, bool isAvailable, double price);
	Item(const Item& other);
	Item& operator=(const Item& other);
	~Item();

	const char* GetName() const;
	bool IsAvailable() const;
	double GetPrice() const;

	void SetName(const char* name);
	void SetAvailability(bool availability);
	void SetPrice(double price);

	void SaveItem(std::ofstream& writeFile) const;
private:
	void CopyFrom(const Item& other);
	void Free();
};

