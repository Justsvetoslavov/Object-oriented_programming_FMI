#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning (disable : 4996)

const char TITLE_MAX_SIZE = 64;
const int GAMES_MAX_COUNT = 15;
const int CHEAPEST_PRICE = 100000;
const int MOST_EXPENSIVE_PRICE = -100000;
const double EPSILON = 0.000001;
const int FIELD_MAX_SIZE = 256;

const char MESSAGE_UKNOWN[] = "Uknown";
const char FILE_PATH[] = "gamePlatform.txt";

class Game {
private:
	char title[TITLE_MAX_SIZE + 1];
	double price;
	bool isAvailable;

	bool IsInvalidTitle(const char* title) const;
	bool IsInvalidPrice(double price) const;
public:
	Game();
	Game(const char* title, double price, bool isAvailable);

	const char* GetTitle() const;
	double GetPrice() const;
	bool GetAvailability() const;

	void SetTitle(const char* title);
	void SetPrice(double price);
	void SetAvailability(bool isAvailable);

	bool IsFree();
	void Print() const;
	bool IsEqualTo(const Game& game) const;
};

class GamePlatform {
private:
	Game games[GAMES_MAX_COUNT];
	int gamesCount = 0;

	void CheckIfThereAreAnyGames() const;

public:
	GamePlatform();
	GamePlatform(const Game* games, int gamesCount);
	int GetGamesCount() const;

	void AddGame(const Game& game);
	const Game GetGameByID(int id) const;
	void PrintAllGames() const;
	const Game ReturnCheapestGame() const;
	const Game ReturnMostExpensiveGame() const;
	void PrintAllFreeGames() const;
	void RemoveGameFromLibrary(const Game& game);
	void WriteGamePlatformToFile(const char* filePath) const;
	void ReadGamePlatformFromFile(const char* filePath);

};

Game::Game() : Game(MESSAGE_UKNOWN, 0, 0) {}

Game::Game(const char* title, double price, bool isAvailable) {
	SetTitle(title);
	SetPrice(price);
	SetAvailability(isAvailable);
}

const char* Game::GetTitle() const {
	return this->title;
}

double Game::GetPrice() const {
	return this->price;
}

bool Game::GetAvailability() const {
	return this->isAvailable;
}

void Game::SetTitle(const char* title) {
	if (IsInvalidTitle(title)) return;

	strcpy(this->title, title);
}

void Game::SetPrice(double price) {
	if (IsInvalidPrice(price)) return;

	this->price = price;
}

void Game::SetAvailability(bool isAvailable) {
	this->isAvailable = isAvailable;
}

bool Game::IsFree() {
	if (this->price == 0) return true;

	return false;
}

void Game::Print() const {
	std::cout << "Game title: " << this->title << std::endl;
	std::cout << "Game price: " << this->price << std::endl;
	std::cout << "Is game available: " << this->isAvailable << std::endl;
}

bool CompareDoubles(double d1, double d2) {
	return abs(d1 - d2) < EPSILON;
}

bool Game::IsEqualTo(const Game& game) const {
	if (!strcmp(this->GetTitle(), game.GetTitle())
		&& this->GetAvailability() == game.GetAvailability()
		&& CompareDoubles(this->GetPrice(), game.GetPrice())) {
		return true;
	}

	return false;
}

bool Game::IsInvalidTitle(const char* title) const {
	return (strlen(title) > FIELD_MAX_SIZE || !title);
}

bool Game::IsInvalidPrice(double price) const {
	return (price > CHEAPEST_PRICE || price < 0);
}

GamePlatform::GamePlatform() : GamePlatform(nullptr, 0) {}

GamePlatform::GamePlatform(const Game* games, int gamesCount) {
	this->gamesCount = gamesCount;

	for (size_t i = 0; i < gamesCount; i++)
	{
		this->games[i] = games[i];
	}
}

int GamePlatform::GetGamesCount() const {
	return this->gamesCount;
}


void GamePlatform::AddGame(const Game& game) {
	if (this->gamesCount < GAMES_MAX_COUNT) {
		this->games[gamesCount++] = game;
		return;
	}
	std::cout << "Not enough space for this game!" << std::endl;
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
	for (size_t i = 0; i < this->gamesCount; i++)
	{
		this->games[i].Print();
	}
}

const Game GamePlatform::ReturnCheapestGame() const {
	this->CheckIfThereAreAnyGames();

	int cheapestPrice = CHEAPEST_PRICE;
	Game cheapestGame;
	for (size_t i = 0; i < this->gamesCount; i++)
	{
		if (this->games[i].GetPrice() < cheapestPrice) {
			cheapestPrice = games[i].GetPrice();
			cheapestGame = games[i];
		}
	}

	return cheapestGame;
}

const Game GamePlatform::ReturnMostExpensiveGame() const {
	this->CheckIfThereAreAnyGames();
	int mostExpPrice = MOST_EXPENSIVE_PRICE;
	Game mostExpGame;
	for (size_t i = 0; i < this->gamesCount; i++)
	{
		if (this->games[i].GetPrice() > mostExpPrice) {
			mostExpPrice = games[i].GetPrice();
			mostExpGame = games[i];
		}
	}
	return mostExpGame;
}

void GamePlatform::PrintAllFreeGames() const {
	this->CheckIfThereAreAnyGames();
	int freeGamesCount = 0;
	for (size_t i = 0; i < this->gamesCount; i++)
	{
		if (this->games[i].GetPrice() == 0) {
			this->games[i].Print();
			freeGamesCount++;
		}
	}

	if (freeGamesCount == 0) std::cout << "No free games!" << std::endl;
}

void GamePlatform::RemoveGameFromLibrary(const Game& game) {
	this->CheckIfThereAreAnyGames();

	int removedGamesCount = 0;
	for (size_t i = 0; i < this->gamesCount; i++)
	{
		if (game.IsEqualTo(this->games[i])) {
			for (size_t j = i; j < this->gamesCount; j++)
			{
				this->games[j] = this->games[j + 1];
				removedGamesCount++;
			}
			gamesCount--;
			break;
		}
	}
	if(removedGamesCount == 0)
		std::cout << "Couldn't find this game in the library!" << std::endl;
}

void GamePlatform::WriteGamePlatformToFile(const char* filePath) const {
	this->CheckIfThereAreAnyGames();

	std::ofstream writeFile(filePath, std::ios::out);
	if (!writeFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	writeFile << this->gamesCount << std::endl;
	for (size_t i = 0; i < this->gamesCount; i++)
	{
		writeFile << this->games[i].GetTitle() << ","
			<< this->games[i].GetPrice() << ","
			<< this->games[i].GetAvailability() << std::endl;
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
	for (size_t i = 0; i < gamesCount; i++)
	{
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
	
	for (size_t i = 0; i < gamePlatform.gamesCount; i++)
	{
		this->games[i] = gamePlatform.games[i];
	}

	this->gamesCount = gamePlatform.gamesCount;
	readFile.close();
}

void GamePlatform::CheckIfThereAreAnyGames() const {
	if (this->gamesCount == 0) {
		std::cout << "There are no games in this library!";
		return;
	}
}

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