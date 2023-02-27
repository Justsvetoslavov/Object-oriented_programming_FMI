#include <iostream>
using std::cin;
using std::cout;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1


//Една група се състои от краен брой студенти, като броят на студентите се задава от вас.
//
//Създайте структура, която описва група.Структурата също така трябва да пази средния успех на групата.
//
//Направете функция, която създава група, вземайки информация от стандартния вход.Средния успех трябва да се сметне след въвеждане на информацията.
//Напишете функция, която приема група и минимален успех за стипендия, и връща колко студента ще получават стипендия.
//Създайте функция, която приема група и минимален успех за стипендия и извежда сортирани всички студенти, които ще получават стипендия
//идния семестър.

const int MAX = 50;
struct Student {
	char name[50];
	double grade;
};
struct Group {
	int numberofstudents;
	double gpa;
};

void inputdata(Student mystudent[], Group& mygroup) {
	cout << "enter nr of students in the group:";
	cin >> mygroup.numberofstudents;
	mygroup.gpa = 0;
	
	for (int i = 0; i < mygroup.numberofstudents; i++) {
		cin >> mystudent[i].name >> mystudent[i] .grade;
		mygroup.gpa += mystudent[i].grade;
	}
	mygroup.gpa /= mygroup.numberofstudents;


}
void  readinput(Student mystudent[], Group& mygroup) {
	for (int i = 0; i < mygroup.numberofstudents; i++) {
		cout << mystudent[i].name <<' '<< endl << mystudent[i].grade<<' '<<endl;
		
	}
	cout << "GROUP GPA IS:";
	cout << mygroup.gpa << endl;

}
void provideScholarship(Student mystud[], Group& mygroup) {
	double minimumScholarship = 5.5;
	int num = 0;
	
	for (int i = 0; i < mygroup.numberofstudents; i++) {
		if (mystud[i].grade >= minimumScholarship) {
			num++;
		}

	}
	cout << "Number of student who will gain a scholarship is:" << num << endl;


	cout << "STUDETNS WHO WILL GAIN A SCHOLARSHIP BASED ON THEIR GPA ARE:" << endl;
	for (int i = 0; i < mygroup.numberofstudents; i++) {
		for(int j=0;j<num;j++){
		if (mystud[j].grade <= mystud[j+1].grade) {
			Student temp = mystud[j];
			mystud[j] = mystud[j + 1];
			mystud[j + 1] = temp;
				
			}
		}

	}
	for (int i = 0; i < mygroup.numberofstudents; i++) {
		if (mystud[i].grade >= minimumScholarship) {
			cout << mystud[i].name << ' ' << mystud[i].grade;
		}
	}



}


int main() {
	cout << "Enter datas for students" << endl;
	Student mystudent[MAX];
	Group mygroup;
	inputdata(mystudent, mygroup);
	cout << "STUDENTS AND THEIR GRADES ARE:" << endl;
	readinput(mystudent, mygroup);
	provideScholarship(mystudent, mygroup);
}