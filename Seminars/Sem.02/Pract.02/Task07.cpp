#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;

const char *FILE_NAME = "../users.txt";

const int max_length = 128;
const int max_users = 100;

struct User {
    char name[max_length + 1];
    char email[max_length + 1];
    char password[max_length + 1];

    void addUserToFile(const char *fileName) {
        ofstream file(fileName, std::ios::app | std::ios::out);
        if (!file.is_open()) {
            cout << "File is not open" << endl;
            return;
        }

        file << name << endl;
        file << email << endl;
        file << password << endl;

        file.close();
    }
};

struct System {
    User users[max_users];
    int users_count;

    void addSystemToFile(const char *fileName) {
        ofstream file(fileName, std::ios::app | std::ios::out);
        if (!file.is_open()) {
            cout << "File is not open" << endl;
            return;
        }

        for (int i = 0; i < users_count; ++i) {
            file << users[i].name << endl;
            file << users[i].email << endl;
            file << users[i].password << endl;
        }

        file.close();
    }

    int readSystemFromFile(const char *fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cout << "File is not open" << endl;
            return -1;
        }
        for (int i = 0; i < max_users && !file.eof(); ++i) {
            file.getline(users[i].name, max_length);
            file.getline(users[i].email, max_length);
            file.getline(users[i].password, max_length);
            ++users_count;
        }

        file.close();
        return 0;
    }
};


int login(const char *email, const char *password, System &system) {
    for (int i = 0; i < system.users_count; ++i) {
        if (!strcmp(system.users[i].email, email) &&
            !strcmp(system.users[i].password, password)) {
            return 0;
        } else if (!strcmp(system.users[i].email, email) &&
                   strcmp(system.users[i].password, password)) {
            return 1;
        }
    }
    return -1;
}

int registerUser(const char *name, const char *email, const char *password, System &system) {
    for (int i = 0; i < system.users_count; ++i) {
        if (!strcmp(system.users[i].email, email)) {
            return 1;
        }
    }
    if (system.users_count >= max_users) {
        return -1;
    }
    strcpy(system.users[system.users_count].name, name);
    strcpy(system.users[system.users_count].email, email);
    strcpy(system.users[system.users_count].password, password);
    ++system.users_count;

    system.users[system.users_count - 1].addUserToFile(FILE_NAME);
    return 0;
}

int main() {
    cout << "Welcome to the system" << endl;
    System system{};
    char *command = new char[max_length];
    int status = system.readSystemFromFile(FILE_NAME);
    if (status == -1) {
        cout << "System isn't working right now. Theres file error. Try again later" << endl;
    } else {
        cout << "All users are loaded successfully" << endl;
        cout << "Available commands: register, login, save, reload, exit." << endl;
    }
    while (true) {
        cout << "\\> ";
        cin.getline(command, max_length);
        if (!strcmp(command, "register")) {
            char *name = new char[max_length];
            char *email = new char[max_length];
            char *password = new char[max_length];
            cout << "Enter name: ";
            cin.getline(name, max_length);
            cout << "Enter email: ";
            cin.getline(email, max_length);
            cout << "Enter password: ";
            cin.getline(password, max_length);
            int result = registerUser(name, email, password, system);
            if (result == 0) {
                cout << "User registered successfully" << endl;
            } else if (result == 1) {
                cout << "User with this email already exists" << endl;
            } else {
                cout << "System is full" << endl;
            }
            delete[] name;
            delete[] email;
            delete[] password;
        } else if (!strcmp(command, "login")) {
            char *email = new char[max_length];
            char *password = new char[max_length];
            cout << "Enter email: ";
            cin.getline(email, max_length);
            cout << "Enter password: ";
            cin.getline(password, max_length);
            int result = login(email, password, system);
            if (result == 0) {
                cout << "User logged in successfully" << endl;
            } else if (result == 1) {
                cout << "Wrong password" << endl;
            } else {
                cout << "User with this email does not exist" << endl;
            }
            delete[] email;
            delete[] password;
        } else if (!strcmp(command, "save")) {
            system.addSystemToFile(FILE_NAME);
        } else if (!strcmp(command, "reload")) {
            system.readSystemFromFile(FILE_NAME);
            cout << "System reloaded successfully" << endl;
        } else if (!strcmp(command, "exit")) {
            break;
        } else {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}
