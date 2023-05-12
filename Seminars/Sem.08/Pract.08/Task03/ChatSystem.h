#pragma once
#include "User.h"
#include "Message.h"
#include "GlobalConstants.h"

class ChatSystem{
private:
	User users[max_Users_Count];
	unsigned usersCount = 0;
	mutable int loggedInIndex = -1;

public:
	void AddUser(const User& user);
	int CheckUserEmailOrName(const char* text) const;
	bool CheckPasswordMatch(int index, const char* password) const;
	void SendMessageTo(const char* email, const char* message);
	void PrintEmails() const;
	void PrintUserMessages() const;
	void SaveToFile(const char* fileName) const;
	void ReadFromFile(const char* fileName);
};

