#pragma once

#include "Game.h"

const size_t MAX_GAMES = 50;

class GamePlatform {
private:
	Game games[MAX_GAMES];
	short size;
public:
	void changeSize(const size_t& newSize);

	void addGame(const Game& game);

	void printGameIndex(const size_t& position);

	void printAllGames();

	void printCheapestGame();

	void printFreeGames();

	void deleteGame(const size_t& position);

	void saveToFile(std::ofstream& out)const;

	void readFromFile(std::ifstream& input, GamePlatform& games);

};