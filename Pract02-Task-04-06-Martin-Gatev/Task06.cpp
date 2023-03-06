#include <iostream>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const int MAX_LENGTH = 128;
const int MAX_BUFFER_SIZE = 50;
const int MAX_USERS = 100;
const int MAX_COMMAND_SIZE = 10;
const int LOGIN_SIZE = 6;

struct User {
	char name[MAX_LENGTH];
	char email[MAX_LENGTH];
	char password[MAX_LENGTH];
};

int ReadUserFromFile(User& user, const char* fileName, const long long posToStart)
{
	std::ifstream ReadFile(fileName);

	if (!ReadFile.is_open())
	{
		return -1;
	}

	ReadFile.seekg(posToStart, std::ios::beg);

	char tempBuffer[MAX_BUFFER_SIZE], buffer[MAX_BUFFER_SIZE];

	ReadFile.getline(tempBuffer, MAX_BUFFER_SIZE, ': ');

	ReadFile.getline(buffer, MAX_BUFFER_SIZE, '\n');

	for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		user.name[i] = buffer[i];
	}

	ReadFile.seekg(1, std::ios::cur);

	ReadFile.getline(tempBuffer, MAX_BUFFER_SIZE, ': ');

	ReadFile.getline(buffer, MAX_BUFFER_SIZE, '\n');

	for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		user.email[i] = buffer[i];
	}

	ReadFile.seekg(1, std::ios::cur);

	ReadFile.getline(tempBuffer, MAX_BUFFER_SIZE, ': ');

	ReadFile.getline(buffer, MAX_BUFFER_SIZE, '\n');

	for (int i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		user.password[i] = buffer[i];
	}
	ReadFile.seekg(1, std::ios::cur);

	int currPos = ReadFile.tellg();

	ReadFile.close();

	return currPos;
}

int WriteUserInFile(const User& user, const char* fileName, std::ofstream& WriteFile, const long long posToWrite)
{
	if (!WriteFile.is_open())
	{
		return -1;
	}

	WriteFile.seekp(posToWrite, std::ios::beg);

	WriteFile << "Username: " << user.name << endl <<
		"E-mail: " << user.email << endl <<
		"Password: " << user.password << endl << endl;

	int pos = WriteFile.tellp();

	return pos;
}

struct System
{
	User users[MAX_USERS];
};

int GetArrLength(const char* arr)
{
	int counter{};
	while (arr[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

void WriteSystem(const System& system, const char* fileName)
{
	const char write[] = "printUsers.txt";

	int index{}, pos{};

	std::ofstream WriteFile(write);

	while (GetArrLength(system.users[index].name) != 0)
	{
		pos = WriteUserInFile(system.users[index], write, WriteFile, pos);
		index++;
	}

	WriteFile.close();
}

void ReadSystem(System& system, const char* fileName)
{
	long long posToStart{};

	for (int i = 0; i < 10; i++)
	{
		posToStart = ReadUserFromFile(system.users[i], fileName, posToStart);

	}
}

void SetDefaultValuesChar(char* arr)
{
	if (arr == nullptr)
	{
		return;
	}

	for (size_t i = 0; i < 70; i++)
	{
		arr[i] = '\0';
	}
}

void Login(const char* fileName)
{
	std::ifstream ReadFile(fileName);

	if (!ReadFile.is_open())
	{
		return;
	}

	User user;

	char tempBuffer[30], buffer[70];

	ReadFile.getline(tempBuffer, 30, ': ');

	SetDefaultValuesChar(buffer);

	SetDefaultValuesChar(user.name);

	ReadFile.getline(buffer, 70, '\n');

	cout << endl << "Enter a name: " << endl;

	cin >> user.name;

	int indexName{};
	bool isLoginName = true;

	while (user.name[indexName] != '\0')
	{
		if (user.name[indexName] != buffer[indexName])
		{
			isLoginName = false;
			break;
		}
		indexName++;
	}

	if (isLoginName == false)
	{
		cout << "Incorrect name! Try again!" << endl;
		return;
	}
	else
	{
		ReadFile.getline(tempBuffer, 30, ': ');

		SetDefaultValuesChar(buffer);

		SetDefaultValuesChar(user.email);

		ReadFile.getline(buffer, 70, '\n');

		cout << endl << "Enter an email: " << endl;

		cin >> user.email;

		int indexEmail{};
		bool isLoginEmail = true;

		while (user.email[indexEmail] != '\0')
		{
			if (user.email[indexEmail] != buffer[indexEmail])
			{
				isLoginEmail = false;
				break;
			}
			indexEmail++;
		}

		if (isLoginEmail == false)
		{
			cout << "Incorrect email! Try Again!" << endl;
			return;
		}
		else
		{
			ReadFile.getline(tempBuffer, 30, ': ');

			SetDefaultValuesChar(buffer);

			SetDefaultValuesChar(user.password);

			ReadFile.getline(buffer, 70, '\n');

			cout << endl << "Enter a password: " << endl;

			cin >> user.password;

			int indexPass{};
			bool isLoginPass = true;

			while (user.password[indexPass] != '\0')
			{
				if (user.password[indexPass] != buffer[indexPass])
				{
					isLoginPass = false;
					break;
				}
				indexPass++;
			}

			if (isLoginPass == false)
			{
				cout << "Incorrect password! Try Again!" << endl;
				return;
			}
			else
			{
				cout << "You logged in successfully!" << endl;
			}
		}


	}
	ReadFile.close();
}

void Register(const char* fileName)
{
	std::ofstream WriteFile(fileName);

	char command[MAX_COMMAND_SIZE], myLogin[] = "login";

	long long posToWrite{};

	if (!WriteFile.is_open())
	{
		return;
	}

	User user;

	cout << endl << "Enter a name: " << endl;

	cin >> user.name;

	cout << endl << "Enter an e-mail: " << endl;

	cin >> user.email;

	cout << endl << "Enter a password: " << endl;

	cin >> user.password;

	posToWrite = WriteUserInFile(user, fileName, WriteFile, posToWrite);

	cout << endl << "Registration successful!" << endl;

	WriteFile.close();

	cout << "If you want to login type 'login'. If you want to exit, type 'exit'" << endl;

	bool isLogin = true;

	SetDefaultValuesChar(command);

	cin >> command;

	for (size_t i = 0; i < LOGIN_SIZE; i++)
	{
		if (command[i] != myLogin[i])
		{
			isLogin = false;
			break;
		}
	}

	if (isLogin)
	{
		Login(fileName);
	}
	else
	{
		return;
	}

}

void StartLogin(const char* fileName)
{
	cout << "Enter a command: " << endl;

	char command[MAX_COMMAND_SIZE], myRegister[] = "register";;

	cin >> command;

	bool isRegister = true;

	for (size_t i = 0; i < MAX_COMMAND_SIZE; i++)
	{
		if (command[i] != myRegister[i])
		{
			isRegister = false;
			break;
		}
	}

	if (isRegister == true)
	{
		Register(fileName);
	}
	else
	{
		Login(fileName);
	}
}


int main()
{
	char registered[] = "registered.txt";

	StartLogin(registered);

	return 0;
}