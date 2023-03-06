//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>
#include <fstream>

const char TEMPLATENAME[] = "template.txt";
const char INFOFILE[] = "information.txt";
const int ARRSIZE = 30;
const int BUFFSIZE = 1024;

void inputInfo(char* title, char* recipientName, char* message, char* senderName)
{
    std::cout << "Enter title: ";
    std::cin.getline(title, ARRSIZE + 1);
    std::cout << "Enter recipient name: ";
    std::cin.getline(recipientName, ARRSIZE + 1);
    std::cout << "Enter message: ";
    std::cin.getline(message, ARRSIZE + 1);
    std::cout << "Enter sender name: ";
    std::cin.getline(senderName, ARRSIZE + 1);
}

void createInfoFile(const char* title, const char* recipientName, const char* message, const char* senderName)
{
    std::ofstream writeInFile(INFOFILE);

    if (!writeInFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return;
    }

    writeInFile << "title: " << title << std::endl
        << "recipient_name: " << recipientName << std::endl
        << "message: " << message << std::endl
        << "sender_name: " << senderName;

    writeInFile.close();
}

void createTemplate(char* title, char* recipientName, char* message, char* senderName)
{
    std::ofstream writeInFile(TEMPLATENAME);

    if (!writeInFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return;
    }

    writeInFile << "Dear, " << title << " " << recipientName << "." << std::endl
        << std::endl << message << std::endl
        << std:: endl << "Sincerely, " << senderName;

    writeInFile.close();
}

void readFromFile(char buffer[])
{
    std::ifstream readFromFile(TEMPLATENAME);
    if (!readFromFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened! ";
        return;
    }

    while (!readFromFile.eof())
    {
        readFromFile.getline(buffer, BUFFSIZE);
        std::cout << buffer << std::endl;
    }

    readFromFile.close();
}

int main()
{
    char* title = new char[ARRSIZE + 1];
    char* recipientName = new char[ARRSIZE + 1];
    char* message = new char[ARRSIZE + 1];
    char* senderName = new char[ARRSIZE + 1];
    char buffer[BUFFSIZE] = {};
    
    inputInfo(title, recipientName, message, senderName);
    createInfoFile(title, recipientName, message, senderName);
    createTemplate(title, recipientName, message, senderName);
    std::cout << std::endl;
    readFromFile(buffer);

    delete[] title;
    delete[] recipientName;
    delete[] message;
    delete[] senderName;

    return 0;
}
