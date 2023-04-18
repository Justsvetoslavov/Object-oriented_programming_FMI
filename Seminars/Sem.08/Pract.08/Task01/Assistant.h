#pragma once

class Assistant {
private:
	char* _name;

	void copyFrom(const Assistant& other);
	void free();
public:
	Assistant();
	Assistant(const char* name);
	Assistant(const Assistant& other);
	Assistant& operator=(const Assistant& other);
	~Assistant();

	const char* getName() const;
	void setName(const char* name);
};