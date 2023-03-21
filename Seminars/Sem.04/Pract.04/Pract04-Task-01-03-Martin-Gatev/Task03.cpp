#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;

const size_t MAX_TITLE_LENGTH = 64;
const size_t MAX_GAMES = 50;

void myStrCopy(char* str1, const char* str2)
{
	int counter{};

	while (str2[counter] != '\0')
	{
		str1[counter] = str2[counter];
		counter++;
	}

	str1[counter] = '\0';
}

class Game {
private:
	double price;
	char title[MAX_TITLE_LENGTH + 1];
	bool isAvailable;
public:
	Game()
	{
		price = 0;
		title[0] = '\0';
		isAvailable = true;
	}

	Game(const double& price, const char* title, const bool& isAvailable)
	{
		this->price = price;
		myStrCopy(this->title, title);
		this->isAvailable = isAvailable;
	}

	Game(const char* title)
	{
		myStrCopy(this->title, title);
		price = 0;
		isAvailable = true;
	}

	Game(const double& price, const char* title)
	{
		this->price = price;
		myStrCopy(this->title, title);
		isAvailable = true;
	}

	const char* getTitle()const
	{
		return title;
	}

	double getPrice()const
	{
		return price;
	}

	bool getAvailability()const
	{
		return isAvailable;
	}

	void setTitle(const char* title)
	{
		myStrCopy(this->title, title);
	}

	void setPrice(const double& price)
	{
		this->price = price;
	}

	void setAvailability(const bool& isAvailable)
	{
		this->isAvailable = isAvailable;
	}

	bool isFree()const
	{
		return (this->price == 0);
	}

	void printGame()
	{
		cout << "Title: " << this->title << endl;
		cout << "Price: " << this->price << endl;
		cout << "Availability: " << this->isAvailable << endl;
	}
};

class GamePlatform {
private:
	Game games[MAX_GAMES];
	short size;
public:
	void changeSize(const size_t& newSize)
	{
		this->size = newSize;
	}

	void addGame(const Game& game)
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

	void printGameIndex(const size_t& position)
	{
		games[position].printGame();
	}

	void printAllGames()
	{
		for (int i = 0; i < size; i++)
		{
			games[i].printGame();
		}
	}

	void printCheapestGame()
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

	void printFreeGames()
	{
		for (size_t i = 0; i < size; i++)
		{
			if (games[i].isFree())
			{
				games[i].printGame();
			}
		}
	}

	void deleteGame(const size_t& position)
	{
		games[position].setTitle("\0");
		games[position].setAvailability(true);
		games[position].setPrice(0);
	}

	void saveToFile(std::ofstream& out)
	{
		for (size_t i = 0; i < size; i++)
		{
			out << "Name: " << games[i].getTitle() << endl;

			out << "Price: " << games[i].getPrice() << endl;

			out << "Availability: " << games[i].getAvailability() << endl << endl;
		}
	}

	void readFromFile(std::ifstream& input, GamePlatform& games)
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

};
