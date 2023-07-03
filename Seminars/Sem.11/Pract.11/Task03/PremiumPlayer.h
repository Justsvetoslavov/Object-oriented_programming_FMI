#pragma once

#include "MyString.h"
#include "Player.h"

class PremiumPlayer : public Player{
	MyString _name = "Anonymous";
public:
	PremiumPlayer() = default;
	PremiumPlayer(int ID, const MyString& name);

	bool levelUp() override;
};