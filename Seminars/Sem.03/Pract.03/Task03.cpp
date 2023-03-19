#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 256;
const int MAX_ITEMS = 10;
const int MAX_ORDERS = 100;

enum Dominos
{
    SmallPizza, MeduimPiza, LargePizza, Soda, MineralWater, Tea, Beer
};

struct Order
{
    char destAddress[MAX_SIZE];
    Dominos orderItems[MAX_ITEMS];
};

Order currentOrders[MAX_ORDERS];
int orderAmount;

// За тестове с двоични файлове ползвайте ".data" като разширение
void saveOrders(const char* filePath)
{
    ofstream streamWriter(filePath);

    if (streamWriter.is_open())
        streamWriter.write((char*)&currentOrders, sizeof(currentOrders));

    streamWriter.close();
}

void getOrders(const char* filePath)
{
    ifstream streamReader(filePath);

    if (streamReader.is_open())
        streamReader.read((char*)&currentOrders, sizeof(currentOrders));

    streamReader.close();
}

void readOrders()
{
    int items, orders, temp, i;
    do {
        cout << "Enter the amount of orders: ";
        cin >> orders;
    } while (orders < 0);
    cin.ignore();

    for (i = 0; i < orders; ++i)
    {
        cout << "Enter the address of the chosen destination: ";
        cin.getline(currentOrders[i].destAddress, MAX_SIZE);

        do {
            cout << "Enter the amoint of items in the order: ";
            cin >> items;
        } while (items < 0 || items > MAX_ITEMS);

        cout << "Enter the items in the order: ";
        for (int a = 0; a < items; ++a)
        {
            cin >> temp;
            currentOrders[i].orderItems[a] = (Dominos)temp;
        }
    }

    orderAmount = i;
}

template <class T>
void swap2(T& item1, T& item2)
{
    T temp = item1;
    item1 = item2;
    item2 = temp;
}

template <class T>
void swapElements(T arr1[], T arr2[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        swap2(arr1[i], arr2[i]);
    }
}

void sortOrders(const char* outPath)
{
    for (int i = 0; i < MAX_ORDERS - 1; ++i)
    {
        for (int j = i + 1; j < MAX_ORDERS; ++j)
        {
            if (strcmp(currentOrders[i].destAddress, currentOrders[j].destAddress) > 0)
            {
                swapElements(currentOrders[i].destAddress, currentOrders[j].destAddress, MAX_SIZE );
                swapElements(currentOrders[i].orderItems , currentOrders[j].orderItems , MAX_ITEMS);
            }
        }
    }

    saveOrders(outPath);
}

int main()
{
    return 0;
}