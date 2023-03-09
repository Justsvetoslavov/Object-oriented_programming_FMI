//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>
#include <fstream>

const int SIZE = 128;
const int USERS = 100;
const char FILENAME[] = "usersList.txt";

struct User
{
    char name[SIZE + 1];
    char email[SIZE + 1];
    char password[SIZE + 1];
};

struct System
{
    User systemOfUsers[USERS];
    int countOfStudentsInSystem;
};

void inputUsers(System &newSystem)
{
    std::ofstream writeInFile(FILENAME, std::ios::app);
    if (!writeInFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened!";
        return;
    }

    for (int i = 0; i < USERS; ++i)
    {
        writeInFile << newSystem.systemOfUsers[i].name
            << newSystem.systemOfUsers[i].email 
            << newSystem.systemOfUsers[i].password << std::endl;

        ++newSystem.countOfStudentsInSystem;
    }

    writeInFile.close();
}

void printUsersList(System &newSystem)
{
    std::ifstream readFromFile(FILENAME);
    if (!readFromFile.is_open())
    {
        std::cout << "ERROR! The file could not be opened!";
        return;
    }

    int count = 0;
    for (int i = 0; i < USERS; ++i)
    {
        readFromFile >> newSystem.systemOfUsers[i].name
            >> newSystem.systemOfUsers[i].email
            >> newSystem.systemOfUsers[i].password;

        ++count;
    }
    newSystem.countOfStudentsInSystem = count;

    readFromFile.close();
}

void makeRegistration(System& newSystem)
{
    std::cout << "Enter your name: ";
    std::cin >> newSystem.systemOfUsers[0].name;

    std::cout << "Enter your email: ";
    std::cin >> newSystem.systemOfUsers[1].email;

    std::cout << "Enter your password: ";
    std::cin >> newSystem.systemOfUsers[2].password;

    inputUsers(newSystem);

    std::cout << "You are successfully registered!" << std::endl;
}

int strCompare(const char str1[], const char str2[])
{
    int i;
    for (i = 0; str1[i] && str2[i]; ++i)
    {
        if (str1[i] != str2[i])
        {
            break;
        }
    }

    if (str1[i] == str2[i])
    {
        return 1;
    }

    return 0;
}

void logInTheSystem(const System& newSystem)
{
    char name[SIZE + 1];
    char email[SIZE + 1];
    char password[SIZE + 1];
    bool registrated = 0;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your email: ";
    std::cin >> email;

    std::cout << "Enter your password: ";
    std::cin >> password;

    for (int i = 0; i < newSystem.countOfStudentsInSystem; ++i)
    {
        if (strCompare(name, newSystem.systemOfUsers[i].name) == 1 &&
            strCompare(email, newSystem.systemOfUsers[i].email) == 1 &&
            strCompare(password, newSystem.systemOfUsers[i].password)== 1)
        {
            registrated = 1;
        }
    }

    if (registrated == 0)
    {
        std::cout << "Your data is invalid!";
        return;
    }
    else
    {
        std::cout << "You are successfully logged in!";
    }
}

int main()
{
    System newSystem;

    printUsersList(newSystem);

    int choice;

    std::cout << "MENU" << std::endl;
    std::cout << "1. Make a registration" << std::endl;
    std::cout << "2. Long in the system" << std::endl;
    std::cout << std::endl << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1)
    {
        makeRegistration(newSystem);
    }
    else if (choice == 2)
    {
        logInTheSystem(newSystem);
    }
    else
    {
        std::cout << "Wrong number!";
        return 0;
    }

    return 0;
}
