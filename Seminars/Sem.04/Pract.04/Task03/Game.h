#pragma once

const char TITLE_MAX_SIZE = 64;
const int CHEAPEST_PRICE = 100000;
const int MOST_EXPENSIVE_PRICE = -100000;
const int FIELD_MAX_SIZE = 256;

class Game {
private:
	double price;
	bool isAvailable;
	char title[TITLE_MAX_SIZE + 1];
public:
	Game();
	Game(const char* title, double price, bool isAvailable);

	const char* GetTitle() const;
	double GetPrice() const;
	bool GetAvailability() const;

	bool SetTitle(const char* title);
	bool SetPrice(double price);
	void SetAvailability(bool isAvailable);

	bool IsFree() const;
	void Print() const;
	bool IsEqualTo(const Game& game) const;
private:
	bool IsInvalidTitle(const char* title) const;
	bool IsInvalidPrice(double price) const;
};