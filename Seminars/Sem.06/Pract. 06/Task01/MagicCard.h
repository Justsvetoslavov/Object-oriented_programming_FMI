#pragma once
#include "GlobalConstants.h"

enum type {
	trap,
	buff,
	spell
};

class MagicCard {
private:
	char name[name_Max_Size + 1];
	char effect[effect_Max_Size + 1];
	type cardType;
public:
	MagicCard();
	MagicCard(const char* name, const char* effect, type cardType);
}; 

