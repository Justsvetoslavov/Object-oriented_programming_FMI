#pragma once
#include "Game.h"

const size_t maxAmountOfGames = 16;

class GamePlatform
{
private:
	Game games[maxAmountOfGames];
	size_t currAmountOfGames = 0;
public:
	GamePlatform() = default;
	~GamePlatform() = default;

	void addGame();
	void getGame(size_t index) const;
	void printAllGames() const;
	void getTheCheapestGame() const;
	void getTheMostExpensiveGame() const;
	void printAllFreeGames() const;
	void removeGame(size_t index);

private:
	bool enoughSpace() const;
	Game& createGame();
};