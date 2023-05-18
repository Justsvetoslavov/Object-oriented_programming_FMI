
#include "Player.h"

Player::Player(unsigned int id) : id(id), points(0), stars(Stars::one) {}

unsigned Player::getPointsNeeded() const {
    return 2 << (int) stars;
}

bool Player::levelUp() {
    unsigned pointsNeeded = getPointsNeeded();

    if (points < pointsNeeded) {
        return false;
    }

    points -= pointsNeeded;

    return true;
}

void Player::progressOnMission(Mission &mission) {
    if (!mission.isComplete()) {
        mission.addProgress();
        return;
    }

    points += mission.getPoints();
}