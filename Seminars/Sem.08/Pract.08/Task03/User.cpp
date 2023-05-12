#include "User.h"
#include <sstream>

User::User(const char* name, const char* password, const char* email) {
	if (name == nullptr || password == nullptr || email == nullptr)
		throw std::invalid_argument("You entered an non existing text");

	this->name = name;
	this->password = password;
	this->email = email;
	receivedMessages = new Message[messagesCapacity];
}

void User::SetName(const char* name) {
	if (name == nullptr)
		throw std::invalid_argument("The name doesn't exist!");

	this->name = name;
}

void User::free() {
	delete[] receivedMessages;
	receivedMessages = nullptr;
	messagesCapacity = 2;
	messagesCount = 0;
}

void User::SetPassword(const char* password) {
	if (password == nullptr)
		throw std::invalid_argument("The password doesn't exist!");

	this->password = password;
}

void User::copyFrom(const User& user) {
	name = user.name;
	password = user.password;
	email = user.email;
	receivedMessages = new Message[user.messagesCapacity];
	messagesCapacity = user.messagesCapacity;
	messagesCount = user.messagesCount;
	for (int i = 0; i < user.messagesCount; i++)
		receivedMessages[i] = user.receivedMessages[i];
}

void User::SetEmail(const char* email) {
	if (email == nullptr)
		throw std::invalid_argument("The email doesn't exist!");

	this->email = email;
}

void User::Resize(){
	messagesCapacity *= 2;
	Message* temp = new Message[messagesCapacity];

	for (int i = 0; i < messagesCount; i++) {
		temp[i] = receivedMessages[i];
	}

	delete[] receivedMessages;
	receivedMessages = temp;
}

User::User(const User& user) {
	copyFrom(user);
}

User& User::operator=(const User& user) {
	if (this != &user) {
		free();
		copyFrom(user);
	}
	return *this;
}

User::~User(){
	free();
}

int User::GetMessagesCount() const{
	return messagesCount;
}

std::ostream& operator<<(std::ostream& os, const User& user){
	os << user.name.c_str() << '\n';
	os << user.password.c_str() << '\n';
	os << user.email.c_str() << '\n';
	os << user.messagesCapacity << ' ' << user.messagesCount;
	for (int i = 0; i < user.messagesCount; i++)
		os << user.receivedMessages[i];
	return os;
}

std::istream& operator>>(std::istream& is, User& user){
	is >> user.name >> user.password >> user.email;
	is >> user.messagesCapacity >> user.messagesCount;
	user.receivedMessages = new Message[user.messagesCapacity];
	for (int i = 0; i < user.messagesCount; i++)
		is >> user.receivedMessages[i];
	return is;
}
