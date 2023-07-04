#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>
#include "Game.h"

Game::Game() : Game((char*)" ", 0) {}

Game::Game(char* title, float price)
{
	setTitle(title);
	setPrice(price);
	this->isAvailabe = true;
}
Game::Game(const Game& other)
{
	copyFrom(other);
}
Game& Game::operator=(const Game& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
Game::~Game()
{
	free();
}

char* Game::getTitle() const
{
	return title;
}
float Game::getPrice() const
{
	return price;
}
bool Game::getIsAvailable() const
{
	return isAvailabe;
}

void Game::setTitle(char* title)
{
	unsigned size = 0;
	while (title[size] != '\0')
	{
		size += 1;
	}
	size += 1;
	this->title = new char[size];
	int index = 0;
	while (title[index] != '\0')
	{
		this->title[index] = title[index];
		index += 1;
	}
}
void Game::setPrice(float price)
{
	this->price = price;
}

bool Game::isFree() const
{
	return  price == 0;
}
void Game::print() const
{
	std::cout << "Title: " << title << '\n';
	std::cout << "Price: " << std::setprecision(4) << price << '\n' << std::fixed;
	std::cout << "Availabe: " << (isAvailabe ? "Yes" : "No") << '\n';
}

void Game::free()
{
	delete[] title;
}
void Game::copyFrom(const Game& other)
{
	setTitle(other.getTitle());
	setPrice(other.getPrice());
	this->isAvailabe = other.isAvailabe;
}

