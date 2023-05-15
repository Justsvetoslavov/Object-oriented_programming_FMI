#include <iostream>
#include "Game.h"
#include "GamePlatform.h"

int main()
{
	GamePlatform library;
	library.addGame();
	library.printAllGames();
	library.removeGame(1);
	library.printAllGames();
	return 0;
}