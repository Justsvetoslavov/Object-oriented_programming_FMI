
#include "Guest.h"
#include <cmath>

Guest::Guest(unsigned int id, unsigned int time) : Player(id), timeLeft(time) {}

bool Guest::levelUp() {
    return false;
}

unsigned Guest::getTimeLeft() const {
    return timeLeft;
}

void Guest::decrementTime(unsigned int time) const {
    timeLeft = std::max(timeLeft - time, 0);
}

bool Guest::canPlay() const {
    return timeLeft != 0;
}

void Guest::progressOnMission(Mission &mission) {
    if (canPlay()) {
        Player::progressOnMission(mission);
    }
}