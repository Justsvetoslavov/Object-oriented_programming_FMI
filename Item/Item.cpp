#include "Item.h"

Item::Item() {
    name = new char[1];
    name[0] = '\0';
    amount = false;
    price = -1;
}

Item::Item(const char *name, const int amount, const int price) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->amount = amount;
    this->price = price;
}

Item::Item(const Item& item) {
    copyItem(item);
}

Item::~Item() {
    free();
}

const char* Item::getName() const {
    return name;
}

bool Item::getAmount() const {
    return amount;
}

double Item::getPrice() const {
    return (double)price / 10;
}

void Item::setName(const char* name) {
    delete[] name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Item::setAmount(const int amount) {
    this->amount = amount;
}

void Item::setPrice(const int price) {
    this->price = price;
}

void Item::copyItem(const Item& item) {
    name = new char[strlen(item.name) + 1];
    strcpy(name, item.name);
    amount = item.amount;
    price = item.price;
}

Item &Item::operator=(const Item &item) {
    if (this != &item) {
        free();
        copyItem(item);
    }
    return *this;
}

void Item::delItem() {
    name = new char[1];
    name[0] = '\0';
}

void Item::save(std::fstream &file) const {
    file << name << ',' << amount << ',' << getPrice() << std::endl;
}

void Item::free() {
    price = -1;
    amount = false;
    delete[] name;
}