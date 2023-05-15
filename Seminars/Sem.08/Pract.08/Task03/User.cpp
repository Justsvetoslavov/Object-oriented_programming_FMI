#include "User.h"
#include <cstring>
#include <sstream>
#pragma warning (disable : 4996)

const int INIT_CAPACITY = 8;
const int USER_BUFFER_SIZE = 1024;
const int USER_INFO_BUFFER = 256;

User::User() : User("default", "default", "default") {}

User::User(const char* name, const char* password, const char* email) {
	this->messagesCapacity = INIT_CAPACITY;
	this->messages = new Message[messagesCapacity];
	this->messagesCount = 0;
	SetName(name);
	SetPass(password);
	SetEmail(email);
}

void User::CopyFrom(const User& other) {
	this->name = other.name;
	this->email = other.email;
	this->password = other.password;
	this->messagesCount = other.messagesCount;
	this->messagesCapacity = other.messagesCapacity;
	this->messages = new Message[messagesCapacity];
	for (size_t i = 0; i < messagesCount; i++)
	{
		this->messages[i] = other.messages[i];
	}
}

void User::Free() {
	delete[] this->messages;
	this->messages = nullptr;
	this->messagesCapacity = 0;
	this->messagesCount = 0;
}

void User::AddMessage(const Message& message) {
	if (this->messagesCount >= this->messagesCapacity)
		Resize(this->messagesCapacity * 2);

	this->messages[messagesCount++] = message;
}

void User::Resize(size_t newCapacity) {
	Message* temp = this->messages;
	this->messages = new Message[newCapacity];
	for (size_t i = 0; i < this->messagesCount; i++)
	{
		this->messages[i] = temp[i];
	}
	this->messagesCapacity = newCapacity;
	delete[] temp;
}

void User::SetName(const char* name) {
	if (!name)
		throw std::invalid_argument("Invalid value!");

	this->name = MyString(name);
}

void User::SetPass(const char* pass) {
	if (!pass)
		throw std::invalid_argument("Invalid value!");

	this->password = MyString(pass);
}

void User::SetEmail(const char* email) {
	if (!email)
		throw std::invalid_argument("Invalid value!");

	this->email = MyString(email);
}

User::User(const char* name) {
	SetName(name);
}

User::User(const User& other) {
	CopyFrom(other);
}

User& User::operator=(const User& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

User::~User() {
	Free();
}

void User::SendMessage(User& to, const MyString& message) const {
	Message newMessage(this->name, message);
	to.messages[to.messagesCount++] = newMessage;
}

int User::GetIdOfFromUser(const User& fromUser) const {
	for (size_t i = 0; i < this->messagesCount; i++)
	{
		if (messages[i].GetUser() == fromUser.name)
			return i;
	}
	return -1;
}

const MyString& User::ReadMessage(const User& from) const {
	int idOfFromUser = GetIdOfFromUser(from);
	if (idOfFromUser == -1)
		throw std::invalid_argument("This user didn't send message!");

	return this->messages[idOfFromUser].GetMessage();
}

const MyString& User::GetName() const {
	return this->name;
}
const MyString& User::GetPassword() const {
	return this->password;
}
const MyString& User::GetEmail() const {
	return this->email;
}

const MyString& User::ReadAllMessages() const {
	MyString* messages = new MyString();
	for (size_t i = 0; i < messagesCount; i++)
	{
		*messages += (this->messages[i].GetUser() + ":" + this->messages[i].GetMessage()) + "\n";
	}
	return *messages;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
	os << user.name << ","
		<< user.email << ','
		<< user.password << std::endl;
	os << user.messagesCapacity << std::endl;
	os << user.messagesCount << std::endl;
	for (size_t i = 0; i < user.messagesCount; i++)
	{
		os << user.messages[i].GetUser() << ":";
		os << user.messages[i].GetMessage() << std::endl;
	}
	return os;
}
std::istream& operator>>(std::istream& is, User& user) {
	char userBuffer[USER_BUFFER_SIZE];
	is.getline(userBuffer, USER_BUFFER_SIZE);
	std::stringstream ss(userBuffer);

	while (!ss.eof()) {
		char nameBuffer[USER_INFO_BUFFER];
		ss.getline(nameBuffer, USER_INFO_BUFFER, ',');
		char emailBuffer[USER_INFO_BUFFER];
		ss.getline(emailBuffer, USER_INFO_BUFFER, ',');
		char passBuffer[USER_INFO_BUFFER];
		ss.getline(passBuffer, USER_INFO_BUFFER);

		user.SetName(nameBuffer);
		user.SetEmail(emailBuffer);
		user.SetPass(passBuffer);
	}
	size_t messagesCount;
	size_t messagesCapacity;
	is >> messagesCapacity;
	is >> messagesCount;
	is.ignore();
	user.messagesCapacity = messagesCapacity;
	for (size_t i = 0; i < messagesCount; i++)
	{
		char userMessageBuffer[USER_BUFFER_SIZE];
		is.getline(userMessageBuffer, USER_BUFFER_SIZE);
		std::stringstream ss(userMessageBuffer);

		Message message;
		while (!ss.eof()) {
			char nameBuffer[USER_INFO_BUFFER];
			ss.getline(nameBuffer, USER_INFO_BUFFER, ':');
			char messageBuffer[USER_INFO_BUFFER];
			ss.getline(messageBuffer, USER_INFO_BUFFER);
			message.SetMessage(messageBuffer);
			User fromUser(nameBuffer);
			message.SetUser(nameBuffer);

			user.AddMessage(message);
		}
	}
	return is;
}