// Solution by Venelina & Manoela

#include "GamePlatform.h"
#include <iostream>

int main()
{
	Game games[] = {
		Game("game1", 14.40, true),
		Game("game2", 0, false)
	};

	GamePlatform gamePlatform(games, 2);

	Game game1("game3", 12.45, false);
	Game game2("game4", 13.45, true);

	std::cout << "All games are: " << std::endl;
	gamePlatform.PrintAllGames();
	gamePlatform.AddGame(game1);
	gamePlatform.AddGame(game2);

	std::cout << "Added two more games: " << std::endl;
	gamePlatform.PrintAllGames();

	std::cout << "Most expensive game is: " << std::endl;
	gamePlatform.ReturnMostExpensiveGame().Print();

	std::cout << "All free games are: " << std::endl;
	gamePlatform.PrintAllFreeGames();

	gamePlatform.RemoveGameFromLibrary(game1);

	std::cout << "Removed game3 from library." << std::endl;
	gamePlatform.PrintAllGames();

	std::cout << "The game with index 1 is: " << std::endl;
	gamePlatform.GetGameByID(1).Print();

	gamePlatform.WriteGamePlatformToFile(FILE_PATH);

	GamePlatform gamePlatform2;
	gamePlatform2.ReadGamePlatformFromFile(FILE_PATH);
	std::cout << "Games read from file: " << std::endl;
	gamePlatform2.PrintAllGames();
}