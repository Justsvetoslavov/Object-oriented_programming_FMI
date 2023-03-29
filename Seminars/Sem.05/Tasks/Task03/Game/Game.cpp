#include "Game.h"

Game::Game(){

    this->title = new char[1];
    this->price = 0;
    this->isAvailable = false;

}

Game::Game(const char* title,const float &price,const bool &isAvailable){

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->price = price;
    this->isAvailable = isAvailable;
}

const char* Game::getTitle() const  {
    return this->title;
}

float Game::getPrice() const  {
    return this->price;
}

bool Game::getIsAvailable() const {
    return this->isAvailable;
}

Game Game::setTitle(const char *title) {

    if (this->title == nullptr)
        delete[] this->title;

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    return *this;
}


Game Game::setPrice(const float &price){
    this->price = price;
    return *this;
}


Game Game::setIsAvailable(const bool &isAvailable){
    this->isAvailable = isAvailable;
    return *this;
}

void Game::print(){
    std::cout<<   "Title - "<<
    this->title<< "\nPrice - "<<
    this->price<< "\nAvailable - ";
    std::cout<<(this->isAvailable ? "YES\n" : "NO\n");
}
std::string Game::buildString(){

    std::ostringstream string;
    string <<this->title<<" "<< this->price<<" "<<this->isAvailable;
    return string.str();

}
bool Game::isFree(){
    if(this->price == 0)return true;
    return false;
}

bool Game::isEqual(Game game){

    if(this->title == game.getTitle() and this->price == game.getPrice())return true;
    return false;

}

Game& Game::operator = (const Game game){

    if (this->title == nullptr)
        delete[] this->title;

    this->title = new char[strlen(game.title) + 1];
    strcpy(this->title, game.title);

    this->price = game.price;
    this->isAvailable = game.isAvailable;

    return *this;
}

Game::~Game() {
    delete[] title;
}
