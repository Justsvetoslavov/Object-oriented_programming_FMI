#include <iostream>
#include <fstream>

const int MAX_SIZE_CHAR = 128;
const char PATH[] = "Database.txt";
const char USER_ERROR[] = "NO_USER_ERROR";

struct User {
    char name[MAX_SIZE_CHAR] = "",
            email[MAX_SIZE_CHAR] = "",
            password[MAX_SIZE_CHAR] = "";
};

struct System {
    User users[100];
    int size = 0;
};

void error_input() {
    std::cout << "Incorrect input\n";
}

void writeUserToFile(std::fstream &file, const User &user) {
    file << user.email << " " << user.password << " " << user.name << std::endl;
}

User readUserFromFile(std::fstream &file, const int &mode = 0) {
    size_t curr_pos;
    if (mode == 0) {
        curr_pos = file.tellg();
        file.seekg(0, std::ios::beg);
    }
    User res;
    file.getline(res.email, MAX_SIZE_CHAR, ' ');
    file.getline(res.password, MAX_SIZE_CHAR, ' ');
    file.getline(res.name, MAX_SIZE_CHAR);
    if (mode == 0) {
        file.clear();
        file.seekg(curr_pos);
    }
    return res;
}

void writeSystemToFile(const char path[], const System &system) {
    std::fstream file(path, std::ios::out);
    for (int i = 0; i < system.size; ++i)
        writeUserToFile(file, system.users[i]);
    file.close();
}

System readSystemFromFile(const char path[]) {
    std::fstream file(path, std::ios::in);
    System sys;
    int i = -1;
    while (file.tellg() != EOF)
        sys.users[++i] = readUserFromFile(file, 1);
    sys.size = i;
    file.close();
    return sys;
}

bool strEqual(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2 != "\0" && str1[i] && str2[i]) {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    return true;
}

User findUser(const char path[], const User &user) {
    System system = readSystemFromFile(path);
    for (int i = 0; i < system.size; ++i) {
        if (strEqual(user.email, system.users[i].email) && strEqual(user.password, system.users[i].password))
            return system.users[i];
    }
    return User{"NO_USER_ERROR", "", ""};
}

int main() {
    char answer[MAX_SIZE_CHAR];
    std::fstream file;
    while (true) {
        std::cout << "Enter command:\n\\> ";
        std::cin >> answer;
        if (strEqual(answer, "register")) {
            file.open(PATH, std::ios::out | std::ios::app);
            User new_user;
            std::cout << "Enter name:\n\\> ";
            std::cin.ignore();
            std::cin.getline(new_user.name, MAX_SIZE_CHAR - 1);
            std::cout << "Enter email:\n\\> ";
            std::cin.getline(new_user.email, MAX_SIZE_CHAR - 1);
            std::cout << "Enter password:\n\\> ";
            std::cin.getline(new_user.password, MAX_SIZE_CHAR - 1);
            writeUserToFile(file, new_user);
            file.close();
        } else if (strEqual(answer, "login")) {
            User user;
            std::cout << "Enter email\n\\> ";
            std::cin.ignore();
            std::cin.getline(user.email, MAX_SIZE_CHAR);
            std::cout << "Enter password\n\\> ";
            std::cin.getline(user.password, MAX_SIZE_CHAR);
            user = findUser(PATH, user);
            if (strEqual(user.name, USER_ERROR))
                error_input();
            else {
                std::cout << "Login successful\nWelcome, " << user.name << std::endl;
                break;
            }
        } else
            error_input();
    }
}