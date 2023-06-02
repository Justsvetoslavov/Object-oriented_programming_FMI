#include <iostream>
#include "ChatSystem.h"
#include "GlobalConstants.h"

User InputUser() {
	User user;
	std::cout << "Enter username: ";
	char buff[buff_Size];
	std::cin.ignore();
	std::cin.getline(buff, buff_Size);
	try {
		user.SetName(buff);
	}
	catch (const std::invalid_argument& inv) {
		std::cout << inv.what();
	}
	std::cout << "Enter password: ";
	std::cin.getline(buff, buff_Size);
	user.SetPassword(buff);
	std::cout << "Enter email: ";
	std::cin.getline(buff, buff_Size);
	user.SetEmail(buff);
	std::cout << "You have registered successfully!\n";
	return user;
}

bool CheckLogIn(const ChatSystem& system) {
	std::cout << "Enter name or email: ";
	char buff[buff_Size];
	std::cin.ignore();
	std::cin.getline(buff, buff_Size);
	int index = system.CheckUserEmailOrName(buff);
	if (index == -1) {
		std::cout << "There is no user with such name or email!\n";
		return false;
	}
	std::cout << "Enter password: ";
	std::cin.getline(buff, buff_Size);
	if (system.CheckPasswordMatch(index, buff)) {
		std::cout << "You have logged in successfully!\n";
		return true;
	}
	else {
		std::cout << "The password doesn't match!\n";
		return false;
	}
}

void CheckCommand(int& command) {
	while (command < 1 || command > 3) {
		std::cout << "Wrong command! Please try again: ";
		std::cin >> command;
	}
}

void PrintStartMenu() {
	std::cout << "1. Login\n";
	std::cout << "2. Register\n";
	std::cout << "3. Exit\n";
	std::cout << "\nPlease choose a number: ";
}

void PrintLoggedInMenu() {
	std::cout << "1. Send a message\n";
	std::cout << "2. Preview received messages\n";
	std::cout << "3. Log out\n";
	std::cout << "\nPlease choose a number: ";
}

void InputMessage(ChatSystem& system) {
	system.PrintEmails();
	std::cout << "Enter receiver's email: ";
	char email[buff_Size];
	std::cin.ignore();
	std::cin.getline(email, buff_Size);
	char message[buff_Size];
	std::cout << "Enter the message: ";
	std::cin.getline(message, buff_Size);
	system.SendMessageTo(email, message);
}

int main()
{
	ChatSystem system;
	system.ReadFromFile("ChatSystem.txt"); 

	std::cout << "----Welcome----\n";
	while (true) {
		PrintStartMenu();
		int command;
		std::cin >> command;
		CheckCommand(command);

		if (command == 1) {
			if (CheckLogIn(system)) {
				while (true) {
					PrintLoggedInMenu();
					std::cin >> command;
					CheckCommand(command);

					if (command == 1) {
						InputMessage(system);
					}
					else if (command == 2) {
						system.PrintUserMessages();
					}
					else {
						std::cout << "Logging out!\n";
						break;
					}
				}
			}
		}
		else if (command == 2) {
			User user = InputUser();
			system.AddUser(user);
		}
		else {
			std::cout << "Goodbye!";
			break;
		}
	}
	system.SaveToFile("ChatSystem.txt");
}

