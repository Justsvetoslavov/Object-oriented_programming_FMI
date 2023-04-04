#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    items = new Item[1];
    size = 1;
    count = 0;
}

ShoppingCart::~ShoppingCart() {
    delete[] items;
}

void ShoppingCart::addItem(const Item &item) {
    if (size == count)
        addSpace();
    if (!exists(item.getName())) {
        items[count++] = item;
        std::cout << "Item added\n";
    } else
        std::cout << "Item not added\n";
}

void ShoppingCart::delItem(const char* name) {
    int pos = findPos(name);
    if (pos != -1) {
        for (int i = pos; i < count - 1; ++i) {
            items[i] = items[i + 1];
        }
        items[--count].delItem();
        std::cout << "Item deleted\n";
    } else
        std::cout << "Item not deleted\n";
}

int ShoppingCart::itemsCount() const {
    return count;
}

bool ShoppingCart::exists(const char* name) const {
    if (findPos(name) == -1)
        return false;
    return true;
}

bool ShoppingCart::isEmpty() const {
    if (count == 0)
        return true;
    return false;
}

double ShoppingCart::getPriceOf(const char* name) const {
    int pos = findPos(name);
    return pos == -1 ? 0.0 : items[pos].getPrice();
}

double ShoppingCart::totalPrice() const {
    double res = 0;
    for (int i = 0; i < count; ++i) {
        res += items[i].getPrice() * items[i].getAmount();
    }
    return res;
}

void ShoppingCart::sortByNames() {
    for (int i = 1; i < count; ++i)
        for (int j = 0; j < count - i; ++j)
            if (items[j].getName()[0] > items[j + 1].getName()[0])
                mySwap(items[j], items[j + 1]);
}

void ShoppingCart::save(const char* path) const {
    std::fstream file(path, std::ios::out);
    file << "Name,Amount,Price\n";
    for (int i = 0; i < count; ++i)
        items[i].save(file);
    file.close();
}

void ShoppingCart::mySwap(Item &item1, Item &item2) {
    Item temp(item1);
    item1 = item2;
    item2 = temp;
}

void ShoppingCart::addSpace() {
    Item *copyItems = new Item[size];
    for (int i = 0; i < size; ++i)
        copyItems[i] = items[i];
    delete[] items;
    items = new Item[size * 2];
    for (int i = 0; i < size; ++i)
        items[i] = copyItems[i];
    size *= 2;
}

int ShoppingCart::findPos(const char* name) const {
    for (int i = 0; i < count; ++i) {
        if (strcmp(items[i].getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}