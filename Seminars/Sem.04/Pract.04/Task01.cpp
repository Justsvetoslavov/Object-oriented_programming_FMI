#include <iostream>
#include <cstring>

const int name_max_size = 50;
bool IsNameValid(const char* name);

class Teacher {
private:
	char name[name_max_size + 1];
	int age;
	int internship;
public:
	Teacher();
	Teacher(const char* name, int age, int internship);

	const char* GetName() const;
	int GetAge() const;
	int GetInternship() const;

	void SetName(const char* name);
	void SetAge(int age);
	void SetInternship(int internship);
};

Teacher::Teacher() : Teacher("Unknown", 16, 0) {}

Teacher::Teacher(const char* name, int age, int internship) {
	SetName(name);
	SetAge(age);
	SetInternship(internship);
}

const char* Teacher::GetName() const {
	return name;
}

int Teacher::GetAge() const {
	return age;
}

int Teacher::GetInternship() const {
	return internship;
}

void Teacher::SetName(const char* name) {
	if (strlen(name) > name_max_size || !IsNameValid(name))
		name = "Unknown";
	strcpy_s(this->name, name);
}

void Teacher::SetAge(int age) {
	if (age < 16 || age > 80)
		age = 16;
	this->age = age;
}

bool IsNameValid(const char* name) {
	if (name[0] < 'A' || name[0] > 'Z')
		return false;

	for (int i = 1; name[i] != '\0'; i++)
		if (name[i] < 'a' || name[i] > 'z')
			return false;

	return true;
}

void Teacher::SetInternship(int internship) {
	if (internship < 0)
		internship = 0;
	this->internship = internship;
}

Teacher ReadTeacherInfo() {
	Teacher teacher;
	std::cout << "Enter teacher name: ";
	char buff[name_max_size + 1];
	std::cin.getline(buff, name_max_size + 1, '\n');
	teacher.SetName(buff);
	std::cout << "Enter age: ";
	int age;
	std::cin >> age;
	teacher.SetAge(age);
	std::cout << "Enter internship: ";
	int internship;
	std::cin >> internship;
	teacher.SetInternship(internship);
	return teacher;
}

int main()
{
	Teacher teacher = ReadTeacherInfo();
	std::cout << "Teacher: " << teacher.GetName() << std::endl;
	std::cout << "Age: " << teacher.GetAge() << std::endl;
	std::cout << "Internship: " << teacher.GetInternship();
}
