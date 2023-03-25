#include "GamePlatform.h"

void GamePlatform::addGame(const char *title, float price, bool isAvailable) {
    if (size == MAX_GAMES)
        return;
    games[size].SetTitle(title);
    if (price < 0)
        games[size].SetPrice(0);
    else
        games[size].SetPrice(price);
    games[size].SetIsAvailable(isAvailable);
    size++;
}

void GamePlatform::readByIndex(int index) const {
    if (index >= size || index < 0 || games[index].getPrice() == -1)
        return;
    games[index].print();
}

void GamePlatform::readAll() const {
    for (int i = 0; i < size; ++i)
        if (games[i].getPrice() != -1)
            games[i].print();
}

void GamePlatform::readMinMaxPriceGame() const {
    int min_pos = 0, max_pos = 0, min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (min > games[i].getPrice() && games[i].getPrice() != 0) {
            min = games[i].getPrice();
            min_pos = i;
        }
        if (max < games[i].getPrice() && games[i].getPrice() != 0) {
            max = games[i].getPrice();
            max_pos = i;
        }
    }
    std::cout << "Max: \n";
    games[max_pos].print();
    std::cout << "Min: \n";
    games[min_pos].print();
}

void GamePlatform::readFree() const {
    for (int i = 0; i < size; ++i)
        if (games[i].isFree() && games[i].getPrice() != -1)
            games[i].print();
}

void GamePlatform::deleteByIndex(int index) {
    if (index >= size || index < 0 || games[index].getPrice() == -1)
        return;
    games[index].SetTitle("none");
    games[index].SetPrice(-1);
    games->SetIsAvailable(false);
}

void GamePlatform::writeToFile() const {
    std::fstream file(PATH, std::ios::out);
    for (int i = 0; i < size; ++i)
        if (games[i].getPrice() != -1)
            file << "\nTitle: " << games[i].getTitle() << std::endl
                 << "Price: " << games[i].getPrice() << std::endl
                 << "Available: " << games[i].getIsAvailable();
    file.close();
}

Game GamePlatform::readGame(std::fstream &file) {
    Game game;
    char reader[MAX_SYMBOLS];
    float price;
    bool avail;
    file.getline(reader, MAX_SYMBOLS, ' ');
    file.getline(reader, MAX_SYMBOLS);
    game.SetTitle(reader);
    file.getline(reader, MAX_SYMBOLS, ' ');
    file >> price;
    game.SetPrice(price);
    file.getline(reader, MAX_SYMBOLS, ' ');
    file >> avail;
    file.getline(reader, MAX_SYMBOLS);
    game.SetIsAvailable(avail);
    return game;
}

void GamePlatform::readFromFile() {
    std::fstream file(PATH, std::ios::in);
    if (!file.is_open())
        return;
    size = 0;
    while (!file.eof())
        games[size++] = readGame(file);
    file.close();
}