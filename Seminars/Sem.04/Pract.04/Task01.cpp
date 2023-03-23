#include <iostream>
#include <cstring>

const int MAX_TEACHER_NAME = 31;
const char *DEFAULT_NAME = "~DEFAULT~";

class Teacher
{
private:
    char m_name[MAX_TEACHER_NAME + 1];
    int m_age;
    int m_internship;

public:
    Teacher();

    Teacher(const char *name, int age, int internship);

    void SetName(const char *name);

    void SetAge(int age);

    void SetInternship(int internship);

    const char *GetName() const;

    int GetAge() const;

    int GetInternship() const;

    void Print() const;
};

Teacher::Teacher()
        : Teacher(DEFAULT_NAME, 1, 1)
{}

Teacher::Teacher(const char *name, int age, int internship)
{
    if (strlen(name) < MAX_TEACHER_NAME)
        strcpy_s(m_name, name);
    else
        strcpy_s(m_name, DEFAULT_NAME);

    m_age = age;
    m_internship = internship;
}

void Teacher::SetName(const char *name)
{
    if (!name || strlen(name) >= MAX_TEACHER_NAME)
        return;

    strcpy_s(m_name, name);
}

void Teacher::SetAge(int age)
{
    m_age = age;
}

void Teacher::SetInternship(int internship)
{
    m_internship = internship;
}

const char *Teacher::GetName() const
{
    return m_name;
}

int Teacher::GetAge() const
{
    return m_age;
}

int Teacher::GetInternship() const
{
    return m_internship;
}

void Teacher::Print() const
{
    std::cout << m_name << " - " << m_age << ", " << m_internship;
}


int main()
{
    Teacher th("Dragan Petrov", 46, 10);

    th.Print();
}
