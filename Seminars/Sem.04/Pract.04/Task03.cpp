#include <iostream>
#include <fstream>

const int MAX_LENGTH = 25;
const int MAX_NO_OF_GAMES = 25;
const int BUFF = 1024;
class Game {
private:
	char title[MAX_LENGTH];
	float price;
	bool isAvailable;
public:
	// Default constructor
	Game() : price(0.0), isAvailable(false){ title[0] = '\0'; }
	// Parameterized constructor
	Game(const char title[], float price, bool isAvailable) {
		setTitle(title);
		setPrice(price);
		setAvailability(isAvailable);

	}
	const char* getTitle()const {
		return title;
	}
	float getPrice()const {
		
			return price;
	
	}
	bool getAvailability()const {
			return isAvailable;
	
	}
	void setTitle(const char title[]) {
		int index = 0;
		while (title[index] != '\0') {
			this->title[index] = title[index];
			index++;
		}
		this->title[index] = '\0';
	}
	void setPrice(float price)
	{
		if (price >= 0) {
			this->price = price;
		}
	}
    void setAvailability(bool isAvailable) {

		this->isAvailable = isAvailable;

		}
	
	bool isFree() const { return price == 0.0; }
	

	void printInformation()const {

		std::cout << "Title:" << getTitle() << std::endl;
		std::cout << "Price:" << getPrice() << std::endl;
		std::cout << "Availability: " << (isAvailable ? "Available" : "Not available") << std::endl;

	}

};

class GamePlatform {
private:
	Game games[MAX_NO_OF_GAMES];
	int numOfGames;
public:
	GamePlatform():numOfGames(0){}


	void addGame( const Game&game) {
		if (numOfGames < MAX_NO_OF_GAMES) {
			games[numOfGames] = game;
			numOfGames++;
			std::cout << "Game added successfully!" << std::endl;
		}
		else {
			std::cout << "Library is full, cannot add game." << std::endl;
		}
	}

	void DisplayGameByIndex(const int index)const {
		if (index >= 0 && index < numOfGames) {
			const Game& game = games[index];
			std::cout << "Game at index:" << index << ":" << std::endl;
			game.printInformation();
		}
		else {
			std::cout << "Invalid index!" << std::endl;
		}
	}
	void ListAllTheGames()const {
		if (numOfGames == 0) {
			std::cout << "No games in the library" << std::endl;
		}

		else {
			for (int i = 0; i < numOfGames; i++) {
				const Game& game = games[i];
				std::cout << "Game at index:" << i << ":" << std::endl;
				game.printInformation();
				std::cout << std::endl;


			}
		}
	}

		const Game* getCheapestGame()const {
			if (numOfGames == 0) {
				return nullptr;
			}
			const Game* cheapestGame = &games[0];
			for (int i = 1; i < numOfGames; i++) {
				const Game* currentGame = &games[i];
				if (currentGame->getPrice() < cheapestGame->getPrice()) {
					cheapestGame = currentGame;
				}
			}
			return cheapestGame;
		}
		const Game* getMostExpensiveGame() const {
			if (numOfGames == 0) {
				return nullptr;
			}
			const Game* mostExpensiveGame = &games[0];
			for (int i = 1; i < numOfGames; i++) {
				const Game* currentGame = &games[i];
				if (currentGame->getPrice() > mostExpensiveGame->getPrice()) {
					mostExpensiveGame = currentGame;
				}
			}
			return mostExpensiveGame;
		}
		void ListAllFreeGames()const {
			bool foundFreeGame = false;
				for (int i = 0; i < numOfGames; i++) {
					const Game& game = games[i];
					if(game.isFree()){
						std::cout << "Game at index " << i << ":" << std::endl;
						game.printInformation();
						std::cout << std::endl;
						foundFreeGame = true;
					}
				}
				if (!foundFreeGame) {
					std::cout << "No free games in the library." << std::endl;
				}

		}
		void removeGameFromLibrary(int index) {
			if (index < 0 || index >= numOfGames) {
				std::cout << "Invalid index!" << std::endl;
				return;
			}
			// Shifting  games to the left to fill the gap
			for (int i = index + 1; i < numOfGames; i++) {
				games[i - 1] = games[i];
			}

			// Clearing the last element of the array
			Game emptyGame;
			games[numOfGames - 1] = emptyGame;

			numOfGames--;

		}
		void saveDataToFile(const char* filename)const {
			std::ofstream outfile(filename, std::ios::out);
			if (!outfile.is_open()) {
				std::cout << "ERROR OPENING THIS FILE." << std::endl;
				return;
			}
			outfile << numOfGames << std::endl;
			for (int i = 0; i < numOfGames; i++) {
				const Game& game = games[i];
				outfile << games[i].getTitle() << std::endl;
				outfile << games[i].getPrice() << std::endl;
				outfile << games[i].getAvailability() << std::endl;
			}
			outfile.close();

		}
		void ReadDataToFile(const char* filename)const {
			std::ifstream infile(filename, std::ios::in);
			if (!infile.is_open()) {
				std::cout << "ERROR OPENING THIS FILE." << std::endl;
				return;
			}
				char buffer[BUFF];
				while (infile.getline(buffer, BUFF)) {

					std::cout << buffer << std::endl;
				}
			infile.close();

		}
	

};

int main() {
	GamePlatform platform;

	// Adding some games to the platform
	Game game1("Super Mario Bros.", 19.99, true);
	platform.addGame(game1);

	Game game2("The Legend of Zelda: Breath of the Wild", 59.99, false);
	platform.addGame(game2);

	Game game3("Minecraft", 26.95, true);
	platform.addGame(game3);

	Game game4("Portal 2", 9.99, true);
	platform.addGame(game4);

	Game game5("Undertale", 14.99, true);
	platform.addGame(game5);

	// Displaying information about a game at a specific index
	platform.DisplayGameByIndex(2);

	// Displaying information about all games
	platform.ListAllTheGames();

	// Displaying the cheapest game
	const Game* cheapestGame = platform.getCheapestGame();
	if (cheapestGame != nullptr) {
		std::cout << "The cheapest game is: " << cheapestGame->getTitle() << std::endl;
	}
	else {
		std::cout << "No games in the library." << std::endl;
	}

	// Displaying the most expensive game
	const Game* mostExpensiveGame = platform.getMostExpensiveGame();
	if (mostExpensiveGame != nullptr) {
		std::cout << "The most expensive game is: " << mostExpensiveGame->getTitle() << std::endl;
	}
	else {
		std::cout << "No games in the library." << std::endl;
	}

	// Displaying all free games
	platform.ListAllFreeGames();

	// Removing a game from the platform
	platform.removeGameFromLibrary(1);

	// Displaying information about all games after a game has been removed
	platform.ListAllTheGames();

	// Saving data to a file
	platform.saveDataToFile("games.txt");
	platform.ReadDataToFile("games.txt");
	

	return 0;
}



