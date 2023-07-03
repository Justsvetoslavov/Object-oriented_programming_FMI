#include "Player.h"

#include <iostream>

Player::Player(int ID) {
	_ID = ID;
}

const int NUMBER_OF_STARS = 5;
const int POINTS[4] = { 256, 512, 1024, 2048 };

bool Player::levelUp() {
	if (_star == Star::fifth) {
		std::cout << "Maximal level reached\n";
		return false;
	}

	for (int i = 0; i < NUMBER_OF_STARS; i++) {
		// The user has the points to possibly reach the next level 
		if (_points >= POINTS[i]) {
			// Check the user's level - it should match the value of i 
			if (_star == (Star)i) {
				_star = (Star)(i + 1); // Increase the level by one
				_points -= POINTS[i];
				return true;
			}
		}

		// The player doesn't have enough points to reach the next level
		else {
			return false;
		}
	}
}