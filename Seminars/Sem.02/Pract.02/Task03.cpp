#include <iostream>
#include <fstream>

const char* PROPERTIES_FILE_NAME = "properties.txt";
const char* TEMPLATE_FILE_NAME = "template.txt";
const char* RESULT_FILE_NAME = "result.txt";
const int PROPERTY_NAME_MAX_LENGTH = 31;
const int PROPERTY_VALUE_MAX_LENGTH = 100;

void writePropertyInFile(std::ofstream& result, const char* propValue)
{
	while (propValue[0] != '\0')
	{
		result << propValue[0];
		propValue++;
	}
}

// returns how many symbols were read
int setProperyName(std::ifstream& templateFile, char* propName)
{
	int templateFilePrevPos = templateFile.tellg();

	char curr;
	templateFile >> curr;
	int indexesRead = 1;
	while (curr != '}')
	{
		propName[0] = curr;
		propName++;
		templateFile >> curr;
		indexesRead++;
	}
	propName[0] = '\0';

	templateFile.seekg(templateFilePrevPos);
	return indexesRead;
}

int getIndexOfPropertyValueInFile(std::ifstream& propFile, const char* propName)
{
	int propFilePrevPos = propFile.tellg();
	propFile.seekg(0, std::ios::beg);

	int result = 0;
	int propNameIndex = 0;
	char currCh;

	while (propName[propNameIndex] != '\0')
	{
		propFile >> currCh;
		if (currCh == propName[propNameIndex])
		{
			propNameIndex++;
		}
		else
		{
			propNameIndex = 0;
		}
	}

	propFile.seekg(1, std::ios::cur);
	result = propFile.tellg();

	propFile.seekg(propFilePrevPos);
	return result;
}

void setPropertyValue(std::ifstream& propFile, const char* propName, char* propValue)
{
	int propFilePrevPos = propFile.tellg();

	int indexOfPropertyValueInFile = getIndexOfPropertyValueInFile(propFile, propName);
	propFile.seekg(indexOfPropertyValueInFile);

	propFile.getline(propValue, PROPERTY_VALUE_MAX_LENGTH);

	propFile.seekg(propFilePrevPos);
}

void fulfillTemplate(std::ifstream& propFile, std::ifstream& templateFile, std::ofstream& result)
{
	if (propFile.is_open() && templateFile.is_open() && result.is_open())
	{
		int propFilePrevPos = propFile.tellg();
		int templateFilePrevPos = propFile.tellg();

		char currTemplateCh;

		while (!templateFile.eof())
		{
			templateFile >> currTemplateCh;

			if (currTemplateCh == '{')
			{
				char* propertyName = new char[PROPERTY_NAME_MAX_LENGTH];
				char* propertyValue = new char[PROPERTY_VALUE_MAX_LENGTH];

				int indexesRead = setProperyName(templateFile, propertyName);
				templateFile.seekg(indexesRead, std::ios::cur);
				setPropertyValue(propFile, propertyName, propertyValue);
				writePropertyInFile(result, propertyValue);

				delete[] propertyName;
				delete[] propertyValue;
			}
			else
			{
				result << currTemplateCh;
			}
		}

		propFile.seekg(propFilePrevPos);
		templateFile.seekg(templateFilePrevPos);
	}
}

int main()
{
	std::ifstream propFile(PROPERTIES_FILE_NAME);
	std::ifstream templateFile(TEMPLATE_FILE_NAME);
	std::ofstream myFile(RESULT_FILE_NAME);

	fulfillTemplate(propFile, templateFile, myFile);

	propFile.close();
	templateFile.close();
	myFile.close();
}
