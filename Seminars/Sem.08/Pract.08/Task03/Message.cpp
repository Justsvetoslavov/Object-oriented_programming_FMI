#include "Message.h"
#include "MyString.h"
Message::Message(const MyString& fromUser, const MyString& message) {
	this->fromUser = fromUser;
	this->message = message;
}

const MyString& Message::GetMessage() const {
	return this->message;
}

const MyString& Message::GetUser() const {
	return this->fromUser;
}

void Message::SetUser(const MyString& user) {
	this->fromUser = user;
}
void Message::SetMessage(const MyString& message) {
	this->message = message;
}