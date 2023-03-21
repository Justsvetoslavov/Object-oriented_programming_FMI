#include <iostream>

const size_t MAX_NAME_LENGTH = 16;

void myStrCopy(char* str1, const char* str2)
{
	int counter{};

	while (str2[counter] != '\0')
	{
		str1[counter] = str2[counter];
		counter++;
	}

	str1[counter] = '\0';
}

class Teacher {

private:
	size_t age;
	size_t exp;
	char name[MAX_NAME_LENGTH + 1];
public:
	Teacher()
	{
		age = 0;
		exp = 0;
		name[0] = '\0';
	}

	Teacher(const char* name, const size_t age, const size_t exp)
	{
		this->age = age;
		this->exp = exp;
		myStrCopy(this->name, name);
	}

	bool setTeacherAge(const size_t age)
	{
		if (age <= 0 || age > 90)
		{
			return false;
		}
		else
		{
			this->age = age;
		}
		return true;
	}

	bool setTeacherExp(const size_t exp)
	{
		if (exp < 0 || exp > 60)
		{
			return false;
		}
		else
		{
			this->exp = exp;
		}
		return true;
	}

	bool setTeacherName(char name[MAX_NAME_LENGTH])
	{
		if (name == nullptr)
		{
			return false;
		}
		myStrCopy(this->name, name);
		return true;
	}

	size_t getTeacherAge()const
	{
		return age;
	}

	size_t getTeacherExp()const
	{
		return exp;
	}

	const char* getTeacherName()const
	{
		return name;
	}
};