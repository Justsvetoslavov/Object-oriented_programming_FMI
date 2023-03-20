#include <iostream>

const int LENGTH = 20;

class Teacher {

private:
	char name[LENGTH];
	int age;
	int yearsOfTeaching;

public:
	Teacher(const char name[LENGTH], int age, int yearsOfTeaching) {
		setName(name);
		setAge(age);
		setYearsofTeaching(yearsOfTeaching);
	}

	const char * getName()const 
	{
		return name;
	}
	int getAge()const 
	{
		return age;
	}
	int getYearsOfTeaching()const 
	{
		return yearsOfTeaching;
	}
	void setName(const char name[])
	{
		int index = 0;
		while (name[index] != '\0') {
			this->name[index] = name[index];
			index++;
		}
		this->name[index] = '\0';
	}
	void setAge(int age) 
	{
		if (age >= 0) {
			this->age = age;
		}

	}
	void setYearsofTeaching(int yearsOfTeaching) 
	{
		if (yearsOfTeaching >= 0) {
			this->yearsOfTeaching = yearsOfTeaching;
		}

	}
	~Teacher() {

	}

};
int main() {
	Teacher t1("Lisa", 28, 5);

     std::cout << "Name:" << t1.getName() << std::endl;
     std::cout << "Age:" << t1.getAge() << std::endl;
     std::cout << "Years of Teaching:" << t1.getYearsOfTeaching() << std::endl;

	 t1.setName("Jane");
	 t1.setAge(35);
	 t1.setYearsofTeaching(10);

	 std::cout << "Name:" << t1.getName() << std::endl;
	 std::cout << "Age:" << t1.getAge() << std::endl;
	 std::cout << "Years of Teaching:" << t1.getYearsOfTeaching() << std::endl;
	  
	 return 0;
	
}
	


