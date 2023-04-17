#pragma once
#include "Person.h"
#include <iostream>
#include <cstring>

Person::Person(const char* name, int age) {
	setName(name);
	setAge(age);
}

Person::Person(const Person& other) {
	CopyFrom(other);
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

Person::~Person() {
	Free();
}

const char* Person::getName() const {
	return name;
}

int Person::getAge() const {
	return age;
}

void Person::setName(const char* name) {
	if (name == nullptr || this->name == name) {
		return;
    	}
	
	delete[] this->name;
	size_t nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	strcpy(this->name, name);
}

void Person::setAge(int age) {
	this->age = age;
}

void Person::print() const {
	std::cout << name << " " << age << std::endl;
}

void Person::CopyFrom(const Person& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
}

void Person::Free() {
	delete[] name;
}
