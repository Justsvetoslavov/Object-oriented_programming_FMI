#include <iostream>
#include <cstring>

class Secret {
private:
	char* task;
	char* password;
	mutable int countOfLoginFails = 0;
public:
	Secret();
	Secret(const char* task, const char* password);

	void SetTask(const char* task);
	void SetPassword(const char* password);

	const char* GetTask(const char* password) const;
	bool SetPassword(const char* newPassword, const char* oldPassword);
	bool SetTask(const char* newTask, const char* password);
	int GetLoginFails() const;

	~Secret();
};

Secret::Secret() : Secret("Unknown", "Unknown") {}

Secret::Secret(const char* task, const char* password) {
	SetTask(task);
	SetPassword(password);
}

Secret::~Secret() {
	delete[] this->task;
	delete[] this->password;
}

void Secret::SetTask(const char* task) {
	if (task == nullptr)
		return;
	this->task = new char[strlen(task) + 1];
	strcpy_s(this->task, sizeof(this->task), task); // I have a problem with that function and I don't know how to fix it
}

void Secret::SetPassword(const char* password) {
	if (password == nullptr)
		return;
	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, sizeof(this->password), password);
}

const char* Secret::GetTask(const char* password) const {
	if (!strcmp(this->password, password))
		return task;

	countOfLoginFails++;
	return nullptr;
}

bool Secret::SetPassword(const char* newPassword, const char* oldPassword) {
	if (newPassword == nullptr || oldPassword == nullptr)
		return false;
	if (!strcmp(newPassword, oldPassword))
	{
		strcpy_s(this->password, sizeof(this->password), newPassword);
		return true;
	}
	countOfLoginFails++;
	return false;
}

bool Secret::SetTask(const char* newTask, const char* password) {
	if (newTask == nullptr || password == nullptr)
		return false;
	if (!strcmp(this->password, password))
	{
		strcpy_s(this->task, sizeof(this->task), newTask);
		return true;
	}
	countOfLoginFails++;
	return false;
}

int Secret::GetLoginFails() const {
	return countOfLoginFails;
}

int main()
{
	Secret secret("Some task", "123");
	secret.SetPassword("1233", "123");
	std::cout << "The count of failed logins is: " << secret.GetLoginFails();
	if (secret.SetTask("New task", "1233"))
		std::cout << "The task is successfully changed to: " << secret.GetTask("1233");
}
