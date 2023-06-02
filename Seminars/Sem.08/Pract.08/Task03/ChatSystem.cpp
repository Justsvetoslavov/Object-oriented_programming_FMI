#include "ChatSystem.h"
#include <sstream>
#include <iostream>

void ChatSystem::AddUser(const User& user) {
	if (usersCount == max_Users_Count)
		throw std::out_of_range("The maximum capacity of users is 100!");

	users[usersCount++] = user;
}

bool ChatSystem::CheckPasswordMatch(int index, const char* password) const {
	if (password == nullptr)
		throw std::invalid_argument("The password doesn't exist");

	if (!strcmp(users[index].password.c_str(), password)) {
		loggedInIndex = index;
		return true;
	}
	return false;
}

void ChatSystem::SendMessageTo(const char* email, const char* message) {
	if (email == nullptr)
		throw std::invalid_argument("The email doesn't exist!");

	if (loggedInIndex == -1) {
		std::cout << "You must log in first in your account!\n";
		return;
	}

	for (int i = 0; i < usersCount; i++) {
		if (!strcmp(users[i].email.c_str(), email)) {
			if (users[i].messagesCount >= users[i].messagesCapacity)
				users[i].Resize();

			users[i].receivedMessages[users[i].messagesCount] = Message(users[loggedInIndex].email.c_str(), message);
			users[i].messagesCount++;

			std::cout << "Message is successfully sent!\n";
			return;
		}
	}
	std::cout << "There is no such email address!\n";
}

void ChatSystem::PrintEmails() const{
	if (usersCount <= 1)
		return;
	std::cout << "Other users' emails:\n";
	for (int i = 0; i < usersCount; i++) {
		if (i == loggedInIndex)
			continue;
		std::cout << users[i].email.c_str() << std::endl;
	}
}

void ChatSystem::PrintUserMessages() const{
	if (loggedInIndex == -1) {
		std::cout << "You must log in first in your account!\n";
		return;
	}
	int count = users[loggedInIndex].messagesCount;
	if (count == 0) {
		std::cout << "There are no messages!\n";
		return;
	}
	std::cout << "You have " << count << " messages\n";
	for (int i = 0; i < count; i++) {
		users[loggedInIndex].receivedMessages[i].Print();
	}
}

void ChatSystem::SaveToFile(const char* fileName) const{
	if (!fileName)
		throw std::invalid_argument("The file name doesn't exist");

	std::ofstream file(fileName);
	if (!file.is_open())
		throw std::exception("The file couldn't open");

	file << usersCount;
	for (int i = 0; i < usersCount; i++) {
		file << users[i];
	}
	file.close();
}

void ChatSystem::ReadFromFile(const char* fileName){
	if (!fileName)
		throw std::invalid_argument("The file name doesn't exist");

	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::exception("The file couldn't open");

	file >> usersCount;
	for (int i = 0; i < usersCount; i++)
		file >> users[i];
	file.close();
}

int ChatSystem::CheckUserEmailOrName(const char* text) const {
	if (text == nullptr)
		throw std::invalid_argument("The email or name doesn't exist!");

	for (int i = 0; i < usersCount; i++) {
		if (!strcmp(users[i].name.c_str(), text))
			return i;
		else if (!strcmp(users[i].email.c_str(), text))
			return i;
	}

	return -1;
}
