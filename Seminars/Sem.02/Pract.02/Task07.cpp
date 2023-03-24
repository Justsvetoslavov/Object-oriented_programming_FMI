#include <iostream>
#include <fstream>

const int MAX_LEN = 128;
const int MAX_NUMBER_OF_USERS = 100;

struct User {
    char name[MAX_LEN + 1];
    char email[MAX_LEN + 1];
    char password[MAX_LEN + 1];
};

struct System {
    User users[MAX_NUMBER_OF_USERS];
    unsigned int numberOfUsers = 0;
};

void MyStrcpy(char* dest, const char* src) {
    size_t index = 0;
    while (src[index] != '\0') {
        dest[index] = src[index];
        ++index;
    }
    dest[index] = '\0';
}

void ReadUserFromFile(std::ifstream& file, User& user) {
    file.getline(user.name, MAX_LEN);
    file.getline(user.email, MAX_LEN);
    file.getline(user.password, MAX_LEN);

    user.name[MAX_LEN] = user.email[MAX_LEN] = user.password[MAX_LEN] = '\0'; //add null terminator
}

void WriteUserToFile(std::ofstream& file, const User& user) {
    file << user.name << "\n";
    file << user.email << "\n";
    file << user.password << "\n";
}

bool RegisterUser(System& system) {
    if (system.numberOfUsers >= MAX_NUMBER_OF_USERS) {
        std::cout << "Error. The system is full\n";
        return false;
    }

    char buff[MAX_LEN + 1];
    User user;
    std::cin.ignore();

    std::cout << "Enter name:\n";
    std::cin.getline(buff, MAX_LEN);
    buff[MAX_LEN] = '\0';
    MyStrcpy(user.name, buff);

    std::cout << "Enter email:\n";
    std::cin.getline(buff, MAX_LEN);
    buff[MAX_LEN] = '\0';
    MyStrcpy(user.email, buff);

    std::cout << "Enter password:\n";
    std::cin.getline(buff, MAX_LEN);
    buff[MAX_LEN] = '\0';
    MyStrcpy(user.password, buff);

    system.users[system.numberOfUsers] = user;
    ++system.numberOfUsers;

    std::cout << "Registration successful\n";
    return true;
}

bool WriteSystemToFile(const char* fileName, const System& system) {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Error\n";
        return false;
    }

    file << system.numberOfUsers << "\n";

    for (size_t i = 0; i < system.numberOfUsers; i++) {
        WriteUserToFile(file, system.users[i]);
    }

    file.close();
    return true;
}

bool readSystemFromFile(const char fileName[], System& system) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Error\n";
        return false;
    }

    size_t size;
    file >> size;
    system.numberOfUsers = size;
    file.get();

    for (size_t i = 0; i < size; ++i) {
        ReadUserFromFile(file, system.users[i]);
    }

    file.close();
    return true;
}

size_t MyStrlen(const char* str) {
    size_t index = 0;
    while (str[index] != '\0') {
        ++index;
    }
    return index;
}

bool MyStrcmp(const char* str1, const char* str2) {
    int len1 = MyStrlen(str1);
    int len2 = MyStrlen(str2);

    if (len1 != len2) {
        return false;
    }

    //The strings are of equal length, so one check is enough
    while (*str1) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return true;
}

int GetUserIndex(const System& system, const char* email) {
    for (size_t i = 0; i < system.numberOfUsers; ++i) {
        if (MyStrcmp(system.users[i].email, email)) {
            return i;
        }
    }
    return -1;
}

bool LoginUser(const System& system) {
    std::cin.ignore();

    char buff[MAX_LEN + 1];
    std::cout << "Enter email:\n";
    std::cin.getline(buff, MAX_LEN);
    buff[MAX_LEN] = '\0';

    int ind = GetUserIndex(system, buff);

    if (ind < 0) {
        std::cout << "User not found\n";
        return false;
    }

    do {
        std::cout << "Enter password:\n";
        std::cin.getline(buff, MAX_LEN);
        buff[MAX_LEN] = '\0';

        if (MyStrcmp(system.users[ind].password, buff)) {
            std::cout << "Login successful\n";
            return false;
        } else {
            std::cout << "Incorrect password\n";
            std::cout << "Enter 0 to quit and 1 to try again\n";
            int command;
            std::cin >> command;

            switch (command) {
            case 0:
                return false;
            case 1:
                break;
            default:
                std::cout << "Invalid command\n";
                return false;
            }
        }
    } while(true);
}

void PrintUser(const User& user) {
    std::cout << user.name << " " << user.email << " " << user.password << "\n";
}

void PrintSystem(const System& system) {
    for (size_t i = 0; i < system.numberOfUsers; ++i) {
        PrintUser(system.users[i]);
    }
}

int main()
{
    const char fileName[] = "System.txt";
    System system;
    ReadSystemFromFile(fileName, system);
    PrintSystem(system);

    int command;
    bool getUserInput = true;

    do {
        std::cout << "Enter 0 to quit, 1 to register and 2 to login:\n";
        std::cin >> command;

        switch (command) {
        case 0:
            getUserInput = false;
            break;
        case 1: 
            RegisterUser(system);
            break;
        case 2:
            LoginUser(system);
            break;
        default:
            std::cout << "Invalid command\n";
        }
    } while (getUserInput);

    WriteSystemToFile(fileName, system);
}