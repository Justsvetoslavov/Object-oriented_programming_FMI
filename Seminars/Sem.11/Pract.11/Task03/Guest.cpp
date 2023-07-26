#include "Guest.h"

Guest::Guest(unsigned id, unsigned minutesToPlay)
        : Player(id), minutesLeft{minutesToPlay} {}

unsigned Guest::getMinutesLeft() const {
    return minutesLeft;
}

void Guest::decrementMinutes(unsigned amount) {
    if (minutesLeft <= amount) {
        minutesLeft = 0;
    } else {
        minutesLeft -= amount;
    }
}

bool Guest::levelUp() {
    return false;
}

