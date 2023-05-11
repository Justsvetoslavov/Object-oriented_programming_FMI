#pragma once
class MonsterCard
{
private:
	char* name = nullptr;
	unsigned attackPoints = 0;
	unsigned defensePoints = 0;
public:
	MonsterCard();
	MonsterCard(const char* name, unsigned attackPoints, unsigned defensePoints);
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& other);
	~MonsterCard();

	const char* GetName() const;
	unsigned GetAttackPoints() const;
	unsigned GetDefensePoints() const;

	void SetName(const char* name);
	void SetAttackPoints(unsigned attackPoints);
	void SetDefensePoints(unsigned defensePoints);

private:
	void CopyFrom(const MonsterCard& other);
	void CopyName(const char* name);
	void Free();
};

 