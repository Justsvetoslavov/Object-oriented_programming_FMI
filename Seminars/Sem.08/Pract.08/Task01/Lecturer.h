#pragma once

class Lecturer {
private:
	char* _name;

	void copyFrom(const Lecturer& other);
	void free();
public:
	Lecturer(const char* name);
	Lecturer(const Lecturer& other);
	Lecturer& operator=(const Lecturer& other);
	~Lecturer();

	const char* getName() const;
	void setName(const char* name);
};