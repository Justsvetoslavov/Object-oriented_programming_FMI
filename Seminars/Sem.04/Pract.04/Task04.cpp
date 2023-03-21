#include <iostream>


void myStrCopy(char* str1, const char* str2)
{
	int counter{};

	while (str2[counter] != '\0')
	{
		str1[counter] = str2[counter];
		counter++;
	}

	str1[counter] = '\0';
}

const int MAX_CONDITION_SIZE = 500;
const int MAX_PASSWORD_SIZE = 20;

bool compareString(const char* str1, const char* str2)
{
	size_t index{};

	bool areSame = true;

	while (str2[index] != '\0')
	{
		if (str1[index] != str2[index])
		{
			return false;
		}
	}

	return areSame;
}

class secret {
private:
	int amountOfLogins;
	char condition[MAX_CONDITION_SIZE + 1];
	char password[MAX_PASSWORD_SIZE + 1];

public:
	secret()
	{
		amountOfLogins = 0;
		condition[0] = '\0';
		password[0] = '\0';
	}

	secret(const char* condition, const char* password, const int& logins)
	{
		myStrCopy(this->condition, condition);
		myStrCopy(this->password, password);
		amountOfLogins = logins;
	}

	const char* getTask(const char* pwd)
	{
		if (compareString(this->password, pwd))
		{
			return this->condition;
		}

		return nullptr;
	}

	void setPassword(const char* newPassword, const char* oldPassword)
	{
		if (compareString(oldPassword, newPassword))
		{
			myStrCopy(this->password, newPassword);
		}
	}

	void setTask(const char* newTask, const char* passwd)
	{
		if (compareString(this->password, passwd))
		{
			myStrCopy(this->condition, newTask);
		}
	}

	int getLoginsFailed()const
	{
		return amountOfLogins;
	}

	void setLoginFails(const size_t num)
	{
		amountOfLogins = num;
	}
};