#include "GamePlatform.h"

GamePlatform::GamePlatform(){

    size = 0;
    this->games = new Game[1];

}

size_t GamePlatform::getSize() const{
    return this->size;
}

bool GamePlatform::addGame(Game game){

    games[size++] = game;
    return true;
}

void GamePlatform::showGames(){

    for(int i =0; i < this->size;i++){
        games[i].print();
    }

}

void GamePlatform::showGameByID(const int &index){

    if(index >= 0 and index < this->size){
        std::cout<<games[index].getTitle()<<"\n";
    }
    else std::cout<<"invalid index";
}

void GamePlatform::showCheapestGame(){

    Game minPriceGame;
    minPriceGame.setPrice(INT_MAX);
    for(int i = 0; i < this->size;i++){
        if(games[i].getPrice() < minPriceGame.getPrice())minPriceGame = games[i];
    }

    std::cout<<"Cheapest game is ->"<<"\n";
    minPriceGame.print();

}

void GamePlatform::showMostExpensiveGame(){

    Game maxPriceGame;
    maxPriceGame.setPrice(-1);
    for(int i = 0; i < this->size;i++){
        if(games[i].getPrice() > maxPriceGame.getPrice())maxPriceGame = games[i];
    }

    std::cout<<"Most expensive game is ->"<<"\n";
    maxPriceGame.print();

}

void GamePlatform::showFreeGames() {

    for(int i = 0;i < this->size; i++){
        if(games[i].isFree())
            games[i].print();
    }

}

void GamePlatform::deleteByID(const int &index){

    if(index < 0 or index >= this->size){
        std::cout<<"invalid index";
        return;
    }

    for(int i = index; i < this->size-1; i++){
        this->games[i] = this->games[i+1];
    }

    this->size--;

    std::cout<<"\ndeleted successfully";

}

int GamePlatform::getGameID(const Game &game){

    for(int i = 0; i < this->size;i++){
        if(games[i].isEqual(game))return i;
    }

    return -1;

}

const char *fileName = "game_platform.txt";

bool GamePlatform::readGamePlatform(){

    std::ifstream file(fileName,std::ios::in);

    if(!file.is_open())return false;

    while(true){

        std::string str;
        std::string element;
        if(file.eof())break;

        std::getline(file,str);

        Game game;

        std::istringstream stream(str);
        std::getline(stream,element,' ');
        game.setTitle(element.data());

        std::getline(stream,element,' ');
        game.setPrice(std::stof(element));

        std::getline(stream,element,' ');
        game.setIsAvailable(std::stoi(element));

        addGame(game);

    }

    file.close();

    return true;

}

bool GamePlatform::savePlatform(){

    std::ofstream file(fileName,std::ios::out);
    if(!file.is_open())return false;

    for(int i = 0; i < this->size;i++){

        file<<this->games[i].buildString();
        if(i < this->size-1)file<<"\n";

    }

    return true;
}

GamePlatform::~GamePlatform() {

        delete[] games;
}
