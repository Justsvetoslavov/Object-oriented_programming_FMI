
#include "GamePlatform.h"

void GamePlatform::resizeGames() {
    Game *newArr = new Game[this->size*2];
   // newArr = this->getGames();
    delete[] this->games;
    this->games = newArr;
}

const Game *GamePlatform::getGames() const {
    return games;
}


