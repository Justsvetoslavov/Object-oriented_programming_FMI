#include "../Item/Item.h"
#include <iostream>

class ShoppingCart {
    Item* items;
    int size;
    int count;

public:
    ShoppingCart();

    ShoppingCart(const ShoppingCart& cart);

    ShoppingCart& operator=(const ShoppingCart& cart);

    ~ShoppingCart();

    void addItem(const Item &item);

    void delItem(const char* name);

    int itemsCount() const;

    bool exists(const char* name) const;

    bool isEmpty() const;

    double getPriceOf(const char* name) const;

    double totalPrice() const;

    void sortByNames();

    void save(const char* path) const;

private:

    void mySwap(Item &item1, Item &item2);

    void addSpace();

    int findPos(const char* name) const;

    void free();

    void copyFrom(const ShoppingCart& cart);
};
