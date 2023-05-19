#include "PremiumPlayer.h"
#include <utility>
#include <cstring>

PremiumPlayer::PremiumPlayer(unsigned int id, const char *username)
        : Player(id) {
    copyUsername(username);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer &other) : Player(other) {
    copyFrom(other);
}

PremiumPlayer::PremiumPlayer(PremiumPlayer &&other) noexcept
        : Player(std::move(other)) {
    moveFrom(std::move(other));
}

PremiumPlayer &PremiumPlayer::operator=(const PremiumPlayer &other) {
    if (this != &other) {
        Player::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

PremiumPlayer &PremiumPlayer::operator=(PremiumPlayer &&other) noexcept {
    if (this != &other) {
        Player::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

PremiumPlayer::~PremiumPlayer() {
    free();
}

void PremiumPlayer::free() {
    delete[] username;
    username = nullptr;
}

void PremiumPlayer::copyFrom(const PremiumPlayer &other) {
    copyUsername(other.username);
}

void PremiumPlayer::moveFrom(PremiumPlayer &&other) {
    username = other.username;
    other.username = nullptr;
}

void PremiumPlayer::copyUsername(const char *username) {
    if (!username) {
        this->username = new char[12];
        strcpy(this->username, "no username");
        return;
    }

    this->username = new char[strlen(username) + 1];
    strcpy(this->username, username);
}

const char *PremiumPlayer::getUsername() const {
    return username;
}

void PremiumPlayer::setUsername(const char *newUsername) {
    free();
    copyUsername(newUsername);
}

bool PremiumPlayer::levelUp() {
    if (stars == Stars::five) {
        return false;
    }
    return upgrade(256);
}



