#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const int USER_PROPERTY_MAX_LENGTH = 129;
const int PROPERTY_VALUE_MAX_LENGTH = 101;
const int SYSTEM_MAX_USERS_COUNT = 101;
const int COMMAND_MAX_LENGTH = 31;
const char* REGISTER_COMMAND = "register";
const char* LOGIN_COMMAND = "login";
const char* FILE_NAME = "SystemOfUsers.txt";

struct User
{
	char* name = new char[USER_PROPERTY_MAX_LENGTH];
	char* email = new char[USER_PROPERTY_MAX_LENGTH];
	char* password = new char[USER_PROPERTY_MAX_LENGTH];
};

struct System
{
	User* users = new User[SYSTEM_MAX_USERS_COUNT];
	int usersCount = 0;
};

void initUser(User& user)
{
	std::cin.ignore();
	std::cout << "Enter name:" << std::endl;
	std::cin >> user.name;
	std::cout << "Enter email:" << std::endl;
	std::cin >> user.email;
	std::cout << "Enter password:" << std::endl;
	std::cin >> user.password;
}

void getUserFromLine(const char* line, User& user)
{
	int index = 0;
	while (line[0] != ' ')
	{
		user.email[index++] = line[0];
		line++;
	}
	user.email[index] = '\0';

	line++;
	index = 0;
	while (line[0] != ' ')
	{
		user.name[index++] = line[0];
		line++;
	}
	user.name[index] = '\0';

	line++;
	index = 0;
	while (line[0] != '\0')
	{
		user.password[index++] = line[0];
		line++;
	}
	user.password[index] = '\0';
}

// returns true if their symbols are matching
bool compareStrings(const char* firstString, const char* secondString)
{
	while (firstString[0] != '\0')
	{
		if (secondString[0] != firstString[0])
		{
			return false;
		}

		firstString++;
		secondString++;
	}

	if (secondString[0] != '\0')
	{
		return false;
	}

	return true;
}

int getIndexOfUser(const System& system, const char* email)
{
	int index = 0;
	if (compareStrings(system.users[index].email, email))
	{
		return index;
	}
	index++;
}

void saveUser(std::ofstream& users, const User& user)
{
	users << user.email << " " << user.name << " " << user.password << std::endl;
}

void getSystemFromFile(std::ifstream& users, System& system)
{
	int prevPos = users.tellg();
	users.seekg(0, std::ios::beg);
	char buff[BUFF_SIZE];

	while (!users.eof() && system.usersCount <= PROPERTY_VALUE_MAX_LENGTH)
	{
		users.getline(buff, BUFF_SIZE, '\n');
		User user;
		getUserFromLine(buff, user);
		system.users[system.usersCount++] = user;
	}

	users.seekg(prevPos);
}

User* getUserByEmail(System& system, const char* userEmail)
{
	for (size_t i = 0; i < system.usersCount; i++)
	{
		if (compareStrings(userEmail, system.users[i].email))
		{
			return &(system.users[getIndexOfUser(system, userEmail)]);
		}
	}

	return nullptr;
}

int main()
{
	char command[COMMAND_MAX_LENGTH];
	std::cout << "Enter command:" << std::endl;
	std::cin >> command;

	if (compareStrings(command, REGISTER_COMMAND))
	{
		User user;
		initUser(user);
		std::ofstream myFile(FILE_NAME);
		if (myFile.is_open())
		{
			saveUser(myFile, user);
		}
		myFile.close();
	}
	else if (compareStrings(command, LOGIN_COMMAND))
	{
		System system;
		std::ifstream myFile(FILE_NAME);
		if (myFile.is_open())
		{
			char email[USER_PROPERTY_MAX_LENGTH];
			char password[USER_PROPERTY_MAX_LENGTH];

			std::cout << "Enter email:" << std::endl;
			std::cin.ignore();
			std::cin >> email;

			getSystemFromFile(myFile, system);
			User* currUser = getUserByEmail(system, email);

			if (currUser != nullptr)
			{
				std::cout << "Enter password:" << std::endl;
				std::cin.ignore();
				std::cin >> password;
				if (compareStrings((*currUser).password, password))
				{
					std::cout << "Login successful" << std::endl;
				}
				else
				{
					std::cout << "Login unsuccessful" << std::endl;
				}
			}
			else
			{
				std::cout << "A user with this email does not exists!";
			}
			delete[] currUser;
		}
		myFile.close();
	}
}
