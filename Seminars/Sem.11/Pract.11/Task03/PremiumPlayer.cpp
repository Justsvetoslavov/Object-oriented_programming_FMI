#include "PremiumPlayer.h"

PremiumPlayer::PremiumPlayer(int ID, const MyString& name) : Player(ID){
	_name = name;
}

const int NUMBER_OF_STARS = 5;
const int MIN_POINTS = 256;

bool PremiumPlayer::levelUp() {
	if (_points < MIN_POINTS || _star == Star::fifth) {
		return false;
	}

	// The user has enough points to level up
	// and hasn't reached the last level yet. 
	_star = (Star)((int)_star + 1); // Increase level by 1
	_points -= MIN_POINTS;
	return true;
}