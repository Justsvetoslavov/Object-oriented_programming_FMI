#include <cstring>

const size_t MAX_NAME_LENGTH = 20;

class Teacher {
private:
    char name[MAX_NAME_LENGTH + 1];
    size_t age;
    size_t workYears;

public:
    Teacher();

    Teacher(const char *name, size_t age, size_t workYears);

    const char *getName() const;

    size_t getAge() const;

    size_t getWorkYears() const;

    void setName(const char *name);

    void setAge(size_t age);

    void setWorkYears(size_t workYears);


};
