
#include "LoggedPlayer.h"
#include <cstring>

LoggedPlayer::LoggedPlayer(unsigned int id, const char *password)
        : Player(id) {
    strncpy(this->password, password, password_len);
}
