#include "Interface.h"
#include <iostream>
#include <cstring>
#include <fstream>

int toSeparator(const char* command)
{
	int counter = 0;
	while (*command != ',' && *command != ' ' && *command != '\n' && *command != '\0')
	{
		counter++;
		command++;
	}

	return counter;
}

bool printStudent(const Student* _studentCollection, size_t _studentCount, const int _fn)
{
	for (size_t i = 0; i < _studentCount; i++)
	{
		if (_studentCollection[i].fn == _fn)
		{
			std::cout << _studentCollection[i].first_name << ","
				<< _studentCollection[i].last_name << ","
				<< _studentCollection[i].email << ","
				<< _studentCollection[i].fn << std::endl;
			return true; //success!
		}
	}
	return false; //no such student!
}

bool editFirstName(Student* _studentCollection, size_t _studentCount, const int _fn, const char* _newFirstName)
{
	for (size_t i = 0; i < _studentCount; i++)
	{
		if (_studentCollection[i].fn == _fn)
		{
			strcpy(_studentCollection[i].first_name, _newFirstName);
			return true; //success!
		}
	}
	return false; //no such student!
}

bool saveStudentsToFile(const Student* _studentCollection, size_t _studentCount, const char* fileName)
{
	std::ofstream outFile(fileName);

	if (!outFile.is_open())
		return false;

	outFile << "First name, Last name, email, fn" << std::endl; //include header line

	for (size_t i = 0; i < _studentCount; i++)
		outFile << _studentCollection[i].first_name << ","
		<< _studentCollection[i].last_name << ","
		<< _studentCollection[i].email << ","
		<< _studentCollection[i].fn << std::endl;

	outFile.close();
	return true;
}

void interface(Student* _studentCollection, const int _studentCount)
{
	char commandLine[BUFFER_LINE_SIZE];
	do
	{
		std::cout << ">";
		std::cin.getline(commandLine, BUFFER_LINE_SIZE);
		size_t len = strlen(commandLine);

		//first argument (edit, save ...)
		size_t firstArgSize = toSeparator(commandLine);
		char* commandFirstArg = new char[firstArgSize + 1];

		for (int i = 0; i < firstArgSize; i++)
			commandFirstArg[i] = commandLine[i];
		commandFirstArg[firstArgSize] = '\0';

		if (len == firstArgSize) //no more arguments - quit? Check is below
			continue;

		//second argument (students.csv, 45543 ...)
		size_t secondArgSize = len - firstArgSize - 1;
		char* commandSecondArg = new char[secondArgSize + 1];

		for (int i = 0; i < secondArgSize; i++)
			commandSecondArg[i] = commandLine[firstArgSize + 1 + i];
		commandSecondArg[secondArgSize] = '\0';

		if (strcmp(commandFirstArg, "print") == 0)
		{
			int fn = atoi(commandSecondArg);

			bool res = printStudent(_studentCollection, _studentCount, fn);

			if (!res)
				std::cout << "Student with fn: " << fn << " doesn't exist!" << std::endl;;
		}
		else if (strcmp(commandFirstArg, "edit") == 0)
		{
			int fn = atoi(commandSecondArg);

			//we have a third argument here. It's in the second arguments string
			size_t seprator = toSeparator(commandSecondArg);

			size_t thirdArgumentSize = secondArgSize - seprator;
			char* commandThirdArg = new char[thirdArgumentSize + 1];

			for (size_t i = 0; i < thirdArgumentSize; i++)
				commandThirdArg[i] = commandSecondArg[seprator + 1 + i];
			commandThirdArg[thirdArgumentSize] = '\0';

			bool result = editFirstName(_studentCollection, _studentCount, fn, commandThirdArg);

			if (result)
				std::cout << "Succesfully changed name!" << std::endl;
			else
				std::cout << "Student with fn: " << fn << "doesn't exist!" << std::endl;

			//Free Memory
			delete[] commandThirdArg;
		}
		else if (strcmp(commandFirstArg, "save") == 0)
		{
			bool res = saveStudentsToFile(_studentCollection, _studentCount, commandSecondArg);

			if (res)
				std::cout << "Successfully saved to file: " << commandSecondArg << std::endl;
			else
				std::cout << "Error while saving in file: " << commandSecondArg << std::endl;
		}

		//Free memory
		delete[] commandFirstArg;
		delete[] commandSecondArg;

	} while(strcmp(commandLine, "quit"));
}