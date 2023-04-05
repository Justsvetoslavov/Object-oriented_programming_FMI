#pragma once

namespace {
	const int MAX_NAME_LEN = 25;
	const int MAX_EFFECT_LEN = 100;

	const char* DEFAULT_NAME = "Unknown name";
	const char* DEFAULT_EFFECT = "Unknown effect";
}

enum class Type {
	trap,
	buff,
	spell,
	unknown
};

class MagicCard {
	char name[MAX_NAME_LEN + 1];
	char effect[MAX_EFFECT_LEN + 1];

	Type type = Type::unknown;

public:
	MagicCard();
	MagicCard(const char* name, const char* effect, const Type& type);

	void setName(const char* name);
	void setEffect(const char* effect);
	void setType(const const Type& type);

	const char* getName() const;
	const char* getEffect() const;
	const Type& getType() const;

	void print() const;
};