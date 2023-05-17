#include "Guest.h"

#include <stdexcept>

Guest::Guest(int ID, unsigned timeLeft) : Player(ID){
	_timeLeft = timeLeft;
}

bool Guest::levelUp() {
	throw std::invalid_argument("Guests can't level up!");
}