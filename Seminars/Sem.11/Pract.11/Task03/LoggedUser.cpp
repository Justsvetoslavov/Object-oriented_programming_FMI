#include "LoggedUser.h"

#include <string.h>
#include <iostream>

#pragma warning(disable:4996)

LoggedUser::LoggedUser() {
	_password[0] = '\0';
}

LoggedUser::LoggedUser(int ID, const char* password) : Player(ID) {
	if (strlen(password) > MAX_PASSWORD_SIZE) {
		throw std::invalid_argument("The password you entered is too long.");
	}
	strcpy(_password, password);
}

const char* ERROR_MESSAGE = "Login failed\n";
const char* SUCCESS_MESSAGE = "Login successful\n";

bool LoggedUser::login(int ID, const char* password) const {
	unsigned len1 = strlen(password);
	unsigned len2 = strlen(_password);

	if (ID != _ID || len1 != len2) {
		std::cout << ERROR_MESSAGE;
		return false;
	}

	// The two passwords are of equal length
	for (int i = 0; i < len1; i++) {
		if (password[i] != _password[i]) {
			std::cout << ERROR_MESSAGE;
			return false;
		}
	}

	std::cout << SUCCESS_MESSAGE;
	return true;
}