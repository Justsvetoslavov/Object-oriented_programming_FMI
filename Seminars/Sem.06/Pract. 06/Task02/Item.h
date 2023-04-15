#pragma once
class Item {
private:
	char* name = nullptr;
	bool isAvailable = false;
	double price = 0;

public:
	Item();
	Item(const char* name, bool isAvailable, double price);
	Item(const Item& other);
	Item& operator=(const Item& other);
	~Item();

	void SetName(const char* name);
	void SetAvailability(bool isAvailable);
	void SetPrice(double price);

	const char* GetName() const;
	bool GetAvailability() const;
	double GetPrice() const;
		 
private:
	void copyFrom(const Item& other);
	void free();
};

