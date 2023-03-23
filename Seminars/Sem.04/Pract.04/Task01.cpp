#include <iostream>
#include <string.h>

#pragma warning(disable: 4996)

bool isUpper(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

bool allLower(const char* name)
{
    while (*name)
    {
        if (!isLower(*name))
            return false;
        name++;
    }
    return true;
}

class Teacher {

    char name[41];
    int age;
    int yearsIntern;
    bool possibleIntern(int yearsintern) const;

public:
    Teacher();
    Teacher(const char* name, int age, int yearsIntern);
    const char* getName() const;
    int getAge() const;
    int getYearsIntern() const;
    void setName(const char* name);
    void setAge(int age);
    bool setYearsIntern(int yearsIntern);


};


Teacher::Teacher() : Teacher("Unknown", 18, 0)
{}

Teacher::Teacher(const char* name, int age, int yearsIntern)
{
    setName(name);
    setAge(age);
    setYearsIntern(yearsIntern);
}


bool Teacher::possibleIntern(int yearsIntern) const
{
    return this->age - yearsIntern >= 16;
}


bool correctNameInput(const char* name)
{
    if (!name)
        return false;
    if (strlen(name) > 40)
        return false;
    if (!isUpper(*name))
        return false;
    if (!allLower(name + 1))
        return false;
    return true;

}


const char* Teacher::getName() const
{
    return name;
}


int Teacher::getAge() const
{
    return age;
}


int Teacher::getYearsIntern() const
{
    return yearsIntern;
}


void Teacher::setName(const char* name)
{
    if (correctNameInput(name))
        strcpy(this->name, name);
    else
        strcpy(this->name, "Unkown");
}


void Teacher::setAge(int age)
{
    if (age >= 18 && age <= 65)
        this->age = age;
    else
        this->age = 18;
}


bool Teacher::setYearsIntern(int yearsIntern)
{
    if (yearsIntern < 0 || yearsIntern > 50 || !possibleIntern(yearsIntern))
        return false;

    this->yearsIntern = yearsIntern;
   
}

int main()
{
    char name[41];
    int age, yearsIntern;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << std::endl << "Enter age: ";
    std::cin >> age;
    std::cout << std::endl << "Enter years of internship: ";
    std::cin >> yearsIntern;
    Teacher newTeach(name, age, yearsIntern);
   

}
