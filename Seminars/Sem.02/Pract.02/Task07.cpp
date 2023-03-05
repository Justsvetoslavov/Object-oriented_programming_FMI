#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_SIZE = 128,
		  MAX_DISCIPLINES = 100;
char path[MAX_SIZE] = "C:\\Users\\boris\\OneDrive\\Desktop\\account.txt";

enum Category { OKN, M, PM, PR, Other };

struct Subject
{
	short ID;
	char name[MAX_SIZE]{0};
	float credits;
	short category;
	// typeOfExam - Exam, CourseProject, Test
	bool typeOfExam[3];
};

void strCopy(char arr[MAX_SIZE], string& str)
{
	int i = 0;
	while (str[i] != '\0')
		arr[i] = str[i++];
}

void strCopy(char arr1[MAX_SIZE], char arr2[MAX_SIZE])
{
	int i = 0;
	while (arr1[i] != '\0')
		arr1[i] = arr2[i++];
}

void saveDiscipline(Subject& sub, Subject subs[MAX_DISCIPLINES])
{
	int end = 0;

	for (int i = 0; i < MAX_DISCIPLINES; ++i)
	{
		if (subs[i].ID == sub.ID || subs[i].ID == 0)
		{
			subs[i].ID = sub.ID;
			strCopy(subs[i].name, sub.name);
			subs[i].credits = sub.credits;
			subs[i].category = sub.category;
			subs[i].typeOfExam[0] = sub.typeOfExam[0];
			subs[i].typeOfExam[1] = sub.typeOfExam[1];
			subs[i].typeOfExam[2] = sub.typeOfExam[2];

			return;
		}
	}
}

void deleteDiscipline(short ID, Subject subs[MAX_DISCIPLINES])
{
	for (int i = 0; i < MAX_DISCIPLINES; ++i)
	{
		if (subs[i].ID == ID)
		{
			subs[i].ID = 0;

			return;
		}
	}
}

void findID(short ID, Subject subs[MAX_DISCIPLINES])
{
	for (int i = 0; i < MAX_DISCIPLINES; ++i)
	{
		if (subs[i].ID == ID)
		{
			cout << subs[i].ID << ','
				 << subs[i].name << ','
				 << subs[i].credits << ','
				 << subs[i].category << ','
				 << subs[i].typeOfExam[0] << ','
				 << subs[i].typeOfExam[1] << ','
				 << subs[i].typeOfExam[2] << '\n';

			return;
		}
	}
}

void findByCategory(short category, Subject subs[MAX_DISCIPLINES])
{
	for (int i = 0; i < MAX_DISCIPLINES; ++i)
	{
		if (subs[i].category == category)
		{
			cout << subs[i].ID << ','
				 << subs[i].name << ','
				 << subs[i].credits << ','
				 << subs[i].category << ','
				 << subs[i].typeOfExam[0] << ','
				 << subs[i].typeOfExam[1] << ','
				 << subs[i].typeOfExam[2] << '\n';
		}
	}
}

void findByCredits(float minC, float maxC, Subject subs[MAX_DISCIPLINES])
{
	for (int i = 0; i < MAX_DISCIPLINES; ++i)
	{
		if (subs[i].credits >= minC && subs[i].credits <= maxC)
		{
			cout << subs[i].ID << ','
				<< subs[i].name << ','
				<< subs[i].credits << ','
				<< subs[i].category << ','
				<< subs[i].typeOfExam[0] << ','
				<< subs[i].typeOfExam[1] << ','
				<< subs[i].typeOfExam[2] << '\n';
		}
	}
}

void saveAllDisciplines(char path[MAX_SIZE], Subject subs[MAX_DISCIPLINES])
{
	ofstream streamWriter(path, ofstream::app);
	for (int i = 0; i < MAX_DISCIPLINES; ++i)
	{
		if (subs[i].ID != 0)
		streamWriter << subs[i].ID << ','
					 << subs[i].name << ','
					 << subs[i].credits << ','
					 << subs[i].category << ','
					 << subs[i].typeOfExam[0] << ','
					 << subs[i].typeOfExam[1] << ','
					 << subs[i].typeOfExam[2] << '\n';
	}
	streamWriter.close();
}

// Даваше ми грешкки с template и за това има 2, почти идентични, функции
short shortFromString(string& str)
{
	short newData;
	stringstream strstream(str);
	strstream >> newData;

	return newData;
}

float floatFromString(string& str)
{
	float newData;
	stringstream strstream(str);
	strstream >> newData;

	return newData;
}

void readAllDisciplines(Subject subs[MAX_DISCIPLINES], char path[MAX_SIZE])
{
	ifstream streamReader(path);

	int i = 0;
	char data[MAX_SIZE + 25];
	while (!streamReader.eof())
	{
		streamReader.getline(data, MAX_SIZE + 25);

		stringstream str(data);
		string temp;

		getline(str, temp, ',');
		subs[i].ID = (int)shortFromString(temp);
		
		getline(str, temp, ',');
		strCopy(subs[i].name, temp);
		
		getline(str, temp, ',');
		subs[i].credits = floatFromString(temp);

		getline(str, temp, ',');
		subs[i].category = shortFromString(temp);

		getline(str, temp, ',');
		subs[i].typeOfExam[0] = shortFromString(temp);

		getline(str, temp, ',');
		subs[i].typeOfExam[1] = shortFromString(temp);

		getline(str, temp, ',');
		subs[i++].typeOfExam[2] = shortFromString(temp);
	}
}

int main()
{
	return 0;
}