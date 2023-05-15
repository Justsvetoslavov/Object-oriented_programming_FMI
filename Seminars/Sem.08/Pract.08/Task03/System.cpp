#include "System.h"
#include <iostream>
#include <fstream>
#include <sstream>

void System::CheckChatUsersId(const User& from, const User& to, int& fromId, int& toId) const {
	fromId = FindUserIdByName(from.GetName());
	if (fromId == -1)
		throw std::invalid_argument("From user doesn't exist!");

	toId = FindUserIdByName(to.GetName());
	if (toId == -1)
		throw std::invalid_argument("To user doesn't exist!");
}

void System::AddUser(const User& user) {
	if (this->usersCount >= USERS_MAX_COUNT)
		throw std::length_error("Max count of users is 100!");

	this->users[usersCount++] = user;
}

void System::SendMessage(const User& from, User& to, const MyString& message) {
	int fromId, toId;
	CheckChatUsersId(from, to, fromId, toId);
	this->users[fromId].SendMessage(this->users[toId], message);
}

const MyString& System::ReadMessage(const User& from, const User& to) const {
	int fromId, toId;
	CheckChatUsersId(from, to, fromId, toId);
	return this->users[toId].ReadMessage(this->users[fromId]);
}

int System::FindUserIdByName(const MyString& name) const {
	for (size_t i = 0; i < this->usersCount; i++)
	{
		if (this->users[i].GetName() == name)
			return i;
	}
	return -1;
}

bool System::PasswordMatchWithName(const char* name, const char* password) const {
	for (size_t i = 0; i < usersCount; i++)
	{
		if (this->users[i].GetName() == name && this->users[i].GetPassword() == password)
			return true;
	}
	return false;
}

void System::ReadAllMessages(const User& to) const {
	int toId = FindUserIdByName(to.GetName());
	const MyString* allMessages = &this->users[toId].ReadAllMessages();
	std::cout << *allMessages;
	delete allMessages;
}

void System::GetSystemFromFile(const char* filePath) {
	if (!filePath)
		throw std::invalid_argument("Invalid value for file path!");
	std::ifstream ifs(filePath);
	if (!ifs.is_open())
		throw std::invalid_argument("This file doesn't exist!");

	while (true) {
		if (ifs.eof()) {
			break;
		}
		User newUser;
		ifs >> newUser;
		this->AddUser(newUser);
	}
	ifs.close();
}

void System::SaveSystem(const char* filePath) const {
	if (!filePath)
		throw std::invalid_argument("Invalid value for file path!");
	std::ofstream ofs(filePath);
	if (!ofs.is_open())
		throw std::invalid_argument("This file doesn't exist!");

	for (size_t i = 0; i < this->usersCount; i++)
	{
		ofs << this->users[i];
	}
	ofs.close();
}