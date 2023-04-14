#include <cstring>

class Student {
    char *name;
    int fac_num;
    int grades;
    int count_grades;

    void free();

    void copyFrom(const Student &student);

public:
    Student();

    Student(const Student &student);

    ~Student();

    Student(const char *name, const int num);

    Student &operator=(const Student &student);

    void addGrade(const int grade);

    int getNum() const;

    void editGrade(const int grade);

    double getAverageGrade() const;
};
