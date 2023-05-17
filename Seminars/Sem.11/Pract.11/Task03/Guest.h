#pragma once

#include "Player.h"

class Guest : public Player{
	unsigned _timeLeft = 0; // measured in seconds 

public:
	Guest() = default;
	Guest(int ID, unsigned timeLeft);
	bool levelUp() override;
};