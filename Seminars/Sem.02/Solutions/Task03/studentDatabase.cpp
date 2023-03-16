#include <iostream>
#include <fstream> 
#include "Interface.h"

int countLines(std::ifstream&);
void resetToStartOfFile(std::ifstream&);
bool checkFile(std::ifstream&, int&);
void readStudent(const char*, Student&);
void readStudents(std::ifstream&, Student*, size_t);

int main()
{
	std::cout << "Open file:" << std::endl;
	char fileName[BUFFER_LINE_SIZE];
	std::cin.getline(fileName, BUFFER_LINE_SIZE);

	std::ifstream myFile(fileName , std::ios::_Nocreate);
	int studentCount = 0;
	
	if (!checkFile(myFile, studentCount))
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	std::cout << "File successfully opened!" << std::endl;

	Student* studentCollection = new Student[studentCount];
	readStudents(myFile, studentCollection,studentCount); //read from file, write to studentCollection
	myFile.close();

	interface(studentCollection, studentCount); //commandLine interface

	delete[] studentCollection;
	return 0; //end program
}

void resetToStartOfFile(std::ifstream& _myFile)
{
	//reset to beginning of file
	_myFile.clear();
	_myFile.seekg(0, std::ios::beg);
}
int countLines(std::ifstream& _myFile)
{
	unsigned lines = 0;

	while (!_myFile.eof())
	{
		char buffer[BUFFER_LINE_SIZE];
		_myFile.getline(buffer, BUFFER_LINE_SIZE);
		lines++;
	}

	resetToStartOfFile(_myFile);
	return lines - 1;
}
bool checkFile(std::ifstream& _myFile, int& _studentCount)
{
	if (!_myFile.is_open())
		return false;

	_studentCount = countLines(_myFile) - 1;

	return _studentCount > 0;
}
void readStudent(const char* input, Student& student)
{
	size_t ind = 0;

	// first name
	while (input[ind] != ',')
	{
		student.first_name[ind] = input[ind];
		ind++;
	}
	student.first_name[ind] = '\0';
	ind++;

	//last name
	size_t lastNameInd = 0;
	while (input[ind] != ',')
		student.last_name[lastNameInd++] = input[ind++];
	student.last_name[lastNameInd] = '\0';
	ind++;

	//email
	size_t emailInd = 0;

	while (input[ind] != ',')
		student.email[emailInd++] = input[ind++];
	student.email[emailInd] = '\0';
	ind++;

	//fn
	while (input[ind] != '\0')
		(student.fn *= 10) += (input[ind++] - '0');
}
void readStudents(std::ifstream& _myFile, Student* _studentCollection,size_t _studentCount)
{
	int line = 1;
	while (!_myFile.eof())
	{
		char buff[BUFFER_LINE_SIZE];
		_myFile.getline(buff, BUFFER_LINE_SIZE);

		if (line == 1 || line - 2 == _studentCount)
		{
			line++;
			continue;
		}

		readStudent(buff, _studentCollection[line - 2]);
		line++;
	}

	resetToStartOfFile(_myFile);
}
