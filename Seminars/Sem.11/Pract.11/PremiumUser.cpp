#include "PremiumUser.h"
#include <string>
#include <iostream>

unsigned PremiumUser::getPointsNeeded() const {
    return 256;
}

PremiumUser::PremiumUser(unsigned int id, const char *pass, const char *name) : User(id, pass) {
    setUsername(name);
}

void PremiumUser::setUsername(const char *username) {
    this->username = new char[std::strlen(username) + 1];
    strcpy(this->username, username);
}

const char *PremiumUser::getUsername() const {
    return username;
}

void PremiumUser::sendMessage(const char *massage) const {
    std::cout << massage;
}

void PremiumUser::free() {
    delete[] username;
}

void PremiumUser::copyFrom(const PremiumUser &other) {
    setUsername(other.username);
}

void PremiumUser::moveFrom(PremiumUser &&other) {
    setUsername(other.username);
    username = nullptr;
}

PremiumUser::PremiumUser(const PremiumUser &other) : User(other) {
    copyFrom(other);
}

PremiumUser::PremiumUser(PremiumUser &&other) : User(std::move(other)) {
    moveFrom(std::move(other));
}

PremiumUser &PremiumUser::operator=(const PremiumUser &other) {
    if (this != &other) {
        User::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

PremiumUser &PremiumUser::operator=(PremiumUser &&other) {

    if (this != &other) {
        User::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

