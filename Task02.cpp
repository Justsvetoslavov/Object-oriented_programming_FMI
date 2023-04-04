#include "ShoppingCart/ShoppingCart.h"

// without bonus :(

int main() {
    ShoppingCart shc;
    shc.addItem(Item("Pencil", 1, 20));
    shc.addItem(Item("Pen", 1, 15));
    shc.addItem(Item("Notebook", 1, 30));
    shc.delItem("Pen");
    std::cout << shc.totalPrice() << std::endl;
    std::cout << shc.getPriceOf("Notebook") << std::endl;
    shc.sortByNames();
    shc.save("test.csv");
}