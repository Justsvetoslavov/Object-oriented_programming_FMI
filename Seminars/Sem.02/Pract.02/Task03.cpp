#include <iostream>
#include <fstream>

const int NUMBER_OF_PLACEHOLDERS = 4;
const int BUFF_SIZE = 300;
char** placeholderNames = new char* [NUMBER_OF_PLACEHOLDERS];

struct Placeholder {
	char title[100];
	char recipientName[100];
	char message[750];
	char senderName[100];
};

void myStrcpy(char* dest, const char* src) {
	int ind = 0;
	while (*src) {
		dest[ind++] = *(src++);
	}
	dest[ind] = '\0';
}

int myStrlen(const char* str) {
	int ctr = 0;
	while (*str) {
		ctr++;
		str++;
	}
	return ctr;
}

void initPlaceholderNames() {
	for (int i = 0; i < NUMBER_OF_PLACEHOLDERS; i++) {
		placeholderNames[i] = new char[30];
	}
	myStrcpy(placeholderNames[0], "{title}");
	myStrcpy(placeholderNames[1], "{recipient_name}");
	myStrcpy(placeholderNames[2], "{message}");
	myStrcpy(placeholderNames[3], "{sender_name}");
}

bool placeholderFound(const char buff[], const int placeholderInd) {
	int placeholderIter = 0;
	int len = myStrlen(placeholderNames[placeholderInd]);

	while (*buff && placeholderIter < len) {
		if (*buff != placeholderNames[placeholderInd][placeholderIter++]) {
			return false;
		}
		buff++;
	}

	return placeholderIter == len;
}

int getPlaceholderInd(const char buff[]) {
	for (int i = 0; i < NUMBER_OF_PLACEHOLDERS; i++) {
		if (placeholderFound(buff, i)) {
			return i;
		}
	}
	return -1;
}

void changeText(const char buff[], char changedText[], const Placeholder& placeholder) {
	int  buffIter = 0, changedTextIter = 0;

	while (*buff) {
		if (*buff != '{') {
			changedText[changedTextIter++] = *buff;
			buff++;
		}

		//Check if the text after the opening bracket is a placeholder
		else {
			int ind = getPlaceholderInd(buff);

			//Not a placeholder
			if (ind < 0) {
				changedText[changedTextIter++] = *buff;
				buff++;
			}

			else {
				switch (ind) {
				case 0:
					myStrcpy(changedText + changedTextIter, placeholder.title);
					changedTextIter += myStrlen(placeholder.title);
					break;
				case 1:
					myStrcpy(changedText + changedTextIter, placeholder.recipientName);
					changedTextIter += myStrlen(placeholder.recipientName);
					break;
				case 2: 
					myStrcpy(changedText + changedTextIter, placeholder.message);
					changedTextIter += myStrlen(placeholder.message);
					break;
				case 3:
					myStrcpy(changedText + changedTextIter, placeholder.senderName);
					changedTextIter += myStrlen(placeholder.senderName);
					break;
				}
				buff += myStrlen(placeholderNames[ind]);
			}
		}
	}
	changedText[changedTextIter] = '\0';
}

void copyAndReplace(const char destName[], const char srcName[], const Placeholder& placeholder) {
	std::ofstream writeFile(destName);
	std::ifstream readFile(srcName);

	if (!writeFile.is_open()) {
		std::cout << "Error\n";
		return;
	}

	if (!readFile.is_open()) {
		std::cout << "Error\n";
		return;
	}

	int ctr = 0;
	while (!readFile.eof()) {
		ctr++;
		char buff[BUFF_SIZE];
		readFile.getline(buff, BUFF_SIZE);

		char changedText[BUFF_SIZE];
		changeText(buff, changedText, placeholder);

		writeFile << changedText;
		writeFile << '\n';
	}

	writeFile.close();
	readFile.close();
}

void printFile(const char fileName[]) {
	std::ifstream readFile(fileName);

	if (!readFile.is_open()) {
		std::cout << "Error\n";
		return;
	}

	while (!readFile.eof()) {
		char buff[BUFF_SIZE];
		readFile.getline(buff, BUFF_SIZE);
		std::cout << buff << "\n";
	}
	std::cout << "\n\n";

	readFile.close();
}

int main()
{
	initPlaceholderNames();
	Placeholder placeholder{ "Veliki", "Pop Armeniya", "Iskam da se oplacha!!!", "FMI-student" };
	copyAndReplace("newfile.txt", "file.txt", placeholder);

	printFile("file.txt");
	printFile("newfile.txt");
}

