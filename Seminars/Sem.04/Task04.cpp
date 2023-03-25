#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)

const char MESSAGE_UNKNOWN[] = "Unknown";
const int MAX_TASK_SIZE = 256;
const int MAX_PASSWORD_SIZE = 15;

class Secret {
private:
	char task[MAX_TASK_SIZE + 1];
	char password[MAX_PASSWORD_SIZE + 1];
	mutable int failedLogins;

	bool DoPasswordsMatch(const char* password) const;
	bool IsInvalidTask(const char* task) const;
	bool IsInvalidPassword(const char* password) const;

public:
	Secret() = default;
	Secret(const char* task, const char* password);
	Secret(const Secret&) = delete;
	Secret& operator=(const Secret&) = delete;

	int GetFailedLogins() const;
	const char* GetTask(const char* password) const;

	void SetTask(const char* requirement);

	void SetNewPassword(const char* newPassword, const char* oldPassword);
	void SetTask(const char* newTask, const char* password);

};

Secret::Secret(const char* task, const char* password) {
	SetTask(task);
	strcpy(this->password, password);
	failedLogins = 0;
}

int Secret::GetFailedLogins() const {
	return failedLogins;
}

void Secret::SetTask(const char* task) {
	if (IsInvalidTask(task)) return;

	strcpy(this->task, task);
}

bool Secret::IsInvalidTask(const char* task) const {
	return (strlen(task) > MAX_TASK_SIZE || !task);
}

bool Secret::IsInvalidPassword(const char* password) const {
	return (strlen(password) > MAX_PASSWORD_SIZE || !password);
}

bool Secret::DoPasswordsMatch(const char* password) const {
	if (!strcmp(this->password, password)) {
		return true;
	}
	return false;
}

const char* Secret::GetTask(const char* password) const {
	if (this->DoPasswordsMatch(password)) 
		return this->task;

	this->failedLogins++;
}

void Secret::SetNewPassword(const char* newPassword, const char* oldPassword) {
	if (this->DoPasswordsMatch(oldPassword)) {
		strcpy(this->password, newPassword);
		return;
	}
	this->failedLogins++;
}

void Secret::SetTask(const char* newTask, const char* password) {
	if (this->DoPasswordsMatch(password)) {
		strcpy(this->task, newTask);
		return;
	}

	this->failedLogins++;
}

int main()
{
	Secret secret1("task1", "12345");

	std::cout << "Secret is: " << secret1.GetTask("12345") << std::endl;
	std::cout << "Failing password" << std::endl;
	secret1.SetNewPassword("123", "1234");
	std::cout << "Number of failings: " << secret1.GetFailedLogins() << std::endl;

	std::cout << "Setting new password" << std::endl;
	secret1.SetNewPassword("123", "12345");

	secret1.SetNewPassword("1234", "123");
	std::cout << "Number of failings: " << secret1.GetFailedLogins() << std::endl;
}