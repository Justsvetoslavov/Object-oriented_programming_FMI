#pragma once
class MonsterCard {
private:
	char* name = nullptr;
	unsigned attackPoints = 0;
	unsigned defensePoints = 0;

private:
	void copyFrom(const MonsterCard& other);
	void free();

public:
	MonsterCard();
	MonsterCard(const char* name, int attackPoints, int defensePoints);
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	~MonsterCard();

	void SetName(const char* name);
	void SetAttackPoints(int points);
	void SetDefensePoints(int points);
};

