#pragma once
#include <cstring>

const int MAX_NAME = 25;
const int MAX_DESCRIPTION = 100;

enum class Type {
    trap,
    buff,
    spell,
    undefined
};

class Magic {
    char name[MAX_NAME];
    char effect[MAX_DESCRIPTION];
    Type type = Type::undefined;

public:

    Magic() = default;

    Magic(const char *name, const char *effect, Type type);

    void delMagic();
};