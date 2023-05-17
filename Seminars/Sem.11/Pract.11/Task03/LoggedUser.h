#pragma once

#include "Player.h"

const int MAX_PASSWORD_SIZE = 8;

class LoggedUser : public Player{
	char _password[MAX_PASSWORD_SIZE + 1];

public:
	LoggedUser();
	LoggedUser(int ID, const char* password);

	bool login(int ID, const char* password) const;

	// No override for levelUp()
};