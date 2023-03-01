#include <iostream>
#include <fstream>

const char* FILE_NAME = "myFile.txt";

void createMassege()
{
    std::fstream file(FILE_NAME);
    char title[11];
    char recipientName[31];
    char message[951];
    char senderName[31];
    std::cin.getline(title, 11);
    std::cin.ignore();
    std::cin.getline(recipientName, 31);
    std::cin.ignore();
    std::cin.getline(message, 951);
    std::cin.ignore();
    std::cin.getline(senderName, 31);
    file << "Dear, " << title << ' ' << recipientName << '\n'
    << message << '\n' << "Sincerely,\n" << senderName;
}

void readMessage()
{
    std::fstream file(FILE_NAME);
    char buffer[1024];
    file.getline(buffer, 1024);
    std::cout << buffer << '\n';
}
int main()
{
    std::ifstream file(FILE_NAME);
    
    if(!file.is_open())
    {
        std::cout << "Error!" << std::endl;
        return -1;
    }
    
    createMassege();
    readMessage();

    file.close();
    return 0;
}