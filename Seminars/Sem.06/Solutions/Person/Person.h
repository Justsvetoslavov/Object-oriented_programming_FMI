#pragma once
#include <iostream>

class Person {
private:
	char* name = nullptr;
	int age = 0;
public:
	Person() = default;
	Person(const char* name, int age);
	Person(const Person& other);
	Person& operator=(const Person& other);
  	~Person();

	const char* getName() const;
	int getAge() const;

	void setName(const char* name);
	void setAge(int age);

	void print() const;
private:
  void CopyFrom(const Person& other);
	void Free();
};
