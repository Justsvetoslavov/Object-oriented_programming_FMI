#include "GamePlatform.h"

void GamePlatform::changeSize(const size_t& newSize)
{
	this->size = newSize;
}

void GamePlatform::addGame(const Game& game)
{
	if (size < MAX_GAMES)
	{
		games[size] = game;
	}
	else
	{
		return;
	}
}

void GamePlatform::printGameIndex(const size_t& position)
{
	games[position].printGame();
}

void GamePlatform::printAllGames()
{
	for (int i = 0; i < size; i++)
	{
		games[i].printGame();
	}
}

void GamePlatform::printCheapestGame()
{
	size_t temp = games[0].getPrice();
	size_t temp2{};

	for (int i = 1; i < size; i++)
	{
		temp2 = games[i].getPrice();

		if (temp > temp2)
		{
			temp = temp2;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (temp == games[i].getPrice())
		{
			games[i].printGame();
		}
	}
}

void GamePlatform::printFreeGames()
{
	for (size_t i = 0; i < size; i++)
	{
		if (games[i].isFree())
		{
			games[i].printGame();
		}
	}
}

void GamePlatform::deleteGame(const size_t& position)
{
	games[position].setTitle("\0");
	games[position].setAvailability(true);
	games[position].setPrice(0);
}

void GamePlatform::saveToFile(std::ofstream& out)const
{
	for (size_t i = 0; i < size; i++)
	{
		out << "Name: " << games[i].getTitle() << endl;

		out << "Price: " << games[i].getPrice() << endl;

		out << "Availability: " << games[i].getAvailability() << endl << endl;
	}
}

void GamePlatform::readFromFile(std::ifstream& input, GamePlatform& games)
{
	const size_t MAX_BUFFER_SIZE = 100;

	char tempBuffer[MAX_BUFFER_SIZE], buffer[MAX_BUFFER_SIZE];

	size_t gamesSize{};

	Game tempGame;

	while (!input.eof())
	{
		input.getline(tempBuffer, MAX_BUFFER_SIZE, ': ');
		input.getline(buffer, MAX_BUFFER_SIZE, '\n');
		tempGame.setTitle(buffer);
		input.getline(tempBuffer, MAX_BUFFER_SIZE, ': ');
		input.getline(buffer, MAX_BUFFER_SIZE, '\n');
		double price = atof((const char*)buffer);
		tempGame.setPrice(price);
		input.getline(tempBuffer, MAX_BUFFER_SIZE, ': ');
		input.getline(buffer, MAX_BUFFER_SIZE, '\n');
		if (buffer[0] == '0')
		{
			tempGame.setAvailability(0);
		}
		else if (buffer[0] == '1')
		{
			tempGame.setAvailability(1);
		}

		gamesSize++;
		games.addGame(tempGame);
		games.changeSize(gamesSize);
	}
}