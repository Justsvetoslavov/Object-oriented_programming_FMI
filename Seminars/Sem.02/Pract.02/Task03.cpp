#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

size_t ReadValues(const char* valuesFileName, char** placeholders, char** values);
void PrintLines(char** lines, size_t linesCount);
void ReplaceTemplatePlaceholdersWithValues(char** templateLines, size_t templateLinesCount, char** placeholders, char** values, size_t valuesCount);
void CharArrayCopy(char* toCopy, size_t length, char* copyTo);
void ShiftCharArrayElementsAfterIndex(char* line, size_t lineCharCount, int shift, size_t index);
size_t CharArrayLength(char* arr);
size_t IndexOf(char** words, size_t wordsCount, char* word, size_t wordCharCount);
size_t ReadTemplate(const char* templateFileName, char** templateLines);

const int MAX_WORD_SIZE = 64;
const int MAX_NUMBER_OF_LINES = 256;
const int MAX_LINE_SIZE = 1024;

int main() {
	char* placeholders[MAX_NUMBER_OF_LINES];
	char* values[MAX_NUMBER_OF_LINES];
	char* templateLines[MAX_NUMBER_OF_LINES];
	const char valuesFileName[] = "values.txt";
	const char templateFileName[] = "template.txt";
	size_t valuesCount = ReadValues(valuesFileName, placeholders, values);
	size_t templateLinesCount = ReadTemplate(templateFileName, templateLines);
	ReplaceTemplatePlaceholdersWithValues(templateLines, templateLinesCount, placeholders, values, valuesCount);
	PrintLines(templateLines, templateLinesCount);
	for (size_t i = 0; i < valuesCount; i++)
	{
		delete[] values[i];
		delete[] placeholders[i];
	}
	for (size_t i = 0; i < templateLinesCount; i++)
	{
		delete[] templateLines[i];
	}
}

void PrintLines(char** lines, size_t linesCount) {
	for (size_t i = 0; i < linesCount; i++)
	{
		cout << lines[i] << endl;
	}
}

void ReplaceTemplatePlaceholdersWithValues(char** templateLines, size_t templateLinesCount, char** placeholders, char** values, size_t valuesCount) {
	for (size_t i = 0; i < templateLinesCount; i++)
	{
		size_t j = 0;
		while (templateLines[i][j] != '\0')
		{
			if (templateLines[i][j] == '{')
			{
				size_t startInd = j;
				j++;
				char placeholder[MAX_WORD_SIZE];
				size_t k = 0;
				while (templateLines[i][j] != '}')
				{
					placeholder[k++] = templateLines[i][j++];
				}
				size_t endInd = j;
				placeholder[k] = '\0';
				size_t placeholderCharCount = endInd - startInd - 1;
				size_t placeholderIndex = IndexOf(placeholders, valuesCount, placeholder, placeholderCharCount);
				size_t valueCharCount = CharArrayLength(values[placeholderIndex]);
				int shift = valueCharCount - (placeholderCharCount + 2); // +2 because of '{' and '}'
				size_t lineCharCount = CharArrayLength(templateLines[i]);
				size_t index = j + 1;
				ShiftCharArrayElementsAfterIndex(templateLines[i], lineCharCount, shift, index);
				k = 0;
				for (size_t ind = startInd; ind < startInd + valueCharCount; ind++)
				{
					templateLines[i][ind] = values[placeholderIndex][k++];
				}
			}
			j++;
		}
	}
}

void CharArrayCopy(char* toCopy, size_t length,char* copyTo) {
	size_t i;
	for (i = 0; i < length; i++)
	{
		copyTo[i] = toCopy[i];
	}
	copyTo[i] = '\0';
}

void ShiftCharArrayElementsAfterIndex(char* line, size_t lineCharCount, int shift, size_t index) {
	char lineCopy[MAX_LINE_SIZE];
	CharArrayCopy(line, lineCharCount, lineCopy);
	size_t i;
	for (i = index; i < lineCharCount; i++)
	{
		if (line[i] == '\0' || lineCopy[i + shift])
		{
			line[i + shift] = lineCopy[i];
		}
	}
	line[i + shift] = '\0';
}

size_t CharArrayLength(char* arr) {
	size_t length = 0;
	while (*arr++ != '\0') length++;
	return length;
}

size_t IndexOf(char** words, size_t wordsCount, char* word, size_t wordCharCount) {
	for (size_t i = 0; i < wordsCount; i++)
	{
		size_t j;
		for (j = 0; j < wordCharCount; j++)
		{
			if (words[i][j] == '\0') break;
			if (words[i][j] != word[j]) break;
		}
		if (j == wordCharCount) return i;
	}
	return -1;
}

size_t ReadValues(const char* valuesFileName, char** placeholders, char** values) {
	ifstream valuesFile(valuesFileName);
	if (!valuesFile.is_open())
	{
		cout << "Couldn't open " << valuesFileName << endl;
		return 0;
	}
	size_t i = 0;
	while (!valuesFile.eof())
	{
		char buffer[MAX_LINE_SIZE];
		valuesFile.getline(buffer, MAX_LINE_SIZE);
		placeholders[i] = new char[MAX_WORD_SIZE];
		values[i] = new char[MAX_WORD_SIZE];
		int j = 0, k = 0;
		while (buffer[j] != ' ')
		{
			placeholders[i][j++] = buffer[k++];
		}
		k++;
		placeholders[i][j] = '\0';
		j = 0;
		while (buffer[j] != '\0')
		{
			values[i][j++] = buffer[k++];
		}
		values[i][j] = '\0';
		i++;
	}
	return i;
}

size_t ReadTemplate(const char* templateFileName, char** templateLines) {
	ifstream templateFile(templateFileName);
	if (!templateFile.is_open())
	{
		cout << "Couldn't open " << templateFileName << endl;
		return 0;
	}
	size_t i = 0;
	while (!templateFile.eof())
	{
		templateLines[i] = new char[MAX_LINE_SIZE];
		templateFile.getline(templateLines[i++], MAX_LINE_SIZE);
	}
	return i;
}
