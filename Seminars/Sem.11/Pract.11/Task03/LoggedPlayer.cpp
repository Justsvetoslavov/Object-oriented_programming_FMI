#include "LoggedPlayer.h"
#include <cstring>

LoggedPlayer::LoggedPlayer(int id, const char *password)
        : Player(id)
{
    if (!password)
        return;

    size_t size = strlen(password);
    if (size >= MAX_PASSWORD_LEN + 1)
    {
        strcpy_s(m_password, "NULLPTR");
        return;
    }

    strcpy_s(m_password, password);
}
LoggedPlayer LoggedPlayer::LoginPlayer(int id, const char *password)
{
    if (!password || strlen(password) >= MAX_PASSWORD_LEN + 1)
        return LoginPlayer(-1, nullptr);

    return LoggedPlayer(id, password);
}
