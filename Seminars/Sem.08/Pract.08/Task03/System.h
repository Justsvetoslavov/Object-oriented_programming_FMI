#pragma once
#include "User.h"
#include "Message.h"
const int USERS_MAX_COUNT = 100;

class System
{
private:
	User users[USERS_MAX_COUNT];
	size_t usersCount = 0;
public:
	System() = default;

	void AddUser(const User& user);
	void SendMessage(const User& from, User& to, const MyString& message);
	const MyString& ReadMessage(const User& from, const User& to) const;
	void ReadAllMessages(const User& to) const;

	int FindUserIdByName(const MyString& name) const;
	bool PasswordMatchWithName(const char* name, const char* password) const;

	void GetSystemFromFile(const char* filePath);
	void SaveSystem(const char* filePath) const;

private:
	void CheckChatUsersId(const User& from, const User& to, int& fromId, int& toId) const;
};


