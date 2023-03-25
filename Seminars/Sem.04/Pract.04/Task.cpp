#include <cstring>
#include "Task.h"

const char* Task::GetName() const {
	return name;
}

const char* Task::GetDescription() const {
	return description;
}

unsigned Task::GetPoints() const {
	return points;
}

Task::Task() {
	SetName("Unknown");
	SetDescription("Unknown");
	SetPoints(1);
}

Task::Task(const char* name, const char* description, unsigned points) {
	SetName(name);
	SetDescription(description);
	SetPoints(points);
}

void Task::SetName(const char* newName) {
	if (!IsNameValid(newName)) {
		//error message
		return;
	}
	strcpy_s(name, newName);
}

void Task::SetDescription(const char* newDescription) {
	if (!IsDescriptionValid(newDescription)) {
		//error message
		return;
	}
	strcpy_s(description, newDescription);
}

void Task::SetPoints(unsigned newPoints) {
	if (!ArePointsValid(newPoints)) {
		//error message
		return;
	}
	points = newPoints;
}

bool Task::ArePointsValid(unsigned points) const {
	return points > 0 && points < 50;
}


bool Task::IsDescriptionValid(const char* description) const {
	unsigned descriptionLength = strlen(description);
	if (descriptionLength < 3 || descriptionLength > MAX_TASK_NAME_LENGTH)
		return false;
	return true;
}

bool Task::IsNameValid(const char* name) const {
	unsigned nameLength = strlen(name);
	if (nameLength < 3 || nameLength > MAX_TASK_NAME_LENGTH)
		return false;
	return true;
}