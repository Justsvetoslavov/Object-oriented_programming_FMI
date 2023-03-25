#include <iostream>
#include <cstring>
#include <fstream>

const unsigned title_max_size = 64;
const unsigned game_library_max_size = 20;
const char file_Name[17] = "gamesLibrary.txt";

int LengthOfWord(const char* word);
bool AreWordsEqual(const char* first, const char* second);
bool IsFileOpened(std::ofstream& file);
bool IsFileOpened(std::ifstream& file);

class Game {
private:
	char title[title_max_size + 1];
	double price;
	bool isAvailable;
public:
	Game();
	Game(const char* title, double price, bool isAvailable);

	const char* GetTitle() const;
	double GetPrice() const;
	bool GetAvailability() const;

	void SetTitle(const char* title);
	void SetPrice(double price);
	void SetAvailability(bool isAvailable);

	bool IsFree() const;
	void Print() const;
};

Game::Game() : Game("Unknown", 0, 0) {}

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

void Game::SetTitle(const char* title) {
	if (LengthOfWord(title) > 64) {
		std::cout << "Title cannot exceed 64 symbols!";
		strcpy_s(this->title, "Error");
	}
	else
		strcpy_s(this->title, title);
}

void Game::SetPrice(double price) {
	while (price < 0)
	{
		std::cout << "Price cannot be a negative value! Please enter a new one: ";
		std::cin >> price;
	}
	this->price = price;
}

void Game::SetAvailability(bool isAvailable) {
	this->isAvailable = isAvailable;
}

bool Game::IsFree() const {
	if (price == 0)
		return true;
	else
		return false;
}

void Game::Print() const {
	std::cout << "Title: " << title << std::endl;
	std::cout << "Price: " << price << std::endl;
	if (isAvailable)
		std::cout << "The game is available\n";
	else
		std::cout << "The game is not available\n";
}

class GamePlatform {
private:
	Game games[game_library_max_size + 1];
	int countOfGames = 0;
public:
	int GetCountOfGames() const;
	void AddGame(const Game& game);
	int PrintIndexOfGame(const Game& game) const;
	void PrintAllGames() const;
	void PrintCheapestAndMostExpensive() const;
	void PrintAllFreeGames() const;
	void RemoveGame(const Game& game);
	void SaveGamesToFile() const;
	void ReadGamesFromFile();
};

int GamePlatform::GetCountOfGames() const {
	return countOfGames;
}

void GamePlatform::AddGame(const Game& game) {
	if (countOfGames < 20)
		games[countOfGames++] = game;
	else
		std::cout << "There is no more space in the library!";
}

int GamePlatform::PrintIndexOfGame(const Game& game) const {
	for (int i = 0; i < countOfGames; i++)
		if (AreWordsEqual(games[i].GetTitle(), game.GetTitle())) {
			return i;
		}
}

void GamePlatform::PrintAllGames() const {
	for (int i = 0; i < countOfGames; i++)
		games[i].Print();
}

void GamePlatform::PrintCheapestAndMostExpensive() const {
	if (countOfGames == 1)
	{
		std::cout << "There is only one game in the library";
		return;
	}
	double cheapest = games[0].GetPrice();
	double mostExpensive = games[0].GetPrice();
	int cheapestIndex = 0, mostExpensiveIndex = 0;
	for (int i = 1; i < countOfGames; i++) {
		if (games[i].GetPrice() < cheapest)
		{
			cheapest = games[i].GetPrice();
			cheapestIndex = i;
		}
		else if (games[i].GetPrice() > mostExpensive)
		{
			mostExpensive = games[i].GetPrice();
			mostExpensiveIndex = i;
		}
	}
	std::cout << "Most expensive game is: \n";
	games[mostExpensiveIndex].Print();
	std::cout << "Least expensive game is: \n";
	games[cheapestIndex].Print();
}

void GamePlatform::PrintAllFreeGames() const {
	bool areThereFreeGames = false;
	for (int i = 0; i < countOfGames; i++) {
		if (games[i].IsFree())
		{
			games[i].Print();
			areThereFreeGames = true;
		}
	}
	if (!areThereFreeGames)
		std::cout << "There are no free games!";
}

void GamePlatform::RemoveGame(const Game& game) {
	for (int i = 0; i < countOfGames; i++) {
		if (AreWordsEqual(games[i].GetTitle(), game.GetTitle()))
		{
			for (int index = i; index < countOfGames - 1; index++) {
				games[index] = games[index + 1];
			}
			countOfGames--;
			break;
		}
	}
}

void GamePlatform::SaveGamesToFile() const {
	std::ofstream file(file_Name);
	if (!IsFileOpened(file))
		return;
	for (int i = 0; i < countOfGames; i++) {
		file
			<< games[i].GetTitle() << ", "
			<< games[i].GetPrice() << ", "
			<< games[i].GetAvailability();
		if(i != countOfGames - 1)
			file << '\n';
	}
	file.close();
}

void GamePlatform::ReadGamesFromFile() {
	std::ifstream file(file_Name);
	if (!IsFileOpened(file))
		return;
	while (true) {
		if (file.eof())
			break;
		Game game;
		char buff[title_max_size];
		file.getline(buff, title_max_size + 1, ',');
		game.SetTitle(buff);
		file.ignore();
		file.getline(buff, 6, ',');
		game.SetPrice(strtod(buff, nullptr));
		file.ignore();
		game.SetAvailability(file.get());
		games[countOfGames++] = game;
		file.ignore();
	}
	file.close();
}

bool IsFileOpened(std::ofstream& file) {
	if (!file.is_open()) {
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

bool IsFileOpened(std::ifstream& file) {
	if (!file.is_open()) {
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

bool AreWordsEqual(const char* first, const char* second) {
	int i = 0;
	for (i; first[i] != '\0' && second[i] != '\0'; i++)
		if (first[i] != second[i])
			return false;
	if ((first[i] == '\0' && second[i] != '\0') || (first[i] != '\0' && second[i] == '\0'))
		return false;
	return true;
}

int LengthOfWord(const char* word) {
	int length = 0;
	for (int i = 0; word[i] != '\0'; i++)
		length++;
	return length;
}

int main()
{
	Game game1("Living in the clouds", 23.99, 1);
	Game game2("Find the way: 2", 0, 1);
	Game game3("Glowing", 10, 0);
	Game game4("Paint the rainbow", 0, 1);
	GamePlatform library;
	library.AddGame(game1);
	library.AddGame(game2);
	library.AddGame(game3);
	library.AddGame(game4);
	std::cout << "Index of " << game3.GetTitle() << " game is: " << library.PrintIndexOfGame(game3) << std::endl;
	std::cout << "\nPrinting all games: \n";
	library.PrintAllGames();
	library.PrintCheapestAndMostExpensive();
	std::cout << "\nPrinting all free games: \n";
	library.PrintAllFreeGames();
	library.RemoveGame(game2);
	GamePlatform copiedLibrary;
	library.SaveGamesToFile();
	copiedLibrary.ReadGamesFromFile();
}