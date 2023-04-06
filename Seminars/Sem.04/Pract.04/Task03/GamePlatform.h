#pragma once
#include "Game.h"

const int GAMES_MAX_COUNT = 15;

class GamePlatform {
private:
	Game games[GAMES_MAX_COUNT];
	size_t gamesCount = 0;
public:
	GamePlatform() = default;
	GamePlatform(const Game* games, int gamesCount);

	size_t GetGamesCount() const;
	const Game GetGameByID(int id) const;
	const Game ReturnCheapestGame() const;
	const Game ReturnMostExpensiveGame() const;

	bool AddGame(const Game& game);
	void RemoveGameFromLibrary(const Game& game);

	void WriteGamePlatformToFile(const char* filePath) const;
	void ReadGamePlatformFromFile(const char* filePath);

	void PrintAllGames() const;
	void PrintAllFreeGames() const;
private:
	void CheckIfThereAreAnyGames() const;
};
