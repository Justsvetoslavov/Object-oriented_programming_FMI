#include <iostream>
#include <cstring>
#include <fstream>

const int MAX_GAMES = 20;
const int MAX_SYMB = 1024;
const char *PATH = "test.txt";

class Game {
    char *title;
    float price;
    bool isAvailable;
public:
    Game() {
        title = nullptr;
        price = -1;
        isAvailable = false;
    }

    Game(const char *title, float price, bool isAvailable) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->price = price;
        this->isAvailable = isAvailable;
    }

    const char *getTitle() const {
        return title;
    }

    float getPrice() const {
        return price;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    void SetTitle(const char *title) {
       // if (this->title != nullptr)
           // delete []this->title;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void SetPrice(float price) {
        this->price = price;
    }

    void SetIsAvailable(bool isAvailable) {
        this->isAvailable = isAvailable;
    }

    bool isFree() const {
        if (1 - price < 1)
            return false;
        return true;
    }

    void print() const {
        std::cout << "Title: " << title << std::endl
                  << "Price: " << price << std::endl
                  << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }
};

class GamePlatform {
    Game games[MAX_GAMES];

public:
    int size = 0;
    void addGame(const char *title, float price, bool isAvailable) {
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

    void readByIndex(int index) const {
        if (index >= size || index < 0 || games[index].getPrice() == -1)
            return;
        games[index].print();
    }

    void readAll() const {
        for (int i = 0; i < size; ++i)
            games[i].print();
    }

    void readMinMaxPriceGame() const {
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

    void readFree() const {
        for (int i = 0; i < size; ++i)
            if (games[i].isFree())
                games[i].print();
    }

    void deleteByIndex(int index) {
        if (index >= size || index < 0 || games[index].getPrice() == -1)
            return;
        games[index].SetTitle("none");
        games[index].SetPrice(-1);
        games->SetIsAvailable(false);
    }

    void writeToFile() const {
        std::fstream file(PATH, std::ios::out);
        for (int i = 0; i < size; ++i) {
            file << "Title: " << games[i].getTitle() << std::endl
                    << "Price: " << games[i].getPrice() << std::endl
                    << "Available: " << games[i].getIsAvailable() << std::endl;
        }
        file.close();
    }

    Game readGame(std::fstream &file) {
        Game game;
        char reader[MAX_SYMB];
        float price;
        bool avail;
        file.getline(reader, MAX_SYMB, ':');
        file.getline(reader, MAX_SYMB);
        game.SetTitle(reader);
        file.getline(reader, MAX_SYMB, ':');
        file >> price;
        game.SetPrice(price);
        file.getline(reader, MAX_SYMB, ':');
        file >> avail;
        game.SetIsAvailable(avail);
    }

    void readFromFile() {
        std::fstream file(PATH, std::ios::in);
        if (file.is_open())
            return;
        size = 0;
        while(!file.eof()) {
            games[size++] = readGame(file);
        }
        file.close();
    }
};

int main() {
    Game game("none", 0, 0);
    game.print();
    GamePlatform gmpl;
    gmpl.addGame("none", 0, 0);
    gmpl.writeToFile();
}