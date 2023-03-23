#include <iostream>
#pragma warning (disable : 4996)
const char MESSAGE_UKNOWN[] = "Uknown";

class Secret {
private:
	char* task;
	char* password;
	int failedLogins;

	bool DoPasswordsMatch(const char* password) const;

public:
	Secret();
	Secret(const char* task, const char* password);

	const char* GetPassword() const;
	int GetFailedLogins() const;

	void SetTask(const char* task);
	void SetPassword(const char* password);

	const char* GetTask(const char* password);
	void SetPassword(const char* newPassword, const char* oldPassword);
	void SetTask(const char* newTask, const char* password);

	~Secret();
};

Secret::Secret() : Secret(MESSAGE_UKNOWN, MESSAGE_UKNOWN) {}

Secret::Secret(const char* task, const char* password) {
	this->task = new char[strlen(task) + 1];
	this->password = new char[strlen(password) + 1];
	SetTask(task);
	SetPassword(password);
}

const char* Secret::GetPassword() const {
	return password;
}

int Secret::GetFailedLogins() const {
	return failedLogins;
}

void Secret::SetTask(const char* task) {
	strcpy(this->task, task);
}

void Secret::SetPassword(const char* password) {
	strcpy(this->password, password);
}

Secret::~Secret() {
	delete[] task;
	delete[] password;
}

bool Secret::DoPasswordsMatch(const char* password) const {
	if (!strcmp(this->password, password)) {
		return true;
	}
	return false;
}

const char* Secret::GetTask(const char* password) {
	if (this->DoPasswordsMatch(password)) return this->task;

	this->failedLogins++;
}

void Secret::SetPassword(const char* newPassword, const char* oldPassword) {
	if (this->DoPasswordsMatch(oldPassword))
		strcpy(this->password, newPassword);

	this->failedLogins++;
}

void Secret::SetTask(const char* newTask, const char* password) {
	if (this->DoPasswordsMatch(password))
		strcpy(this->task, newTask);

	this->failedLogins++;
}

int main()
{
	Secret secret1("task1", "12345");

	std::cout << secret1.GetTask("12345");
	secret1.SetPassword("123", "1234");

	std::cout << secret1.GetPassword();
	std::cout << secret1.GetFailedLogins();
}
