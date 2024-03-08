#pragma once

#include <fstream>
#include "Globals.h"

using namespace globals;

class Task {
    char name[MAX_NAME_SIZE + 1];
    char description[MAX_DESCRIPTION_SIZE + 1];
    unsigned points;

public:
    unsigned getPoints() const;

    void setDescription(const char* _description);
    void setName(const char* _name);
    void setPoints(const int& _points);

    void writeToFile(std::ofstream& file) const;
    void readFromFile(std::ifstream& file);
};