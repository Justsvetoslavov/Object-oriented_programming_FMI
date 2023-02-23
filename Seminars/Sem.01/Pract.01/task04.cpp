<iostream>

using namespace std;

struct Student {
   char name[30];
   int facultyNumber;
};

void initStudent(Student &student) {
   cout << "Enter name: ";
   cin.getline(student.name, 30);
   do {
       cout << "Enter faculty number: ";
       cin >> student.facultyNumber;
   } while (student.facultyNumber <= 0);
   cin.ignore();
}

void printStudent(Student const &student) {
   cout << "Name: " << student.name << endl;
   cout << "Faculty number: " << student.facultyNumber << endl;
}

int main() {
   Student student{};
   initStudent(student);
   printStudent(student);
   return 0;
}
