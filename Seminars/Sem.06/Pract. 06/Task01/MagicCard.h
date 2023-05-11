#pragma once
#include <cstring>

const int NAME_MAX_SIZE = 25;
const int EFFECT_MAX_SIZE = 100;

enum class Type {
	trap,
	buff,
	spell
};

class MagicCard
{
private:
	char name[NAME_MAX_SIZE + 1];
	char effect[EFFECT_MAX_SIZE + 1];
	Type type;
public:
	MagicCard() = default;
	MagicCard(const char* name, const char* effect, const Type type);

	void SetName(const char* name);
	void SetEffect(const char* effect);
	void SetType(const Type type);

	const char* GetName() const;
	const char* GetEffect() const;
	const Type& GetType() const;
};
 