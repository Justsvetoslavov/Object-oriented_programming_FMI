#include "Deck.h"
#include <iostream>
#pragma warning(disable: 4996)


int Deck::GetMagicCardsCount() const {
	return magicCardsCount;
}

int Deck::GetMonstersCount() const {
	return monsterCardsCount;
}

void Deck::AddMagicCard(const char* name, const char* effect, type cardType) {
	if (magicCardsCount == 20) {
		std::cout << "The magic cards deck is full!\n";
		return;
	}

	magicCards[magicCardsCount] = MagicCard(name, effect, cardType);
	magicCardsCount++;
}

void Deck::AddMagicCard(const MagicCard& card) {
	if (magicCardsCount == 20) {
		std::cout << "The magic cards deck is full!\n";
		return;
	}

	magicCards[magicCardsCount] = card;
	magicCardsCount++;
}

void Deck::AddMonsterCard(const char* name, int attackPoints, int defensePoints) {
	if (monsterCardsCount == 20) {
		std::cout << "The monster cards deck is full!\n";
		return;
	}

	monsterCards[monsterCardsCount] = MonsterCard(name, attackPoints, defensePoints);
	monsterCardsCount++;
}

void Deck::AddMonsterCard(const MonsterCard& card) {
	if (monsterCardsCount == 20) {
		std::cout << "The monster cards deck is full!\n";
		return;
	}

	monsterCards[monsterCardsCount] = card;
	monsterCardsCount++;
}

void Deck::ChangeMagicCard(int index, const char* name, const char* effect, type cardType) {
	if (index > 20) {
		std::cout << "The cards in the deck cannot exceed 20!\n";
		return;
	}
	if (index > magicCardsCount) {
		magicCards[magicCardsCount] = MagicCard(name, effect, cardType);
		magicCardsCount++;
	}
	magicCards[index - 1] = MagicCard(name, effect, cardType);
}

void Deck::ChangeMagicCard(int index, const MagicCard& card) {
	if (index > 20) {
		std::cout << "The cards in the deck cannot exceed 20!\n";
		return;
	}
	if (index > magicCardsCount) {
		magicCards[magicCardsCount] = card;
		magicCardsCount++;
	}
	magicCards[index - 1] = card;
}

void Deck::ChangeMonsterCard(int index, const char* name, int attackPoints, int defensePoints) {
	if (index > 20) {
		std::cout << "The cards in the deck cannot exceed 20!\n";
		return;
	}
	if (index > monsterCardsCount) {
		monsterCards[monsterCardsCount] = MonsterCard(name, attackPoints, defensePoints);
		monsterCardsCount++;
	}
	monsterCards[index - 1] = MonsterCard(name, attackPoints, defensePoints);
}

void Deck::ChangeMonsterCard(int index, const MonsterCard& card) {
	if (index > 20) {
		std::cout << "The cards in the deck cannot exceed 20!\n";
		return;
	}
	if (index > monsterCardsCount) {
		monsterCards[monsterCardsCount] = card;
		monsterCardsCount++;
	}
	monsterCards[index - 1] = card;
}

void Deck::RemoveMagicCard(int index) {
	if (index > magicCardsCount) {
		std::cout << "There is no magic card at the given position\n";
		return;
	}
	for (int i = index - 1; i < magicCardsCount - 1; i++) {
		magicCards[i] = magicCards[i + 1];
	}
	magicCardsCount--;
}

void Deck::RemoveMonsterCard(int index) {
	if (index > monsterCardsCount) {
		std::cout << "There is no monster card at the given position\n";
		return;
	}
	for (int i = index - 1; i < monsterCardsCount - 1; i++) {
		monsterCards[i] = monsterCards[i + 1];
	}
	monsterCardsCount--;
}
