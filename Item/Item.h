#include <cstring>
#include <fstream>

class Item {
    char* name;
    int amount;
    int price;

public:

    Item();

    Item(const char* name, const int amount, const int price);

    Item(const Item& item);

    ~Item();

    const char* getName() const;

    bool getAmount() const;

    double getPrice() const;

    void setName(const char* name);

    void setAmount(const int amount);

    void setPrice(const int price);

    void copyItem(const Item& item);

    Item& operator=(const Item& item);

    void delItem();

    void save(std::fstream& file) const;
};
