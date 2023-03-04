#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const int OPTIMAL_SUBJECT_NAME_MAX_LENGTH = 31;
const int NUMBER_MAX_LENGTH = 11;
const int CATEGORY_NAME_MAX_LENGTH = 21;
const int EXAM_TYPE_NAME_MAX_LENGTH = 21;

const char* CATEGORY_ENUM_TO_STRING[] = {
	"OKN",
	"M",
	"PM",
	"PR",
	"Other"
};
const char* EXAM_TYPES_ENUM_TO_STRING[] = {
	"Exam",
	"CourseProject",
	"Test"
};

enum class Category
{
	OKN,
	M,
	PM,
	PR,
	Other
};

enum class ExamType
{
	Exam,
	CourseProject,
	Test
};

struct OptimalSubject
{
	char name[OPTIMAL_SUBJECT_NAME_MAX_LENGTH];
	int ID;
	int credits;
	int examTypesCount = 0;
	Category category;
	ExamType* examTypes;
};

void convertStringToInt(const char* str, int& num, const int numLength)
{
	int helpingNum = 1;
	for (int i = numLength - 1; i >= 0; i--)
	{
		num += ((int)str[i]) * helpingNum;
		helpingNum *= 10;
	}
}

bool compareStrings(const char* firstString, const char* secondString)
{
	while (firstString[0] != '\0')
	{
		if (secondString[0] != firstString[0])
		{
			return false;
		}

		firstString++;
		secondString++;
	}

	if (secondString[0] != '\0')
	{
		return false;
	}

	return true;
}

void getNameOutOfLine(const char* line, char* name)
{
	// seek the ptr
	int position = 1;
	for (size_t i = 0; i < position; i++)
	{
		while (line[0] != ',')
		{
			line++;
		}
		line++;
	}

	int index = 0;

	while (line[0] != ',')
	{
		name[index++] = line[0];
		line++;
	}
	name[index] = '\0';
}

void getIdOutOfLine(const char* line, int& ID)
{
	char num[NUMBER_MAX_LENGTH];
	int index = 0; // num length

	while (line[0] != ',')
	{
		num[index++] = line[0];
		line++;
	}

	convertStringToInt(num, ID, index);
}

void getCreditsOutOfLine(const char* line, int& credits)
{
	// seek the ptr
	int position = 2;
	for (size_t i = 0; i < position; i++)
	{
		while (line[0] != ',')
		{
			line++;
		}
		line++;
	}

	char num[NUMBER_MAX_LENGTH];
	int index = 0; // num length

	while (line[0] != ',')
	{
		num[index++] = line[0];
		line++;
	}

	convertStringToInt(num, credits, index);
}

void getCategoryOutOfLine(const char* line, Category& category)
{
	// seek the ptr
	int position = 3;
	for (size_t i = 0; i < position; i++)
	{
		while (line[0] != ',')
		{
			line++;
		}
		line++;
	}

	int index = 0;
	char categoryName[CATEGORY_NAME_MAX_LENGTH];
	while (line[0] != ',')
	{
		categoryName[index++] = line[0];
		line++;
	}
	categoryName[index] = '\0';

	if (compareStrings(CATEGORY_ENUM_TO_STRING[0], categoryName))
	{
		category = Category::OKN;
	}
	else if (compareStrings(CATEGORY_ENUM_TO_STRING[1], categoryName))
	{
		category = Category::M;
	}
	else if (compareStrings(CATEGORY_ENUM_TO_STRING[2], categoryName))
	{
		category = Category::PM;
	}
	else if (compareStrings(CATEGORY_ENUM_TO_STRING[3], categoryName))
	{
		category = Category::PR;
	}
	else
	{
		category = Category::Other;
	}
}

void getExamTypesCountOutOfLine(const char* line, int& examTypesCount)
{
	// seek the ptr
	while (line[0] != '\"')
	{
		line++;
	}
	line++;

	// checks if it is empty string
	if (line[0] != '\"')
	{
		while (line[0] != '\"')
		{
			if (line[0] == ',')
			{
				examTypesCount++;
			}
			line++;
		}
	}
}

