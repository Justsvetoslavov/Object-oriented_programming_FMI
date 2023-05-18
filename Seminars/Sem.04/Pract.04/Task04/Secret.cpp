#include "Secret.h"
#include <cstring>
#pragma warning(disable : 4996)

Secret::Secret(const char* taskDescription, const char* password) {
	strcpy(this->_taskDescription, taskDescription);
	strcpy(this->_password, password);
	failedLogins = 0;
}

const char* Secret::getTask(const char* pwd) const {
	if (strcmp(this->_password, pwd) == 0) {
		return this->_taskDescription;
	}

	this->failedLogins++;
	return "";
}

void Secret::setPassword(const char* newPassword, const char* oldPassword) {
	if (strcmp(this->_password, oldPassword) == 0) {
		strcpy(this->_password, newPassword);
	} else {
		this->failedLogins++;
	}
}

void Secret::setTask(const char* newTask, const char* passwd)
{
	if (strcmp(this->password, passwd) == 0) {
		strcpy(this->taskDescription, newTask);
	} else {
		this->failedLogins++;
	}
}

size_t Secret::getLoginFails() const {
	return this->failedLogins;
}