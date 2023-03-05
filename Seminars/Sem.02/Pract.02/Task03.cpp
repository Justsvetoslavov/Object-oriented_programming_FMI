#include <iostream>
#include <fstream>

const char READ_FILE_NAME[] = "read_file.txt";
const char WRITE_FILE_NAME[] = "write_file.txt";

const int BUFFER_SIZE = 256;
const int TITLE_ID = 6;
const int NAME_ID = 28;
const int MESSAGE_ID = 51;
const int SENDER_NAME_ID = 88;

void ReplacePlaceholders(const char* readFileName, const char* writeFileName) {
	std::ifstream readFile(readFileName);
	std::ofstream writeFile(writeFileName);

	if (!writeFile.is_open() || !readFile.is_open()) {
		std::cout << "Error";
		return;
	}
	char bufferTitle[BUFFER_SIZE];
	readFile.seekg(TITLE_ID, std::ios::beg);
	readFile.getline(bufferTitle, BUFFER_SIZE);

	char bufferName[BUFFER_SIZE];
	readFile.seekg(NAME_ID, std::ios::beg);
	readFile.getline(bufferName, BUFFER_SIZE);

	writeFile << "Dear, " << bufferTitle << bufferName << std::endl;
	writeFile << std::endl;

	char bufferMessage[BUFFER_SIZE];
	readFile.seekg(MESSAGE_ID, std::ios::beg);
	readFile.getline(bufferMessage, BUFFER_SIZE);

	writeFile << bufferMessage << std::endl;
	writeFile << std::endl;

	writeFile << "Sincerely," << std::endl;

	char bufferSenderName[BUFFER_SIZE];
	readFile.seekg(SENDER_NAME_ID, std::ios::beg);
	readFile.getline(bufferSenderName, BUFFER_SIZE);

	writeFile << bufferSenderName << std::endl;
}

int main()
{
	ReplacePlaceholders(READ_FILE_NAME, WRITE_FILE_NAME);
}

