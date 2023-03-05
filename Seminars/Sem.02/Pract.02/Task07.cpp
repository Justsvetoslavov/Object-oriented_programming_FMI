#include <iostream>
#include <fstream>

const int MAX_LEN = 128;
const int MAX_NUMBER_OF_USERS = 100;

struct User {
    char name[MAX_LEN];
    char email[MAX_LEN];
    char password[MAX_LEN];
};

struct System {
    User users[MAX_NUMBER_OF_USERS];
    unsigned int numberOfUsers = 0;
};

void myStrcpy(char* dest, const char* src) {
    int ind = 0;
    while (*src) {
        dest[ind++] = *(src++);
    }
    dest[ind] = '\0';
}

void readUserFromFile(std::ifstream& file, User& user) {
    file.getline(user.name, MAX_LEN);
    file.getline(user.email, MAX_LEN);
    file.getline(user.password, MAX_LEN);
}

void writeUserToFile(std::ofstream& file, const User& user) {
    file << user.name << "\n";
    file << user.email << "\n";
    file << user.password << "\n";
}

void registerUser(System& system) {
    if (system.numberOfUsers >= MAX_NUMBER_OF_USERS) {
        std::cout << "Error. The system is full\n";
        return;
    }

    char buff[MAX_LEN];
    User user;

    std::cout << "Enter name:\n";
    std::cin.ignore();
    std::cin.getline(buff, MAX_LEN);
    myStrcpy(user.name, buff);

    std::cout << "Enter email:\n";
    std::cin.getline(buff, MAX_LEN);
    myStrcpy(user.email, buff);

    std::cout << "Enter password:\n";
    std::cin.getline(buff, MAX_LEN);
    myStrcpy(user.password, buff);

    system.users[system.numberOfUsers] = user;
    system.numberOfUsers++;

    std::cout << "Registration successful\n";
}

void writeSystemToFile(const char fileName[], const System& system) {
    std::ofstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Error\n";
        return;
    }

    file << system.numberOfUsers << "\n";

    for (int i = 0; i < system.numberOfUsers; i++) {
        writeUserToFile(file, system.users[i]);
    }

    file.close();
}

void readSystemFromFile(const char fileName[], System& system) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Error\n";
        return;
    }

    unsigned int size;
    file >> size;
    system.numberOfUsers = size;
    file.get();

    for (int i = 0; i < size; i++) {
        readUserFromFile(file, system.users[i]);
    }

    file.close();
}

int myStrlen(const char* str) {
    int ctr = 0;
    while (*str) {
        ctr++;
        str++;
    }
    return ctr;
}

bool myStrcmp(const char* str1, const char* str2) {
    int len1 = myStrlen(str1);
    int len2 = myStrlen(str2);

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

int getUserIndex(const System& system, const char email[]) {
    for (int i = 0; i < system.numberOfUsers; i++) {
        if (myStrcmp(system.users[i].email, email)) {
            return i;
        }
    }
    return -1;
}

void loginUser(const System& system) {
    char buff[MAX_LEN];
    std::cout << "Enter email:\n";
    std::cin.ignore();
    std::cin.getline(buff, MAX_LEN);

    int ind = getUserIndex(system, buff);

    if (ind < 0) {
        std::cout << "User not found\n";
        return;
    }

    do {
        std::cout << "Enter password:\n";
        std::cin.getline(buff, MAX_LEN);

        if (myStrcmp(system.users[ind].password, buff)) {
            std::cout << "Login successful\n";
            return;
        }

        else {
            std::cout << "Incorrect password\n";
            std::cout << "Enter 0 to quit and 1 to try again\n";
            int command;
            std::cin >> command;

            switch (command) {
            case 0:
                return;
            case 1:
                break;
            default:
                std::cout << "Invalid command\n";
            }
        }

    } while (1);
}

void printUser(const User& user) {
    std::cout << user.name << " " << user.email << " " << user.password << "\n";
}

void printSystem(const System& system) {
    for (int i = 0; i < system.numberOfUsers; i++) {
        printUser(system.users[i]);
    }
}

int main()
{
    const char fileName[] = "System.txt";
    System system;
    readSystemFromFile(fileName, system);
    printSystem(system);

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
            registerUser(system);
            break;
        case 2:
            loginUser(system);
            break;
        default:
            std::cout << "Invalid command\n";
        }
    } while (getUserInput);

    writeSystemToFile(fileName, system);
}
