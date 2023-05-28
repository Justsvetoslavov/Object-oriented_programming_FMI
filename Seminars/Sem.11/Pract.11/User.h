#pragma once

#include "Player.h"

class User : public Player {
private:
    char password[9];
    bool isLogin = false;
public:
    User(unsigned, const char *);

    void setPassword(const char *, const char *);

    bool getIsLogin() const;

    void login(const char *);

private:
    static bool isSamePass(const char *, const char *);

    void setPassword(const char *);
};
