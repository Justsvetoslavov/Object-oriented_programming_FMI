#include <iostream>
#include "game_platform.hpp"

using std::cin, std::cout, std::endl;

int main() {
    Game games[] =
            {
                    Game("League of Legends", 0, true),
                    Game("Minecraft", 50, true)
            };

    GamePlatform gamePlatform(games, sizeof games / sizeof(Game));

    cout << ">>>Games before adding>>>" << endl;
    for (int i = 0; i < gamePlatform.getGamesCount(); ++i) {
        gamePlatform.getGameByIndex(i).print();
    }
    gamePlatform.addGame(Game("Dota 2", 10, true));
    cout << ">>>Games after adding>>>" << endl;
    for (int i = 0; i < gamePlatform.getGamesCount(); ++i) {
        gamePlatform.getGameByIndex(i).print();
    }
    cout << ">>>The most expensive game is>>>" << endl;
    gamePlatform.getTheMostExpensiveGame().print();
    cout << ">>>The cheapest game is>>>" << endl;
    gamePlatform.getTheCheapestGame().print();
    cout << ">>>Free games are>>>" << endl;
    gamePlatform.printFreeGames();
    cout << ">>>Enter title to remove: ";
    char title[MAX_TITLE_LENGTH + 1];
    cin.getline(title, MAX_TITLE_LENGTH + 1);
    gamePlatform.removeGame(title);
    cout << ">>>Games after removing>>>" << endl;
    for (int i = 0; i < gamePlatform.getGamesCount(); ++i) {
        gamePlatform.getGameByIndex(i).print();
    }
    gamePlatform.writeToFile("games.txt");
    GamePlatform gamePlatform2;
    gamePlatform2.readFromFile("games.txt");
    cout << ">>>Games after reading from file>>>" << endl;
    for (int i = 0; i < gamePlatform2.getGamesCount(); ++i) {
        gamePlatform2.getGameByIndex(i).print();
    }
    return 0;
}
