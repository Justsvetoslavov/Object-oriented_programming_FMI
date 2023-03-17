#include <iostream>
#include <fstream>

const unsigned short MAX_SIZE = 128;
const unsigned short MAX_USERS = 100;
const unsigned short BUFFER_SIZE = 150;
const unsigned short COMMAND_SIZE = 150;
const char* SYSTEM_FILE_NAME = "system.txt";
unsigned short registeredUsers = 0;

struct User
{
    char name[MAX_SIZE + 1];
    char email[MAX_SIZE + 1];
    char password[MAX_SIZE + 1];
};

struct System
{
    User users[MAX_USERS];
};

void registerUser(User& user);
bool validName(const char* name);
bool validEmail(const char* email);
bool validPassword(const char* password);
void writeUserToFile(const User& user);
void readUserFromFile();
bool userInSystem(System s, const unsigned short registeredUsers);
bool myStrCompare(const char* arr1, const char* arr2);
unsigned int myStrLen(const char* arr);
void loadUsersFromFile(System& s);


int main()
{
    System s;
    loadUsersFromFile(s);
    char command[COMMAND_SIZE + 1];
    do
    {
        std::cout << "Enter command \n Register, Login or End \n";
        std::cin.getline(command, COMMAND_SIZE + 1);

        switch (command[0])
        {
        case 'R':
            registerUser(s.users[registeredUsers]);
            writeUserToFile(s.users[registeredUsers]);
            registeredUsers += 1;
            break;
        case 'L':
            if(userInSystem(s, registeredUsers))
                std::cout << "Login successful \n";
            else
                std::cout << "There is not such a user \n";
            continue;
            break;    
        default:
            std::cout << "Invalid command \n";
            break;
        }
    } while (!myStrCompare(command, "End"));
    
    readUserFromFile();

    return 0;
}

void registerUser(User& user)
{
    std::cout << "Enter name: " << '\n'; 
    do
    {
        std::cin.getline(user.name, MAX_SIZE + 1);
        if(!validName(user.name))
            std::cout << "Invalid Name \n";
    } while (!validName(user.name));

    std::cout << "Enter email: " << '\n'; 
    do
    {
         std::cin.getline(user.email, MAX_SIZE + 1);
        if(!validEmail(user.email))
            std::cout << "Invalid email \n";
    } while (!validEmail(user.email));
    
    std::cout << "Enter password: " << '\n'; 
    do
    {
        std::cin.getline(user.password, MAX_SIZE + 1);
        if(!validPassword(user.password))
            std::cout << "Invalid password! It has to be at least 8 symbols. \n And has at least one lower letter, upper letter, number and a special symbol. \n";
    } while (!validPassword(user.password));
}

bool validName(const char* name)
{
    int index = 0;
    while(name[index] != '\0')
    {
        if(!('a' <= name[index] && name[index] <= 'z') && !('A' <= name[index] && name[index] <= 'Z') && name[index] != ' ')
            return false;
        index += 1;
    }
    return true;
}

bool validEmail(const char* email)
{
    int count = 0;
    int index = 0;
    const char* com = "com";
    while(email[index] != '\0')
    {
        if(email[index] == '@')
            count += 1;
        index += 1;
    }
    for(int i = index - 3, j = 0; i < index; i++, j++)
    {
        if(email[i] != com[j])
            return false;
    }
    return count != 0;
}

bool validPassword(const char* password)
{
    int countLowerLetters = 0, countUpperLetters = 0, countNumbers = 0, countSpecialSymbols = 0, index = 0;
    while(password[index] != '\0')
    {
        if('a' <= password[index] && password[index] <= 'z')
            countLowerLetters += 1;
        else if('A' <= password[index] && password[index] <= 'Z')
            countUpperLetters += 1;
        else if('0' <= password[index] && password[index] <= '9')
            countNumbers += 1;
        else
            countSpecialSymbols += 1;

        index += 1;
    }
    return countLowerLetters > 0 && countUpperLetters > 0 && countNumbers > 0 && countSpecialSymbols > 0 && index + 1 >= 8;
}

void writeUserToFile(const User& user)
{
    std::fstream file(SYSTEM_FILE_NAME, std::ios::app);
    file << "Name: " << user.name << '\n'
    << "Email: " << user.email << '\n'
    << "Password: " << user.password <<'\n';
    file.flush();

    file.close();
}

void readUserFromFile()
{
    std::fstream file(SYSTEM_FILE_NAME);
    while(!file.eof())
    {
        char buffer[BUFFER_SIZE];
        file.getline(buffer, BUFFER_SIZE);
        std::cout << buffer << '\n';
    }

    file.close();
}

bool userInSystem(System s, const unsigned short registeredUsers)
{
    char email[MAX_SIZE + 1];
    char password[MAX_SIZE + 1];
    
    std::cout << "Enter email: " << '\n'; 
    do
    {
         std::cin.getline(email, MAX_SIZE + 1);
        if(!validEmail(email))
            std::cout << "Invalid email \n";
    } while (!validEmail(email));

    std::cout << "Enter password: " << '\n'; 
    std::cin.getline(password, MAX_SIZE + 1);
    

    for (size_t i = 0; i < registeredUsers; i++)
    {
        if(myStrCompare(s.users[i].email, email) && myStrCompare(s.users[i].password, password))
            return true;
    }
    return false;
}

bool myStrCompare(const char* arr1, const char* arr2)
{
    if(myStrLen(arr1) != myStrLen(arr2))
        return false;
    int index = 0;
    while(arr1[index] != '\0')
    {
        if(arr1[index] != arr2[index])
            return false;
        index += 1;
    }
    return true;
}

unsigned int myStrLen(const char* arr)
{
    unsigned int count = 0;
    while(arr[count] != '\0')
    {
        count += 1;
    }
    return count;
}

void loadUsersFromFile(System& s)
{
    std::ifstream file(SYSTEM_FILE_NAME);
    char follower[MAX_SIZE + 1];
    while(!file.eof())
    {
        file >> follower;
        file >> s.users[registeredUsers].name;
        file >> follower;
        file >> s.users[registeredUsers].email;
        file >> follower;
        file >> s.users[registeredUsers].password;
        registeredUsers += 1;
    }
    file.close();
}