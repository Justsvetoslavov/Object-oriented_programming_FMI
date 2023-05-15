#include <iostream>
#include "System.h"

bool UserExists(const MyString& username, const MyString& password, const System& system) {
	if (system.FindUserIdByName(username.c_str()) != -1) {
		if (system.PasswordMatchWithName(username.c_str(), password.c_str())) {
			std::cout << "Logged in successfully!" << std::endl;
			return true;
		}
		else {
			std::cout << "Password doesn't match username! Please try again." << std::endl;
			return false;
		}
	}
	else
		std::cout << "There is no such username! Please try again." << std::endl;
	return false;
}

void SendMessage(System& system, User& loggedUser) {
	std::cout << "Enter username you want to send messsage to: ";
	MyString toUsername;
	std::cin >> toUsername;
	User toUser(toUsername.c_str());
	std::cout << "Enter message: ";
	MyString message;
	std::cin >> message;
	try {
		system.SendMessage(loggedUser, toUser, message);
		std::cout << "Message sent successfully!" << std::endl;
	}
	catch (const std::invalid_argument& exc) {
		std::cout << exc.what() << std::endl;
	}
}

void SeeMessages(System& system, User& loggedUser) {
	std::cout << "Enter username you want to see messages from: ";
	MyString fromUsername;
	std::cin >> fromUsername;
	User fromUser(fromUsername.c_str());
	bool messageSentSuccessfully = true;
	try {
		std::cout << system.ReadMessage(fromUser, loggedUser) << std::endl;
	}
	catch (const std::invalid_argument& exc) {
		std::cout << exc.what();
	}
}

void LogIn(System& system) {
	std::cout << "Enter username: ";
	MyString username;
	std::cin >> username;
	std::cout << "Enter password: ";
	MyString password;
	std::cin >> password;
	if (UserExists(username, password, system)) {
		while (true) {
			User loggedUser(username.c_str());
			std::cout << "Enter command: \n1 - Send message"
				"\n2 - Look all of your messages\n3 - Look message from specific user"
				"\n4 - Log out" << std::endl;
			char command;
			std::cin >> command;
			if (command == '1') {
				SendMessage(system, loggedUser);
			}
			else if (command == '2') {
				system.ReadAllMessages(loggedUser);
			}
			else if (command == '3') {
				SeeMessages(system, loggedUser);
			}
			else if (command == '4') {
				std::cout << "Logging out..." << std::endl;
				break;
			}
			else {
				std::cout << "Invalid command, please try again!" << std::endl;
			}
		}
	}
}

void Register(System& system) {
	User newUser;
	std::cout << "Enter username: ";
	MyString username;
	std::cin >> username;
	std::cout << "Enter email: ";
	MyString email;
	std::cin >> email;
	std::cout << "Enter password: ";
	MyString password;
	std::cin >> password;
	try {
		newUser.SetName(username.c_str());
		newUser.SetEmail(email.c_str());
		newUser.SetPass(password.c_str());
	}
	catch (const std::invalid_argument& exc) {
		std::cout << exc.what() << std::endl;
	}

	try {
		system.AddUser(newUser);
	}
	catch (const std::length_error& exc) {
		std::cout << exc.what() << std::endl;
	}
	std::cout << "Registered successfully!" << std::endl;
}

void Run() {
	System system;
	system.GetSystemFromFile("file2.txt");

	while (true) {
		std::cout << "Enter command: \n1 - Log in \n2 - Register \n3 - Exit" << std::endl;
		char command;
		std::cin >> command;
		if (command == '1') {
			LogIn(system);
		}
		else if (command == '2') {
			Register(system);
		}
		else if (command == '3') {
			break;
		}
		else {
			std::cout << "Invalid command, please try again!" << std::endl;
		}
	}
	system.SaveSystem("file3.txt");
}

int main()
{
	Run();
}