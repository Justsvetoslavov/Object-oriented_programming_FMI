#include <iostream>
#include "GamePlatform.h"

void GamePlatform::addGame()
{
	if (!enoughSpace())
	{
		std::cout << "There is no enough space in the library!\n";
		return;
	}
	Game temp = createGame();
	this->games[this->currAmountOfGames] = temp;
	this->currAmountOfGames += 1;
}
void GamePlatform::getGame(size_t index) const
{
	if (index >= currAmountOfGames)
	{
		std::cout << "Error: No such index! \n";
		return;
	}
	games[index].print();
	return;
}
void GamePlatform::printAllGames() const
{
	if (currAmountOfGames == 0)
	{
		std::cout << "There is no games in the library!\n";
		return;
	}
	for (size_t i = 0; i < currAmountOfGames; i++)
	{
		std::cout << i + 1 << " game\n";
		games[i].print();
	}
}
void GamePlatform::getTheCheapestGame() const
{
	size_t index = 0;
	float min = FLT_MAX;
	for (size_t i = 0; i < currAmountOfGames; i++)
	{
		if (games[index].getPrice() < min)
		{
			min = games[index].getPrice();
			index = i;
		}
	}
	std::cout << "The cheapest games is: " << games[index].getTitle();
}
void GamePlatform::getTheMostExpensiveGame() const
{
	size_t index = 0;
	float min = FLT_MIN;
	for (size_t i = 0; i < currAmountOfGames; i++)
	{
		if (games[index].getPrice() < min)
		{
			min = games[index].getPrice();
			index = i;
		}
	}
	std::cout << "The most expensive games is: " << games[index].getTitle();
}
void GamePlatform::printAllFreeGames() const
{
	for (size_t i = 0; i < currAmountOfGames; i++)
	{
		if (games[i].getPrice() == 0)
		{
			games[i].print();
		}
	}
}
void GamePlatform::removeGame(size_t index)
{
	currAmountOfGames -= 1;
}

bool GamePlatform::enoughSpace() const
{
	return currAmountOfGames + 1 <= 16;
}

Game& GamePlatform::createGame()
{
	char buffer[1024];
	float price;
	std::cout << "Enter the title of the game: ";
	std::cin.getline(buffer, 1024);
	std::cout << "Enter game's price: ";
	std::cin >> price;
	Game g;
	g.setTitle(buffer);
	g.setPrice(price);
	return g;
}