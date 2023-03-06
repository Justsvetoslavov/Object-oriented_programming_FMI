#include <iostream>
#include <fstream>

const int MAX_LENGTH = 128;
const int MAX_NUM_OF_USERS = 100;
const int MAX_BUFF_SIZE = 1024;

struct User
{
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char password[MAX_LENGTH];
};

struct System
{
    User users[MAX_NUM_OF_USERS];
};

void toBeginningOfFile()
{
    std::ifstream usersFile("users_system.txt", std::ios::app | std::ios::_Nocreate);

    if (!usersFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return;
    }

    usersFile.clear();
    usersFile.seekg(0, std::ios::beg);
}

void writeUserToFile(const User& user)
{
    std::ofstream usersFile("users_system.txt", std::ios::app | std::ios::_Nocreate);

    if (!usersFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return;
    }

    usersFile << user.name << "," << user.email << "," << user.password << '\n';

    usersFile.close();
}

void readUserFromFile(const char* input, User& user)
{
    int index = 0;

    while (input[index] != ',')
    {
        user.name[index] = input[index];
        index++;
    }

    user.name[index] = '\0';
    index++;

    int emailIndex = 0;

    while (input[index] != ',')
    {
        user.email[emailIndex] = input[index];
        emailIndex++;
        index++;
    }

    user.email[emailIndex] = '\0';
    index++;

    int passwordIndex = 0;

    while (input[index] != '\n')
    {
        user.password[passwordIndex] = input[index];
        passwordIndex++;
        index++;
    }

    user.password[passwordIndex] = '\0';
}

void writeSystemOfUsersToFile(const System& users, const int usersCount)
{
    std::ofstream usersFile("users_system.txt", std::ios::app | std::ios::_Nocreate);

    if (!usersFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return;
    }

    for (size_t i = 0; i < usersCount; i++)
    {
        usersFile << users.users[i].name << ',' << users.users[i].email << ',' << users.users[i].password << '\n';
    }

    usersFile.close();
}

void readSystemOfUsersFromFile(System& users, int usersCount)
{
    std::ifstream usersFile("users_system.txt", std::ios::app | std::ios::_Nocreate);

    if (!usersFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return;
    }

    int line = 1;

    while (!usersFile.eof())
    {
        char buffer[MAX_BUFF_SIZE];
        usersFile.getline(buffer, MAX_BUFF_SIZE);

        if (line == 1 || line - 2 == usersCount)
        {
            line++;
            continue;
        }

        readUserFromFile(buffer, users.users[line - 2]);
        line++;
    }

    toBeginningOfFile();
}

void StrCopy(char* dest, const char* source)
{
    size_t index = 0;
    while (source[index] != '\0') {
        dest[index] = source[index];
        index++;
    }

    dest[index] = '\0';
}

int countLines()
{
    std::ifstream usersFile("users_system.txt", std::ios::app | std::ios::_Nocreate);

    if (!usersFile.is_open())
    {
        std::cout << "Error ocurred when trying to open the file." << std::endl;

        return -1;
    }

    unsigned lines = 0;

    while (!usersFile.eof())
    {
        char buffer[MAX_BUFF_SIZE];
        usersFile.getline(buffer, MAX_BUFF_SIZE);
        lines++;
    }

    toBeginningOfFile();

    return lines - 1;
}


int main()
{
    char command[MAX_BUFF_SIZE];

    System users;
    int numOfUsers = countLines();
    int currentUserIndex = countLines();

    do
    {
        std::cout << "Enter command:" << '\n' << "\\>";
        std::cin >> command;

        if (strcmp(command, "register") == 0)
        {
            User user;
            std::cout << "Enter name:" << '\n' << "\\>";
            char name[MAX_LENGTH];
            std::cin >> name;
            StrCopy(user.name, name);

            std::cout << "Enter email:" << '\n' << "\\>";
            char email[MAX_LENGTH];
            std::cin >> email;
            StrCopy(user.email, email);

            std::cout << "Enter password:" << '\n' << "\\>";
            char password[MAX_LENGTH];
            std::cin >> password;
            StrCopy(user.password, password);

            writeUserToFile(user);

            std::cout << "Registration successful" << '\n';
        }
        else if (strcmp(command, "login") == 0)
        {
            std::cout << "Enter email:" << '\n' << "\\>";
            char email[MAX_LENGTH];
            std::cin >> email;

            std::cout << "Enter password:" << '\n' << "\\>";
            char password[MAX_LENGTH];
            std::cin >> password;

            readSystemOfUsersFromFile(users, numOfUsers);

            for (size_t i = 0; i < numOfUsers; i++)
            {
                if (strcmp(users.users[i].email, email) == 0 && strcmp(users.users[i].password, password) == 0)
                {
                    std::cout << "Login successful" << '\n';
                    break;
                }
                
                std::cout << "Login not successful" << '\n';
                break;
            }
        }

    } while (strcmp(command, "exit"));

    return 0;
}
