#include <cstring>
#include <fstream>

class Item {
    char* name;
    int amount;
    int price;

    void copyItem(const Item& item);

    void free();

public:

    Item();

    Item(const char* name, const int amount, const int price);

    Item(const Item& item);

    ~Item();

    const char* getName() const;

    bool getAmount() const;

    void delItem();

    double getPrice() const;

    void setName(const char* name);

    void setAmount(const int amount);

    void setPrice(const int price);

    Item& operator=(const Item& item);

    void save(std::fstream& file) const;
};
