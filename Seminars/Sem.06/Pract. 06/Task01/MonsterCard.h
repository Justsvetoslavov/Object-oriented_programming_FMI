#pragma once

const short MAX_SIZE = 26;

class MonsterCard {
private:
	char name[MAX_SIZE];
	size_t attPoints;
	size_t defPoints;
public:
	MonsterCard();
	MonsterCard(const char*, size_t, size_t);

	MonsterCard(const MonsterCard& monsterCard) = default;
	MonsterCard& operator=(const MonsterCard& monsterCard) = default;
	~MonsterCard() = default;

	size_t getAttPoints() const;
	size_t getDefPoints() const;
	const char* const getName() const;
};