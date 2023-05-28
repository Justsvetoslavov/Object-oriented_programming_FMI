
#include "User.h"

User::User(unsigned int id, const char *pass) : Player(id) {
    setPassword(pass);
}

void User::setPassword(const char *pass) {
    for (int i = 0; i < 9; ++i) {
        password[i] = pass[i];
    }
}

void User::setPassword(const char *oldPass, const char *pass) {
    if (isSamePass(oldPass, password)) {
        setPassword(pass);
    }
}

bool User::getIsLogin() const {
    return isLogin;
}

void User::login(const char *pass) {
    isLogin = isSamePass(pass, password);
}

bool User::isSamePass(const char *pass1, const char *pass2) {
    for (int i = 0; i < 9; ++i) {
        if (pass1[i] != pass2[i]) {
            return false;
        }
    }

    return true;
}
