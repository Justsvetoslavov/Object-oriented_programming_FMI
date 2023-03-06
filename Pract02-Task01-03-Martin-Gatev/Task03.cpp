#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SYMBOLS_READ = 30;

int GetLengthOfWord(const char* word)
{
	if (word == nullptr)
	{
		return -1;
	}

	int size{};

	while (word[size] != '\0')
	{
		++size;
	}

	return size;
}

enum Headings //it's not enum class, cuz i use them as int below
{
	title = 5,
	recipient_name = 14,
	message = 7,
	sender_name = 11
};

void CreateNewFile(const char* templateName, const char* valueName, const char* copyName)
{
	const int MAX_BUFFER_SIZE = 50;

	std::ifstream ReadTemplate(templateName);

	std::ifstream ReadValues(valueName);

	std::ofstream WriteCopy(copyName);

	if (!ReadTemplate.is_open() || !ReadValues.is_open() || !WriteCopy.is_open())
	{
		return;
	}

	char curr, readBuffer[MAX_BUFFER_SIZE]{}, writeBuffer[MAX_BUFFER_SIZE];

	while (!ReadTemplate.eof())
	{
		ReadTemplate.get(curr);

		if (curr == '{')
		{
			ReadTemplate.getline(readBuffer, MAX_SYMBOLS_READ, '}');

			int size = GetLengthOfWord(readBuffer);

			switch (size)
			{
			case Headings::title:
				ReadValues.seekg(Headings::title + 1);
				ReadValues.getline(writeBuffer, MAX_BUFFER_SIZE, '\n');
				WriteCopy << writeBuffer;
				break;

			case Headings::recipient_name:
				ReadValues.seekg(Headings::recipient_name + 1, std::ios::cur);
				ReadValues.getline(writeBuffer, MAX_BUFFER_SIZE, '\n');
				WriteCopy << writeBuffer;
				break;

			case Headings::message:
				ReadValues.seekg(Headings::message + 1, std::ios::cur);
				ReadValues.getline(writeBuffer, MAX_BUFFER_SIZE, '\n');
				WriteCopy << writeBuffer;
				break;

			case Headings::sender_name:
				ReadValues.seekg(Headings::sender_name + 1, std::ios::cur);
				ReadValues.getline(writeBuffer, MAX_BUFFER_SIZE, '\n');
				WriteCopy << writeBuffer;
				break;

			default:
				break;
			}

			continue;
		}

		WriteCopy.put(curr);
	}

	ReadTemplate.close();
	ReadValues.close();
	WriteCopy.close();
}

int main()
{
	const char templateName[] = "template.txt" ;
	const char valuesName[] = "values.txt";
	const char copyName[] = "copy.txt";

	CreateNewFile(templateName, valuesName, copyName);

	return 0;
}