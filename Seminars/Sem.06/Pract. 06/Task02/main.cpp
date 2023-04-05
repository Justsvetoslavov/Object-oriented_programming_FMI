#include <iostream>

#include "ShoppingCart.h"

int main() {
    Item item1("Apple", 4, 1.20);
    Item item2("Bread", 12, 2.30);
    Item item3("Milk", 7, 1.74);

    Item item4("Chocolate", 3, 3.56);
    Item item5("Flour", 2, 1.26);
    Item item6("Sugar", 6, 1.89);
    Item item7("Butter", 10, 7.29);
    Item item8("Eggs", 5, 4.53);

    ShoppingCart sc;
    sc.addItem(item1, 2);
    sc.addItem(item2, 10);
    sc.addItem(item3, 3);

    ShoppingCart sc2;
    sc2.addItem(item4, 1);
    sc2.addItem(item5, 2);
    sc2.addItem(item6, 4);
    sc2.addItem(item7, 8);
    sc2.addItem(item8, 3);

    sc.print();
    std::cout << std::endl;
    sc2.print();
    std::cout << std::endl;

    sc = sc2;
    std::cout << sc.exists("Tomato") <<  ' ' << sc.exists("Sugar") << std::endl;
    std::cout << sc.getPriceOf("Flour") << std::endl;
    std::cout << sc.isEmpty() << std::endl;
    std::cout << sc.itemsCount() << std::endl;
    std::cout << sc.totalPrice() << std::endl;
    std::cout << std::endl;
    sc.print();

    std::cout << "Items count: " << sc.itemsCount() << std::endl;
    sc.removeItem("Chocolate");
    std::cout << std::endl;
    std::cout << "After removing  chocolate:" << std::endl;
    std::cout << "Items count: " << sc.itemsCount() << std::endl;
    sc.print();

    std::cout << std::endl;
    std::cout << "Sorted by name:" << std::endl;
    sc.sortByName();
    sc.print();

    std::cout << "Total price: " << sc.totalPrice() << std::endl;

    sc.save("Cart.csv");
}
