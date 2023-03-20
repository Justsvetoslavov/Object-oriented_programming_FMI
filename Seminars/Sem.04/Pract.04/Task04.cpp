#include <iostream>
#include <fstream>

const int MAX_LENGTH = 50;

class SecretExam {
private:
	char taskCondition[MAX_LENGTH];
	char password[MAX_LENGTH];
	int FailedLogins;
public:
	SecretExam() :taskCondition{}, password{}, FailedLogins{} {}

	SecretExam(const char* taskCondition, const char* password, int FailedLogins = 0) {
		setTaskCondition(taskCondition);
		setPassword(password);
	}
	const char* getTaskCondition()const {
		return taskCondition;

	}
	const char* getPswrd()const {
		return password;
	}
	int  getFailedLogins()const {
		return FailedLogins;
	}

	void setTaskCondition(const char taskCondition[]) {
		int index = 0;
		while (taskCondition[index] != '\0') {
			this->taskCondition[index] = taskCondition[index];
			index++;
		}
		this->taskCondition[index] = '\0';
	}
	void setPassword(const char* password) {
		int index = 0;
		while (password[index] != '\0') {
			this->password[index] = password[index];
			index++;
		}
		this->password[index] = '\0';
	}

	void setFailedLogins(int FailedLogins) {
		if (FailedLogins >= 0) {
			this->FailedLogins = FailedLogins;
		}

	}

	const char* getTask(const char* password) {
		if (strcmp(this->password, password) == 0) {
			return getTaskCondition();
		}
		else {
			setFailedLogins(getFailedLogins() + 1);
			return 	"Wrong password!";
		}
	}
	void changePassword(const char* newPassword, const char* oldPassword) {

		if (strcmp(this->password, oldPassword) == 0) {
			setPassword(newPassword);
			std::cout << "Password changed successfully!" << std::endl;
		}
		else {
			FailedLogins++;
			std::cout << "Error ,the password cannot be changed!" << std::endl;
			return;

		}
	}
	void setTask(const char* newTask, const char* password) {

		if (strcmp(this->password, password) == 0) {
			setTaskCondition(newTask);
			std::cout << "Task condition changed successfully!" << std::endl;
		}
		else {
			FailedLogins++;
			std::cout << "Wrong password, task condition cannot be changed!" << std::endl;
			return;

		}
	}
};

int main() {
	SecretExam myExam("Complete the assignment", "myexam@123", 0);

	std::cout << "Login password: " << myExam.getPswrd() << std::endl;
	std::cout << "Task: " << myExam.getTaskCondition() << std::endl;
	
	// Testing getTask function with correct password
	const char* task = myExam.getTask("myexam@123");
	if (task != nullptr) {
		std::cout << "Get Task condition based on password login: " << task << std::endl;
	}

	// Testing getTask function with incorrect password
	task = myExam.getTask("incorrect_password");
	if (task == nullptr) {
		std::cout << "Failed login attempt. Number of failed logins: " << myExam.getFailedLogins() << std::endl;
	}

	// Testing setPassword function with correct old password
	myExam.changePassword("new_password", "myexam@123");
	std::cout << "New password: " << myExam.getPswrd() << std::endl;

	// Testing setPassword function with incorrect old password
	myExam.changePassword("new_password", "incorrect_password");

	// Testing setTask function with correct password
	myExam.setTask("New task condition", "new_password");
	std::cout << "New task condition: " << myExam.getTaskCondition() << std::endl;

	// Testing setTask function with incorrect password
	myExam.setTask("New task condition", "incorrect_password");

	return 0;
}
