#pragma once

const unsigned short MAX_DESCRIPTION_LENGTH = 1024;
const unsigned short MAX_PASSWORD_LENGTH = 64;

class Secret
{
	char taskDescription[MAX_DESCRIPTION_LENGTH + 1];
	char password[MAX_PASSWORD_LENGTH + 1];
	mutable size_t _failedLogins = 0;
public:
	Secret() = delete;
	Secret(const char* taskDescription, const char* password);

	const char* getTask(const char* pwd) const;
	size_t getLoginFails() const;

	void setPassword(const char* newPassword, const char* oldPassword);
	void setTask(const char* newTask, const char* passwd);
};
