#pragma once

const short NAME_MAX_SIZE = 26;
const short EFFECT_MAX_SIZE = 101;

enum class MagicCardType {
	trap,
	buff,
	spell,
	unknown
};

class MagicCard {
private:
	char name[NAME_MAX_SIZE];
	char effect[EFFECT_MAX_SIZE];
	MagicCardType type;
public:
	MagicCard();
	MagicCard(const char* name, const char* effect, const MagicCardType type);

	MagicCard(const MagicCard& magicCard) = default;
	MagicCard& operator=(const MagicCard& magicCard) = default;
	~MagicCard() = default;

	const char* const getName() const;
	const char* const getEffect() const;
	MagicCardType getMagicCardType() const;
};