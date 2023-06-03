#pragma once
class Teacher
{
private:
	char* name = nullptr;

public:
	Teacher() = default;
	Teacher(const char* name);
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);
	~Teacher();

	const char* GetName() const;

private:
	void CopyFrom(const Teacher& other);
	void Free();
};

