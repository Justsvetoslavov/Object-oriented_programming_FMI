#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 128,
		  MAX_USERS = 100;
char path[MAX_SIZE] = "C:\\Users\\boris\\OneDrive\\Desktop\\account.txt";

struct User
{
	char username[MAX_SIZE],
		 password[MAX_SIZE],
		 email[MAX_SIZE];
};

struct System
{
	int entries = 0;
	User users[MAX_USERS];
};

void saveAccount(User& user, bool overwrite)
{
	ofstream streamWriter;
	if (overwrite) streamWriter.open(path, ofstream::trunc);
	else streamWriter.open(path, ofstream::app);

	if (streamWriter.is_open())
		streamWriter << user.username << '\n'
					 << user.password << '\n'
					 << user.email;

	streamWriter.close();
}

User readAccount(void)
{
	ifstream streamReader(path);
	User user;

	streamReader.getline(user.username, MAX_SIZE);
	streamReader.getline(user.password, MAX_SIZE);
	streamReader.getline(user.email,    MAX_SIZE);

	streamReader.close();
	return user;
}

void saveSys(System& sys, bool overwrite)
{
	ifstream streamWriter(path);
	for (int i = 0; i < sys.entries; ++i)
	{
		streamWriter >> sys.users[i].username;
		streamWriter >> sys.users[i].password;
		streamWriter >> sys.users[i].email;
	}

	streamWriter.close();
}

void readSys(System& sys)
{
	ifstream streamReader(path);
	User user;

	int i = 0;
	while (!streamReader.eof())
	{
		streamReader.getline(user.username, MAX_SIZE);
		streamReader.getline(user.password, MAX_SIZE);
		streamReader.getline(user.email, MAX_SIZE);

		sys.users[i++] = user;
	}
	sys.entries = i;

	streamReader.close();
}

bool strComp(char* str1, char* str2, int amount)
{
	for (int i = 0; i < amount; ++i)
		if (str1[i] != str2[i])
			return false;
	return true;
}

int length(char* str)
{
	int i = 0;
	while (str[i++] != '\0');
	return i - 1;
}

int main()
{
	char rgstr[] = "register",
		 login[] = "login",
		 buffer[MAX_SIZE];

	System sus;
	readSys(sus);

	int i = 0;
	while (1)
	{
		cout << "Enter command:\n\\>";
		cin.getline(buffer, MAX_SIZE);

		if (strComp(rgstr, buffer, length(rgstr)))
		{
			User user;

			cout << "Enter name:\n\\>";
			cin.getline(user.username, MAX_SIZE);
			cout << "Enter email:\n\\>";
			cin.getline(user.email, MAX_SIZE);
			cout << "Enter password:\n\\>";
			cin.getline(user.password, MAX_SIZE);

			sus.users[i++] = user;
			sus.entries = i;
			saveSys(sus, ofstream::app);

			cout << "Registration succesful\n";
		}
		else if (strComp(login, buffer, length(login)))
		{
			char email[MAX_SIZE],
				 pass[MAX_SIZE];

			cout << "Enter email:\n\\>";
			cin.getline(email, MAX_SIZE);
			cout << "Enter password:\n\\>";
			cin.getline(pass, MAX_SIZE);

			bool flag = false;
			for (int j = 0; j < sus.entries && !flag; ++j)
				if (strComp(sus.users[i].email,    email, length(email)) &&
					strComp(sus.users[i].password, pass,  length(pass))  )
					flag = true;

			if (flag)
				cout << "Login successful\n";
			else
				cout << "Incorrect credentials\n";
		}
		else
			cout << "Incorrect command\n";
	}

	return 0;
}