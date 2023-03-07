#include <iostream>
#include <fstream>
#include <sstream>

const int FIELD_MAX_SIZE = 128;
const int USERS_MAX_SIZE = 100;
const int COMMAND_MAX_SIZE = 128;

const char USERS_FILE[] = "users.txt";

struct User {
	char name[FIELD_MAX_SIZE];
	char email[FIELD_MAX_SIZE];
	char password[FIELD_MAX_SIZE];
};

struct System {
	User users[USERS_MAX_SIZE];
	size_t systemCurrentSize = 0;
};

unsigned GetCharCountFromFile(std::ifstream& readFile, char ch)
{
	size_t currentPosition = readFile.tellg();
	readFile.seekg(0, std::ios::beg);

	if (!readFile.is_open())
		return 0;

	unsigned count = 0;

	while (true)
	{
		char current = readFile.get();
		if (readFile.eof())
			break;

		if (current == ch)
			count++;
	}
	readFile.seekg(currentPosition);

	return count;
}
unsigned GetUsersCount(const char* fileName)
{
	std::ifstream myFile(fileName);

	if (!myFile.is_open())
		return 0;

	return GetCharCountFromFile(myFile, '\n');
}

void InitUser(char* name, char* email, char* password) {
	std::cout << "Enter name: " << std::endl;
	std::cin >> name;
	std::cout << "Enter email: " << std::endl;
	std::cin >> email;
	std::cout << "Enter password: " << std::endl;
	std::cin >> password;
}

User CreateUser(const char* name, const char* email, const char* password) {
	User newUser;
	strncpy_s(newUser.name, name, FIELD_MAX_SIZE);
	strncpy_s(newUser.email, email, FIELD_MAX_SIZE);
	strncpy_s(newUser.password, password, FIELD_MAX_SIZE);
	return newUser;
}

User ReadUser(std::ifstream& readFile, size_t userId) {
	User user;

	char buffer[FIELD_MAX_SIZE];

	readFile.getline(buffer, FIELD_MAX_SIZE);
	
	std::stringstream ss;
	ss << buffer;

	char nameBuff[FIELD_MAX_SIZE];
	char emailBuff[FIELD_MAX_SIZE];
	char passwordBuff[FIELD_MAX_SIZE];
	ss.getline(nameBuff, FIELD_MAX_SIZE, ',');
	ss.getline(emailBuff, FIELD_MAX_SIZE, ',');
	ss.getline(passwordBuff, FIELD_MAX_SIZE);

	user = CreateUser(nameBuff, emailBuff, passwordBuff);
	return user;
}

void WriteUserToFile(std::ofstream& writeFile, const User& user) {
	writeFile << user.name << "," << user.email << "," << user.password << std::endl;
}

void WriteSystemToFile(std::ofstream& writeFile, const System& system) {
	for (size_t i = 0; i < system.systemCurrentSize; i++)
	{
		WriteUserToFile(writeFile, system.users[i]);
	}
}
System ReadSystem(std::ifstream& readFile) {
	System system;

	for (size_t i = 0; i < GetUsersCount(USERS_FILE); i++)
	{
		User user = ReadUser(readFile, i + 1);
		system.users[i] = user;
		system.systemCurrentSize++;
	}

	return system;
}

void Login(const System& system, const char* name, const char* email, const char* password) {
	size_t systemSize = system.systemCurrentSize;

	for (size_t i = 0; i < systemSize; i++)
	{
		if (!std::strcmp(name, system.users[i].name) &&
			!std::strcmp(email, system.users[i].email) &&
			!std::strcmp(password, system.users[i].password)) {
			std::cout << "Logged successfully!" << std::endl;
			return;
		}
	}

	std::cout << "You don't have registration!" << std::endl;
}

int main()
{
	System system;
	std::ifstream readFile(USERS_FILE);

	if (!readFile.is_open()) {
		std::cout << "Error!";
		return 0;
	}

	system = ReadSystem(readFile);

	char command[COMMAND_MAX_SIZE];
	while (true) {
		char name[FIELD_MAX_SIZE];
		char email[FIELD_MAX_SIZE];
		char password[FIELD_MAX_SIZE];

		std::cout << "Enter command: " << std::endl;
		std::cin >> command;

		if (!std::strcmp(command, "-1")) {
			break;
		}

		if (!std::strcmp(command, "register")) {
			InitUser(name, email, password);

			std::ofstream writeFile(USERS_FILE, std::ios::app);

			if (!writeFile.is_open()) {
				std::cout << "Error!";
				return 0;
			}

			User user = CreateUser(name, email, password);

			WriteUserToFile(writeFile, user);
			system.users[system.systemCurrentSize] = user;
			system.systemCurrentSize++;

			std::cout << "Registered successfully!" << std::endl;
			writeFile.close();
		}

		if (!std::strcmp(command, "login")) {
			InitUser(name, email, password);
			Login(system, name, email, password);
			readFile.close();
		}
	}
}
