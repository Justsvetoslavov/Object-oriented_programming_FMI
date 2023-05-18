#ifndef LOGGEDPLAYER_H
#define LOGGEDPLAYER_H

#include "Player.h"

class LoggedPlayer : public Player
{
    static const int MAX_PASSWORD_LEN = 8;
    char m_password[MAX_PASSWORD_LEN + 1];

    LoggedPlayer(int id, const char* password);
public:
    LoggedPlayer LoginPlayer(int id, const char* password);
};


#endif
