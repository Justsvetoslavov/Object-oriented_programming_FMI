#include "GamePlatform/GamePlatform.h"

int main() {
//    Game game("none", 0, 0);
//    game.print();
    GamePlatform gamePlatform;
//    gamePlatform.addGame("test1", 1, 1);
//    gamePlatform.addGame("test2", 2, 0);
    gamePlatform.readFromFile();
//    gamePlatform.readAll();
//    gamePlatform.readMinMaxPriceGame();
//    gamePlatform.deleteByIndex(0);
    gamePlatform.readFree();
    gamePlatform.readAll();
    gamePlatform.writeToFile();
}