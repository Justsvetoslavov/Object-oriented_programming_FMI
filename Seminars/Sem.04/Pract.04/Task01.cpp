#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)
class Teacher {
private:
	char* name;
	int age;
	int yearsOfExperience;
	bool IsInvalidName(const char* name) const;
public:
	Teacher();
	Teacher(const char* name, int age, int yearsOfExperience);

	const char* getName() const;
	int getAge() const;
	int getYearsOfExperience() const;

	void setName(const char* name);
	void setAge(int age);
	void setYearsOfExperience(int yearsOfExperience);

	~Teacher();

};

Teacher::Teacher() : Teacher("No name", 0, 0) {}

Teacher::Teacher(const char* name, int age, int yearsOfExperience) {
	this->name = new char[strlen(name) + 1];
	setName(name);
	setAge(age);
	setYearsOfExperience(yearsOfExperience);
}

const char* Teacher::getName() const {
	return name;
}

int Teacher::getAge() const {
	return age;
}

int Teacher::getYearsOfExperience() const {
	return yearsOfExperience;
}

bool Teacher::IsInvalidName(const char* name) const {
	return (strlen(name) > 20 || !name);
}


void Teacher::setName(const char* name) {
	if(!IsInvalidName(name))
		strcpy_s(this->name, sizeof(this->name), name);

	return;
}

void Teacher::setAge(int age) {
	if (age <= 20 && age >= 60)
		return;
	this->age = age;
}

void Teacher::setYearsOfExperience(int yearsOfExperience) {
	if (yearsOfExperience < 0 && yearsOfExperience >= 50)
		return;
	this->yearsOfExperience = yearsOfExperience;
}

Teacher::~Teacher() {
	delete[] name;
}
int main()
{
	Teacher t("t1", 22, 5);
	std::cout << "Teacher name: " << t.getName() << "\nTeacher age: " << t.getAge()
		<< "\nTeacher years of experience: " << t.getYearsOfExperience() << std::endl;

	t.setName("t2");
	std::cout << "\nTeacher new name: " << t.getName();
}
