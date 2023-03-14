#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

const int MAX_SIZE = 128;
const int MAX_USERS = 100;
const char fileName[] = "users.txt";
 
struct User {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char password[MAX_SIZE];
};

void InitUser(User& user)
{
    cout << "Enter name: ";
    cin.getline(user.name, MAX_SIZE);
    cout << "Enter email: ";
    cin.getline(user.email, MAX_SIZE);
    cout << "Enter password: ";
    cin.getline(user.password, MAX_SIZE);
}

void WriteUserToFile(User& user, ofstream& writeFile)
{
    if (!writeFile.is_open())
    {
        cout << "Error.";
        return;
    }
    writeFile << user.name << endl;
    writeFile << user.email << endl;
    writeFile << user.password << endl;
}

void ReadUserFromFile(User& user, ifstream& readFile)
{
    if (!readFile.is_open())
    {
        cout << "Error.";
        return;
    }
    readFile.getline(user.name, MAX_SIZE);
    readFile.getline(user.email, MAX_SIZE);
    readFile.getline(user.password, MAX_SIZE);
}

struct System {
    User Users[MAX_USERS];
    unsigned int count = 0;
};

void AddUserToSystem(System& system, User user)
{
    if (system.count <= MAX_USERS)
    {
        system.Users[system.count] = user;
        system.count++;
    }
}

void WriteSystemToFile(System& system, ofstream& writeFile)
{
    if (!writeFile.is_open())
    {
        cout << "Error";
        return;
    }
    for (size_t i = 0; i < system.count; i++)
    {
        WriteUserToFile(system.Users[i], writeFile);
    }
}

void ReadSystemFromFile(System& system, const char* fileName)
{
    ifstream readFile(fileName);
    if (!readFile.is_open())
    {
        cout << "Error.";
        return;
    }
    for (size_t i = 0; i < system.count; i++)
    {
        ReadUserFromFile(system.Users[i], readFile);
    }
    readFile.close();
}

bool IsUserLogin(System& system, User userCopy)
{
    for(int i = 0; i <= system.count; i++)
    {
        if (system.Users[i].name == userCopy.name &&
            system.Users[i].email == userCopy.email &&
            system.Users[i].password == userCopy.password)
            return true;
    }
    return false;
}

int main()
{
    User loginUser;
    System system;
    ofstream writeFile(fileName);
    char command[MAX_SIZE];
    cout << "Enter command(register or login): ";
    do {
        cin.getline(command, MAX_SIZE);
    } while (strcmp(command, "register") != 0 &&
             strcmp(command, "login") != 0);
    if (strcmp(command, "register") == 0)
    {
        InitUser(loginUser);
        AddUserToSystem(system, loginUser);
        WriteSystemToFile(system, writeFile);
        cout << "Register successful" << endl;
    }
    if (strcmp(command, "login") == 0)
    {
        InitUser(loginUser);
        ReadSystemFromFile(system, fileName);
        if (IsUserLogin(system, loginUser))
            cout << "Login successful";
        else
            cout << "Login unsuccessful";
    }
    writeFile.close();
}