void getExamTypesOutOfLine(const char* line, ExamType* examTypes, const int examTypesCount)
{
	// seek the ptr
	while (line[0] != '\"')
	{
		line++;
	}
	line++;

	for (size_t i = 0; i < examTypesCount; i++)
	{
		int index = 0;
		char examTypeName[EXAM_TYPE_NAME_MAX_LENGTH];
		while (line[0] != ',')
		{
			examTypeName[index++] = line[0];
			line++;
		}
		line++;
		examTypeName[index] = '\0';

		if (compareStrings(EXAM_TYPES_ENUM_TO_STRING[0], examTypeName))
		{
			examTypes[i] = ExamType::Exam;
		}
		else if (compareStrings(EXAM_TYPES_ENUM_TO_STRING[1], examTypeName))
		{
			examTypes[i] = ExamType::CourseProject;
		}
		else if (compareStrings(EXAM_TYPES_ENUM_TO_STRING[2], examTypeName))
		{
			examTypes[i] = ExamType::Test;
		}
	}
}

void getSubjectOutOfLine(const char* line, OptimalSubject& subject)
{
	getNameOutOfLine(line, subject.name);
	getIdOutOfLine(line, subject.ID);
	getCreditsOutOfLine(line, subject.credits);
	getCategoryOutOfLine(line, subject.category);

	getExamTypesCountOutOfLine(line, subject.examTypesCount);

	subject.examTypes = new ExamType[subject.examTypesCount];
	getExamTypesOutOfLine(line, subject.examTypes, subject.examTypesCount);
}

void saveOptimalSubject(std::ofstream& file, const OptimalSubject& subject)
{
	file << subject.ID << ',' << subject.name << ',' << subject.credits << ',';
	switch (subject.category)
	{
	case Category::M: file << CATEGORY_ENUM_TO_STRING[0] << ','; break;
	case Category::OKN: file << CATEGORY_ENUM_TO_STRING[1] << ','; break;
	case Category::PM: file << CATEGORY_ENUM_TO_STRING[2] << ','; break;
	case Category::PR: file << CATEGORY_ENUM_TO_STRING[3] << ','; break;
	case Category::Other: file << CATEGORY_ENUM_TO_STRING[4] << ','; break;
	}

	file << '\"';
	for (size_t i = 0; i < subject.examTypesCount; i++)
	{
		switch (subject.examTypes[i])
		{
		case ExamType::Exam: file << EXAM_TYPES_ENUM_TO_STRING[0]; break;
		case ExamType::CourseProject: file << EXAM_TYPES_ENUM_TO_STRING[1]; break;
		case ExamType::Test: file << EXAM_TYPES_ENUM_TO_STRING[2]; break;
		}
		if (i != subject.examTypesCount - 1)
		{
			file << ", ";
		}
	}
	file << '\"' << std::endl;
}

