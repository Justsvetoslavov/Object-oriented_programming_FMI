#pragma once

class Monster {
	char* name = nullptr;
	size_t attack = 0;
	size_t defense = 0;

	void copyFrom(const Monster& other);
	void free();

	void copyName(const char* newName);

public:

	Monster() = default;
	Monster(const char* name, size_t attack, size_t defense);

	Monster(const Monster& other);
	Monster operator=(const Monster& other);

	~Monster();

	void setName(const char* name);
	void setAttack(size_t attack);
	void setDefense(size_t defense);

	const char* getName() const;
	size_t getAttack() const;
	size_t getDefense() const;

	void print() const;
};