#pragma once
#include <iostream>
#pragma warning(disable : 4996)

const int MAX_NAME_SIZE = 25;
const int MAX_EFFECT_SIZE = 100;

enum class CardType
{
    trap,
    buff,
    spell,
    unknown
};

class MagicCard
{
    char name[MAX_NAME_SIZE + 1];
    char effect[MAX_EFFECT_SIZE + 1];
    CardType type;

public:

    MagicCard();

    MagicCard(const char* name, const char* effect, const CardType type);

    MagicCard(const MagicCard& other);

    MagicCard& operator=(const MagicCard& other);

    ~MagicCard();

    const char* getName() const;

    const char* getEffect() const;

    CardType getType() const;
};
