#include <iostream>
using std::cin;
using std::cout;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1


//Реализирайте функции, която по две цели числа връща по - малкото от тях като подавата числата по стойност
//, като указател и чрез референция(псевдоним).
//Използвайте ключова дума const и демонстрирайте чрез примери кога е възможна(и кога не) употребата на всяка една от функциите.

int smallerbypointer(int* a, int* b) {

	if (*a < *b) {
		return *a;
	}
	else if (*a == *b) {
		return -1;
	}
	else {
		return *b;
	}

}

int smallnr(int a, int b) {
	if (a < b) {
		return a;
	}
	else if (a == b) {
		return -1;
	}
	else {
		return b;
	}
}

int smallbyreference(int& a, int& b) {
	if (a < b) {
		return a;
	}
	else if (a == b) {
		return -1;
	}
	else {
		return b;
	}
}

int main() {
	int a;
	int b;
	cout << "enter numbers" << endl;
	cin >> a >> b;
	cout << smallerbypointer(&a, &b) << endl;
	cout << smallbyreference(a, b) << endl;
	cout << smallnr(a, b) << endl;
}