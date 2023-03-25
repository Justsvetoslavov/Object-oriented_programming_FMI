#pragma once

#include<iostream>
#include<fstream>

using std::cout;
using std::endl;

class Game {
private:
	double price;
	char* title;
	bool isAvailable;
public:
	Game();

	Game(const double& price, const char* title, const bool& isAvailable);

	Game(const char* title);

	Game(const double& price, const char* title);

	Game(const Game& other);

	Game& operator=(const Game& other);

	const char* getTitle()const;

	double getPrice()const;

	bool getAvailability()const;

	void setTitle(const char* title);

	void setPrice(const double& price);

	void setAvailability(const bool& isAvailable);

	bool isFree()const;

	void printGame();

	~Game();
};