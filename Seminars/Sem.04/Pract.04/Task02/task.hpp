#include <cstring>

const int MAX_DESCRIPTION = 100;
const int MAX_NAME = 20;

class Task {
private:
    char name[MAX_NAME + 1];
    char description[MAX_DESCRIPTION + 1];
    size_t points;
public:
    Task();

    Task(const char *name, const char *description, int points);

    void setName(const char *name);

    void setDescription(const char *description);

    void setPoints(int points);

    const char *getName() const;

    const char *getDescription() const;

    int getPoints() const;
};