void printOptimalSubject(const OptimalSubject& subject)
{
	std::cout << subject.ID << ',' << subject.name << ',' << subject.credits << ',';
	switch (subject.category)
	{
	case Category::M: std::cout << CATEGORY_ENUM_TO_STRING[0] << ','; break;
	case Category::OKN: std::cout << CATEGORY_ENUM_TO_STRING[1] << ','; break;
	case Category::PM: std::cout << CATEGORY_ENUM_TO_STRING[2] << ','; break;
	case Category::PR: std::cout << CATEGORY_ENUM_TO_STRING[3] << ','; break;
	case Category::Other: std::cout << CATEGORY_ENUM_TO_STRING[4] << ','; break;
	}

	std::cout << '\"';
	for (size_t i = 0; i < subject.examTypesCount; i++)
	{
		switch (subject.examTypes[i])
		{
		case ExamType::Exam: std::cout << EXAM_TYPES_ENUM_TO_STRING[0]; break;
		case ExamType::CourseProject: std::cout << EXAM_TYPES_ENUM_TO_STRING[1]; break;
		case ExamType::Test: std::cout << EXAM_TYPES_ENUM_TO_STRING[2]; break;
		}
		if (i != subject.examTypesCount - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << '\"';
}

void saveData(std::ofstream& file, const OptimalSubject* subjects, const int subjectsCount)
{
	file << "ID,Name,Credits,Category,Exam types" << std::endl;
	for (size_t i = 0; i < subjectsCount; i++)
	{
		OptimalSubject subject = subjects[i];
		saveOptimalSubject(file, subject);
	}
}

void loadData(std::ifstream& file, OptimalSubject* subjects, const int subjectsCount)
{
	int prevPos = file.tellg();
	file.seekg(0, std::ios::beg);

	// get rid of the first line 
	char buff[BUFF_SIZE];
	file.getline(buff, BUFF_SIZE, '\n');

	for (size_t i = 0; i < subjectsCount; i++)
	{
		OptimalSubject subject;
		file.getline(buff, BUFF_SIZE, '\n');
		getSubjectOutOfLine(buff, subject);
	}

	file.seekg(prevPos);
}

int findSubjectByID(std::ifstream& file, OptimalSubject& subject, const int ID, const int subjectsCount, const bool subjectNeedsChange)
{
	int prevPos = file.tellg();
	file.seekg(0, std::ios::beg);

	// get rid of the first line 
	char buff[BUFF_SIZE];
	file.getline(buff, BUFF_SIZE, '\n');

	int currId;
	for (size_t i = 0; i < subjectsCount; i++)
	{
		file.getline(buff, BUFF_SIZE, '\n');
		getIdOutOfLine(buff, currId);

		if (currId == ID)
		{
			if (subjectNeedsChange)
			{
				getSubjectOutOfLine(buff, subject);
			}
			file.seekg(prevPos);
			return i;
		}
	}

	file.seekg(prevPos);
	return -1;
}

void addOptimalSubject(const char* fileName, OptimalSubject& subject, OptimalSubject* subjects, int& subjectsCount)
{
	std::ifstream fileToRead(fileName);

	if (fileToRead.is_open())
	{
		fileToRead.seekg(0, std::ios::beg);

		// get rid of the first line 
		char buff[BUFF_SIZE];
		fileToRead.getline(buff, BUFF_SIZE, '\n');

		int index = findSubjectByID(fileToRead, subject, subject.ID, subjectsCount, false);
		fileToRead.close();

		if (index == -1)
		{
			std::ofstream fileToWrite(fileName, std::ios::app);

			if (fileToWrite.is_open())
			{
				saveOptimalSubject(fileToWrite, subject);
				subjectsCount++;
			}

			fileToWrite.close();
		}
		else
		{
			std::ofstream fileToWrite(fileName, std::ios::trunc);

			if (fileToWrite.is_open())
			{
				subjects[index] = subject;
				saveData(fileToWrite, subjects, subjectsCount);
			}

			fileToWrite.close();
		}
	}
}

void removeOptimalSubjectById(const char* fileName, const int ID, OptimalSubject* subjects, int& subjectsCount)
{
	std::ifstream fileToRead(fileName);
	if (fileToRead.is_open())
	{
		// get rid of the first line 
		char buff[BUFF_SIZE];
		fileToRead.getline(buff, BUFF_SIZE, '\n');

		OptimalSubject subject;
		int index = findSubjectByID(fileToRead, subject, subject.ID, subjectsCount, true);
		fileToRead.close();

		if (index != -1)
		{
			std::ofstream fileToWrite(fileName, std::ios::trunc);

			if (fileToWrite.is_open())
			{
				for (size_t i = index; i < subjectsCount - 1; i++)
				{
					subjects[i] = subjects[i + 1];
				}

				subjectsCount--;
				saveData(fileToWrite, subjects, subjectsCount);
			}

			fileToWrite.close();
		}
	}
}

void printOptimalSubjectsWithExactCategory(std::ifstream& file, const OptimalSubject* subjects,
	const Category& category, const int subjectsCount)
{
	int prevPos = file.tellg();
	file.seekg(0, std::ios::beg);

	// get rid of the first line 
	char buff[BUFF_SIZE];
	file.getline(buff, BUFF_SIZE, '\n');

	std::cout << "ID,Name,Credits,Category,Exam types" << std::endl;
	for (size_t i = 0; i < subjectsCount; i++)
	{
		OptimalSubject subject = subjects[i];

		if (subject.category == category)
		{
			printOptimalSubject(subject);
		}
	}

	file.seekg(prevPos);
	// print these with the same category
}

void printOptimalSubjectsWithCreditsInInterval(std::ifstream& file, const OptimalSubject* subjects,
	const int minCredits, const int maxCredits, const int subjectsCount)
{
	int prevPos = file.tellg();
	file.seekg(0, std::ios::beg);

	// get rid of the first line 
	char buff[BUFF_SIZE];
	file.getline(buff, BUFF_SIZE, '\n');

	std::cout << "ID,Name,Credits,Category,Exam types" << std::endl;
	for (size_t i = 0; i < subjectsCount; i++)
	{
		OptimalSubject subject = subjects[i];

		if (subject.credits >= minCredits && subject.credits <= maxCredits)
		{
			printOptimalSubject(subject);
		}
	}

	file.seekg(prevPos);
}