#pragma once

#include "Player.h"

class LoggedPlayer : public Player {
    static const short password_len = 8;
    char password[password_len + 1];
public:
    LoggedPlayer(unsigned id, const char *password);
};