#include<iostream>
using std::cout;
using std::cin;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1

//Създайте структура описваща студент.Всеки студент се определя чрез :
//
//име(до 30 символа)
//факултетен номер(цяло неотрицателно число)
//За всеки от долупосочените примери демонстрирайте кои операции са възможни и кои не.
//Възможните операции са предефиниране на променливата и промяна на полетата.




struct student {
	char name[30];
	int number;

};

void initStudent(student& mystud) {
	cin >> mystud.name >> mystud.number;

}
void printStudent(student& mystud) {
	cout << "student name" << endl;
	cout << mystud.name;
	cout << endl;
	cout << "student number" << endl;
	cout << mystud.number;
}


int main() {
	student mystudent;
	initStudent(mystudent);
	printStudent(mystudent);

}
