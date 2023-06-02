#pragma once
#include "String.h"
#include "Message.h"
#include "GlobalConstants.h"

class User{
private:
	String name;
	String password;
	String email;
	Message* receivedMessages = nullptr;
	unsigned messagesCount = 0;
	unsigned messagesCapacity = 2;

	void free();
	void copyFrom(const User& user);
	void Resize();

public:
	User() = default;
	User(const char* name, const char* password, const char* email);
	User(const User& user);
	User& operator=(const User& user);
	~User();

	void SetName(const char* name);
	void SetPassword(const char* password);
	void SetEmail(const char* email);

	int GetMessagesCount() const;

	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);

	friend class ChatSystem;
};

