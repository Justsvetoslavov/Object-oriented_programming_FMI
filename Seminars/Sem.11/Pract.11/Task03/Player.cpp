#include "Player.h"

Player::Player(unsigned id) : id{id}, points{0}, stars{Stars::one} {}

unsigned Player::getId() const {
    return id;
}

unsigned Player::getPoints() const {
    return points;
}

Stars Player::getStars() const {
    return stars;
}

void Player::setPoints(unsigned newPoints) {
    points = newPoints;
}

void Player::addPoints(unsigned amount) {
    points += amount;
}

void Player::removePoints(unsigned amount) {
    if (points <= amount) {
        points = 0;
    } else {
        points -= amount;
    }
}

bool Player::upgrade(unsigned required) {
    if (points < required) {
        return false;
    }
    removePoints(required);
    upgradeStars(stars);
    return true;
}

bool Player::levelUp() {
    switch (stars) {
        case Stars::one:
            return upgrade(256);
        case Stars::two:
            return upgrade(512);
        case Stars::three:
            return upgrade(1024);
        case Stars::four:
            return upgrade(2048);
        case Stars::five:
            return false;
    }
}