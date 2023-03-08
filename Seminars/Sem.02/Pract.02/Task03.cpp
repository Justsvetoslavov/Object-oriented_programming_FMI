#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 128;

// The path to the file with the values to replace
char ifpath[MAX_SIZE]      = "C:\\Users\\boris\\OneDrive\\Desktop\\data.txt";
// The path to the blank of the report
char ofpath[MAX_SIZE]      = "C:\\Users\\boris\\OneDrive\\Desktop\\report.txt";
// The path to the report
char patternpath[MAX_SIZE] = "C:\\Users\\boris\\OneDrive\\Desktop\\pattern.txt";

char patterns[MAX_SIZE][MAX_SIZE];
char elements[MAX_SIZE][MAX_SIZE];

int length(string str)
{
	int i = 0;
	while (str[i++] != '\0');
	return i - 1;
}

void strCopy(string& str, char chr[MAX_SIZE], int len)
{
	for (int i = 0; i < len; ++i)
	{
		chr[i] = str[i];
	}
}

bool strComp(string line, char pattern[MAX_SIZE])
{
	int i = 0;
	while (pattern[i] != '\0')
		if (line[i] != pattern[i++])
			return false;

	return true;
}

void readData()
{
	ifstream streamReader(ifpath);
	int i = 0;

	if (streamReader.is_open())
	{
		while (streamReader.good() && !streamReader.eof())
		{
			char str[MAX_SIZE];
			streamReader.getline(str, MAX_SIZE);
			string temp, concat;
			stringstream strStream(str);

			getline(strStream, temp, ' ');
			strCopy(temp, patterns[i], length(temp));

			while (getline(strStream, temp, ' '))
			{
				concat += temp + ' ';
			}
			strCopy(concat, elements[i++], length(concat));
			elements[i - 1][length(elements[i - 1]) - 1] = '\0';
		}
	}

	streamReader.close();
}

void createReport(void)
{
	ifstream streamReader(patternpath);
	ofstream streamWriter(ofpath, ofstream::app);

	if (streamReader.is_open())
	{
		while (streamReader.good() && !streamReader.eof())
		{
			char str[MAX_SIZE];
			streamReader.getline(str, MAX_SIZE);
			string temp;
			stringstream strStream(str);

			while (getline(strStream, temp, '{'))
			{
				string temp2;
				stringstream strStream2(temp);

				while (getline(strStream2, temp2, '}'))
				{
					bool isPattern = false;
					for (int i = 0; i < 4; ++i)
					{
						if (strComp(temp2, patterns[i]))
						{
							streamWriter << elements[i];
							isPattern = true;
							break;
						}
					}

					if (!isPattern) streamWriter << temp2;
				}
			}

			streamWriter << '\n';
		}
	}

	streamReader.close();
	streamWriter.close();
}

int main()
{
	readData();
	createReport();

	return 0;
}