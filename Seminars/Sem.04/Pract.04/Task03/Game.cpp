#include "Game.h"
#include <iostream>
#include <cstring>

const char MESSAGE_UNKNOWN[] = "Unknown";

Game::Game() : Game(MESSAGE_UNKNOWN, 0, 0) {}

Game::Game(const char* title, double price, bool isAvailable) {
	SetTitle(title);
	SetPrice(price);
	SetAvailability(isAvailable);
}

const char* Game::GetTitle() const {
	return title;
}

double Game::GetPrice() const {
	return price;
}

bool Game::GetAvailability() const {
	return isAvailable;
}

bool Game::SetTitle(const char* title) {
	if (IsInvalidTitle(title)) {
		return false;
	}

	strcpy(this->title, title);
	return true;
}

bool Game::SetPrice(double price) {
	if (IsInvalidPrice(price)) {
		return false;
	}

	this->price = price;
	return true;
}

void Game::SetAvailability(bool isAvailable) {
	this->isAvailable = isAvailable;
}

bool Game::IsFree() const {
	return price == 0;
}

void Game::Print() const {
	std::cout << "Game title: " << title << std::endl;
	std::cout << "Game price: " << price << std::endl;
	std::cout << "Is game available: " << isAvailable << std::endl;
}

bool CompareDoubles(double d1, double d2) {
	return abs(d1 - d2) < DBL_EPSILON;
}

bool Game::IsEqualTo(const Game& game) const {
	if (!strcmp(this->GetTitle(), game.GetTitle())
		&& this->GetAvailability() == game.GetAvailability()
		&& CompareDoubles(this->GetPrice(), game.GetPrice())) {
		return true;
	}

	return false;
}

bool Game::IsInvalidTitle(const char* title) const {
	return (strlen(title) > FIELD_MAX_SIZE || !title);
}

bool Game::IsInvalidPrice(double price) const {
	return (price > CHEAPEST_PRICE || price < 0);
}