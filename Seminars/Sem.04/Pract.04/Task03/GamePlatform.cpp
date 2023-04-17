#include "GamePlatform.h"
#include <iostream>
#include <fstream>
#include <sstream>

GamePlatform::GamePlatform(const Game* games, int gamesCount) {
	this->gamesCount = gamesCount;

	for (size_t i = 0; i < gamesCount; ++i) {
		this->games[i] = games[i];
	}
}

size_t GamePlatform::GetGamesCount() const {
	return gamesCount;
}

const Game GamePlatform::GetGameByID(int id) const {
	Game nullGame;
	if (id < 0 || id >= gamesCount) {
		std::cout << "Invalid id!" << std::endl;
		return nullGame;
	}

	return games[id];
}

bool GamePlatform::AddGame(const Game& game) {
	if (this->gamesCount < GAMES_MAX_COUNT) {
		this->games[gamesCount++] = game;
		return true;
	}
	std::cout << "Not enough space for this game!" << std::endl;
	return false;
}

const Game GamePlatform::GetGameByID(int id) const {
	Game nullGame;
	if (id < 0 || id >= this->gamesCount) {
		std::cout << "Invalid id!" << std::endl;
		return nullGame;
	}

	return this->games[id];
}

void GamePlatform::PrintAllGames() const {
	for (size_t i = 0; i < gamesCount; ++i) {
		games[i].Print();
	}
}

const Game GamePlatform::ReturnCheapestGame() const {
	CheckIfThereAreAnyGames(); //TO DO: Handle this scenario in a better way

	int cheapestPrice = CHEAPEST_PRICE;
	Game cheapestGame;
	for (size_t i = 0; i < gamesCount; ++i) {
		if (games[i].GetPrice() < cheapestPrice) {
			cheapestPrice = games[i].GetPrice();
			cheapestGame = games[i];
		}
	}

	return cheapestGame;
}

const Game GamePlatform::ReturnMostExpensiveGame() const {
	CheckIfThereAreAnyGames();  //TO DO: Handle this scenario in a better way

	int mostExpPrice = MOST_EXPENSIVE_PRICE;
	Game mostExpGame;
	for (size_t i = 0; i < gamesCount; ++i) {
		if (games[i].GetPrice() > mostExpPrice) {
			mostExpPrice = games[i].GetPrice();
			mostExpGame = games[i];
		}
	}
	return mostExpGame;
}

void GamePlatform::PrintAllFreeGames() const {
	CheckIfThereAreAnyGames();  //TO DO: Handle this scenario in a better way

	int freeGamesCount = 0;
	for (size_t i = 0; i < this->gamesCount; i++) {
		if (games[i].GetPrice() == 0) {
			games[i].Print();
			freeGamesCount++;
		}
	}

	if (freeGamesCount == 0) {
		std::cout << "No free games!" << std::endl;
	}
}

void GamePlatform::RemoveGameFromLibrary(const Game& game) {
	CheckIfThereAreAnyGames(); //TO DO: Handle this scenario in a better way

	int removedGamesCount = 0;
	for (size_t i = 0; i < gamesCount; ++i) {
		if (game.IsEqualTo(games[i])) {
			for (size_t j = i; j < gamesCount; ++j) {
				games[j] = games[j + 1];
				removedGamesCount++;
			}
			gamesCount--;
			break;
		}
	}
	if (removedGamesCount == 0) {
		std::cout << "Couldn't find this game in the library!" << std::endl;
	}
}

void GamePlatform::WriteGamePlatformToFile(const char* filePath) const {
	CheckIfThereAreAnyGames(); //TO DO: Handle this scenario in a better way

	std::ofstream writeFile(filePath, std::ios::out);
	if (!writeFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	writeFile << gamesCount << std::endl;
	for (size_t i = 0; i < gamesCount; i++)
	{
		writeFile << games[i].GetTitle() << ","
			<< games[i].GetPrice() << ","
			<< games[i].GetAvailability() << std::endl;
	}

	writeFile.close();
}

void GamePlatform::ReadGamePlatformFromFile(const char* filePath) {
	std::ifstream readFile(filePath, std::ios::in);
	GamePlatform gamePlatform;
	if (!readFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	int gamesCount;
	readFile >> gamesCount;
	char buffer[FIELD_MAX_SIZE];
	readFile.ignore();
	for (size_t i = 0; i < gamesCount; i++) {
		readFile.getline(buffer, FIELD_MAX_SIZE);

		std::stringstream ss;
		ss << buffer;

		char titleBuffer[FIELD_MAX_SIZE];
		ss.getline(titleBuffer, FIELD_MAX_SIZE, ',');
		char priceBuffer[FIELD_MAX_SIZE];
		ss.getline(priceBuffer, FIELD_MAX_SIZE, ',');
		char availabilityBuffer[FIELD_MAX_SIZE];
		ss.getline(availabilityBuffer, FIELD_MAX_SIZE, ',');

		gamePlatform.games[i].SetTitle(titleBuffer);
		gamePlatform.games[i].SetPrice(atof(priceBuffer));
		gamePlatform.games[i].SetAvailability(availabilityBuffer);
		gamePlatform.gamesCount++;
	}

	for (size_t i = 0; i < gamePlatform.gamesCount; i++) {
		this->games[i] = gamePlatform.games[i];
	}

	this->gamesCount = gamePlatform.gamesCount;
	readFile.close();
}

void GamePlatform::CheckIfThereAreAnyGames() const {
	if (gamesCount == 0) {
		std::cout << "There are no games in this library!";
		return;
	}
}