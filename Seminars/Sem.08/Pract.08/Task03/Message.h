#pragma once
#include "MyString.h"
class Message
{
private:
	MyString fromUser;
	MyString message;
public:
	Message() = default;
	Message(const MyString& user, const MyString& message);

	const MyString& GetMessage() const;
	const MyString& GetUser() const;

	void SetUser(const MyString& fromUser);
	void SetMessage(const MyString& message);
};

