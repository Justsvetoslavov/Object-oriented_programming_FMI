#include <iostream>
using namespace std;

const int STUDENT_NAME_LENGTH = 30;

struct Student {
	char name[STUDENT_NAME_LENGTH + 1];
	size_t facultyNumber;
};

bool InitStudent(Student&, char*, int);
void PrintStudent(const Student&);

int main() {							// предефиниране на променливата / промяна на полетата
	Student st = { "Gosho", 10 };		//	            да               /			да
	Student* pSt = &st;					//				да				 /			да
	const Student* pCSt = &st;			//				да  			 /			не
	Student* const cPSt = &st;			//				не				 /			да
	const Student* const cpCSt = &st;	//				не  			 /			не
	Student& refSt = st;				//				да				 /			да
	const Student& refCSt = st;			//				не  			 /			не
}

void PrintStudent(const Student& toPrint) {
	cout << "Name: " << toPrint.name << endl;
	cout << "Faculty number: " << toPrint.facultyNumber << endl;
}

int CharArrayLength(char* arr) {
	int length = 0;
	while (arr[length] != '\0') length++;
	return length;
}

bool InfoIsValid(char* name, int facultyNumber) {
	if (CharArrayLength(name) > STUDENT_NAME_LENGTH) return false;
	if (facultyNumber < 0) return false;
	return true;
}

bool InitStudent(Student& toInit, char* name, int facNumber) {
	if (!InfoIsValid(name, facNumber))
	{
		return false;
	}
	int i = 0;
	while (name[i - 1] != '\0')
	{
		toInit.name[i] = name[i];
		i++;
	}
	toInit.facultyNumber = facNumber;
	return true;
}
