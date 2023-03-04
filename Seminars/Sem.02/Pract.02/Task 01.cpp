#include <iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;


void saveToFile() {
	double a, b, c;
	cin >> a >> b >> c;
	double sum = a + b + c;

	double product = a * b * c;
	std::ofstream file("result.txt");
	if (!file.is_open()) {
		cout << "Error!";
		return ;
	}
	file << sum << ' ' << product;
	file.close();

}
void Difference() {

	std::ifstream file("result.txt");
	double sum, product;
	if (!file.is_open()) {
		cout << "Error!";
		return;
	}
	file >> sum >> product;
	double difference = product-sum;

	cout << "The difference is:" << difference;
	file.close();

}


int main() {
	saveToFile();
	Difference();
}