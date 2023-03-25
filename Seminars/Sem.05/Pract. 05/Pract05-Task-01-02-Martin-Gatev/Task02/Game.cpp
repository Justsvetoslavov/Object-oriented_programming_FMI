#include "Game.h"

namespace {
	void myStrCopy(char* str1, const char* str2)
	{
		int counter{};

		while (str2[counter] != '\0')
		{
			str1[counter] = str2[counter];
			counter++;
		}

		str1[counter] = '\0';
	}
}

Game::Game()
{
	price = 0;
	title = nullptr;
	isAvailable = true;
}

Game::Game(const double& price, const char* title, const bool& isAvailable)
{
	this->price = price;
	myStrCopy(this->title, title);
	this->isAvailable = isAvailable;
}

Game::Game(const char* title)
{
	myStrCopy(this->title, title);
	price = 0;
	isAvailable = true;
}

Game::Game(const double& price, const char* title)
{
	this->price = price;
	myStrCopy(this->title, title);
	isAvailable = true;
}

Game::Game(const Game& other)
{
	this->price = other.price;
	myStrCopy(this->title, other.title);
	this->isAvailable = other.title;
}

Game& Game::operator=(const Game& other)
{
	if (this == &other)
		return *this;

	int otherSize = strlen(other.title);
	int thisSize = strlen(this->title);

	if (thisSize != otherSize)
	{
		delete[] this->title;
		this->title = new char[otherSize];
		myStrCopy(this->title, other.title);
	}

	this->price = other.price;
	this->isAvailable = other.isAvailable;

	return *this;
}

const char* Game::getTitle()const
{
	return title;
}

double Game::getPrice()const
{
	return price;
}

bool Game::getAvailability()const
{
	return isAvailable;
}

void Game::setTitle(const char* title)
{
	myStrCopy(this->title, title);
}

void Game::setPrice(const double& price)
{
	this->price = price;
}

void Game::setAvailability(const bool& isAvailable)
{
	this->isAvailable = isAvailable;
}

bool Game::isFree()const
{
	return (this->price == 0);
}

void Game::printGame()
{
	cout << "Title: " << this->title << endl;
	cout << "Price: " << this->price << endl;
	cout << "Availability: " << this->isAvailable << endl;
}

Game::~Game()
{
	delete[] title;
}