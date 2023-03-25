#pragma once

const int MAX_TASK_NAME_LENGTH = 25;
const int MAX_DESCRIPTION_LENGTH = 255;

class Task {
	char name[MAX_TASK_NAME_LENGTH + 1];
	char description[MAX_DESCRIPTION_LENGTH + 1];
	unsigned points;
	bool IsNameValid(const char* name) const;
	bool IsDescriptionValid(const char* description) const;
	bool ArePointsValid(const unsigned points) const;
public:
	Task();
	Task(const char* name, const char* description, unsigned points);
	const char* GetName() const;
	const char* GetDescription() const;
	unsigned GetPoints() const;
	void SetName(const char* newName);
	void SetDescription(const char* newDescription);
	void SetPoints(unsigned points);
};
