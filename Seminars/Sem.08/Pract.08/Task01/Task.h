#pragma once
class Task
{
private:
	char* name = nullptr;
	char* teacherName = nullptr;
	double grade = 0;
public:
	Task() = default;
	Task(const char* name, double grade, const char* teacherName);
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();

	double GetGrade() const;
	const char* GetTaskName() const;
	const char* GetTeacherName() const;
private:
	void CopyFrom(const Task& other);
	void Free();
};

