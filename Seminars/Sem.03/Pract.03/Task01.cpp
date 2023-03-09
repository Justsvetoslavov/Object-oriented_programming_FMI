#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable: 4996)

const int SIZE_OF_ORDERS = 3;
const char FILE_NAME[] = "pizzasOrders.bin";
const char SIZE_OF_ADDRESS = 26;

struct PizzaDelivery {
	double price;
	char address[SIZE_OF_ADDRESS];
};

void initializeOrders(PizzaDelivery& orders, double price, const char* address) {
	orders.price = price;
	strcpy(orders.address, address);
}

size_t getFileSize(std::ifstream& fileName) {
	size_t currentPos = fileName.tellg();
	fileName.seekg(0, std::ios::end);
	size_t size = fileName.tellg();

	fileName.seekg(currentPos);
	return size;
}

void saveOrders(const PizzaDelivery* orders, size_t counter, std::ofstream& fileName){
	fileName.write((const char*)&orders, counter * sizeof(PizzaDelivery));
}

void readOrders(PizzaDelivery* orders, size_t counter, std::ifstream& fileName) {
	size_t fileSize = getFileSize(fileName);
	counter = fileSize / sizeof(PizzaDelivery);
	orders = new PizzaDelivery[counter];
	fileName.read((char*)&orders, fileSize);
}

int myStrCmp(const char* lhs, const char* rhs) {
	short flag = 0;
	int i = 0;
	while (!flag) {
		if (lhs[i] > rhs[i]) {
			flag = 1;
		}
		else if (lhs[i] < rhs[i]) {
			flag = -1;
		}
		if (lhs[i] == '\0') {
			break;
		}
		i++;
	}
	return flag;
}

void swap(PizzaDelivery& order1, PizzaDelivery& order2) {
	PizzaDelivery temp = order1;
	order1 = order2;
	order2 = temp;
}

void sortOrders(PizzaDelivery* orders) { //selection sort
	for (int i = 0; i < SIZE_OF_ORDERS; i++) {
		int minInd = i;
		for (int j = i+1; j < SIZE_OF_ORDERS; j++) {
			if (myStrCmp(orders[j].address, orders[minInd].address) < 0) {
				minInd = j;
			}
		}
		if (minInd != i) {
			swap(orders[minInd], orders[i]);
		}
	}
}

int main() {
	PizzaDelivery orders[SIZE_OF_ORDERS];
	initializeOrders(orders[0], 10.5, "Ruen");
	initializeOrders(orders[1], 8.5, "JamesBoucher");
	initializeOrders(orders[2], 13, "SomeStreet");
	
	std::ofstream out(FILE_NAME, std::ios::binary);
	if (!out.is_open()) {
		std::cout << "ERROR!" << std::endl;
		return -1;
	}
	saveOrders(orders, SIZE_OF_ORDERS, out);
	out.close();

	std::ifstream in(FILE_NAME, std::ios::binary);
	if (!in.is_open()) {
		std::cout << "ERROR!" << std::endl;
		return -1;
	}
	readOrders(orders, SIZE_OF_ORDERS, in);
	in.close();

	for (int i = 0; i < SIZE_OF_ORDERS; i++) {
		std::cout << "Price: " << orders[i].price << ", address: " << orders[i].address << std::endl;
	}

	return 0;
}