#pragma once
#include "Message.h"
class User
{
private:
	MyString name;
	MyString password;
	MyString email;

	Message* messages = nullptr;
	size_t messagesCount = 0;
	size_t messagesCapacity = 0;
public:
	User();
	User(const char* name);
	User(const char* name, const char* password, const char* email);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	void SendMessage(User& to, const MyString& message) const;
	const MyString& ReadMessage(const User& from) const;
	const MyString& ReadAllMessages() const;

	const MyString& GetName() const;
	const MyString& GetPassword() const;
	const MyString& GetEmail() const;

	void SetName(const char* name);
	void SetPass(const char* pass);
	void SetEmail(const char* email);

	void AddMessage(const Message& message);
private:
	void CopyDynamicCharArray(char*& destination, const char* source);
	void CopyName(const char* name);
	void CopyPassword(const char* pass);
	void CopyEmail(const char* email);
	void CopyFrom(const User& other);
	void Free();
	int GetIdOfFromUser(const User& fromUser) const;
	void Resize(size_t newCapacity);

	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);
};

