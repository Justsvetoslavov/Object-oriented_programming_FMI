#include <iostream>
#include <fstream>

const unsigned short FIELD_MAX_SIZE = 128;
const unsigned short MAX_USER_COUNT = 100;
const char SYSTEM_FILE_NAME[] = "system.txt";
const char USER_FILE_NAME[] = "user.txt";
const char SYSTEM_NAME[] = "System";
const char DELIM = '|';

struct User
{
    char name[FIELD_MAX_SIZE] = {'\0'};
    char email[FIELD_MAX_SIZE] = {'\0'};
    char password[FIELD_MAX_SIZE] = {'\0'};
};

struct System
{
    int size = 0;
    User users[MAX_USER_COUNT] = {{'\0'}, {'\0'}, {'\0'}};
};

int saveSystem(const System &system)
{
    std::ofstream file(SYSTEM_FILE_NAME);

    if (!file.is_open())
    {
        return 1;
    }

    file << SYSTEM_NAME << std::endl;

    for (int i = 0; i < system.size; ++i)
    {
        file << system.users[i].name << DELIM << system.users[i].email << DELIM << system.users[i].password << std::endl;
    }

    file.close();

    return 0;
}

bool compStr(const char str1[], const char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        ++i;
    }
    return true;
}

User parseLine(const char line[])
{
    int idx = 0;
    int i = 0;
    User user;

    while (line[idx] != DELIM && idx < FIELD_MAX_SIZE)
    {
        user.name[idx] = line[idx];
        ++idx;
    }
    ++idx;

    while (line[idx] != DELIM && idx < FIELD_MAX_SIZE)
    {
        user.email[i++] = line[idx];
        ++idx;
    }
    ++idx;
    i = 0;

    while (line[idx] != '\0' && idx < FIELD_MAX_SIZE)
    {
        user.password[i++] = line[idx];
        ++idx;
    }

    return user;
}

int loadSystem(System &system)
{
    std::ifstream file(SYSTEM_FILE_NAME);

    if (!file.is_open())
    {
        return 1;
    }

    bool checked = false;
    User user;

    while (!file.eof())
    {
        char line[FIELD_MAX_SIZE] = {'\0'};

        file.getline(line, FIELD_MAX_SIZE);

        if (!checked)
        {
            if (!compStr(line, SYSTEM_NAME))
            {
                return 1;
            }
            checked = true;
            continue;
        }

        system.users[system.size++] = parseLine(line);
    }

    return 0;
}

int saveUser(const User &user)
{
    std::ofstream file(USER_FILE_NAME);

    if (!file.is_open())
    {
        return 1;
    }

    file << user.name << '\n'
         << user.email << '\n'
         << user.password << std::endl;

    file.close();

    return 0;
}

int addUser(const User &user, System &system)
{
    if (system.size + 1 > FIELD_MAX_SIZE)
    {
        return 1;
    }

    system.users[system.size++] = user;

    return saveSystem(system);
}

void loadUser(User &user)
{
    std::ifstream file(USER_FILE_NAME);
    file.getline(user.name, FIELD_MAX_SIZE);
    file.getline(user.email, FIELD_MAX_SIZE);
    file.getline(user.password, FIELD_MAX_SIZE);
}

int registerUser(System &system)
{
    User newUser;
    std::cout << "Enter name: ";
    std::cin >> newUser.name;
    std::cout << std::endl;

    std::cout << "Enter email: ";
    std::cin >> newUser.email;
    std::cout << std::endl;

    std::cout << "Enter password: ";
    std::cin >> newUser.password;
    std::cout << std::endl;

    return addUser(newUser, system);
}

int checkUser(const User &user, const char email[], const char password[])
{
    if (!compStr(user.email, email))
    {
        return 1;
    };

    if (!compStr(user.password, password))
    {
        return 2;
    };

    return 0;
}

User loginUser(const System &system)
{
    char password[FIELD_MAX_SIZE] = {'\0'};
    char email[FIELD_MAX_SIZE] = {'\0'};

    std::cin.ignore(1000, '\n');

    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << std::endl;

    std::cin.ignore(1000, '\n');

    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    for (int i = 0; i < system.size; ++i)
    {
        if (checkUser(system.users[i], email, password) == 0)
        {
            return system.users[i];
        };
    }

    std::cout << "Error" << std::endl;

    return {{'\0'}, {'\0'}, {'\0'}};
}

int main()
{
    System system;
    User user;

    if (loadSystem(system) != 0)
    {
        std::cout << "Cannot load system!";
        return 1;
    };

    std::cout << "Choose an option: " << std::endl;
    std::cout << "R -> Register" << std::endl;
    std::cout << "L -> Login" << std::endl;

    while (1)
    {
        char option = '\0';
        std::cin >> option;

        switch (option)
        {
        case 'R':
            if (registerUser(system) != 0)
            {
                std::cout << "Error registering new user!";
                break;
            };

            std::cout << "Successful registration" << std::endl;
            continue;

        case 'L':
            if (user.email[0] != '\0')
            {
                std::cout << "An user is already logged in." << std::endl;
                continue;
            }

            user = loginUser(system);

            if (user.email[0] == '\0')
            {
                std::cout << "Error logging in!";
                break;
            }

            std::cout << "Successful login" << std::endl;
            continue;

        default:
            std::cout << "Invalid input" << std::endl;
            std::cin.ignore();
            std::cin.clear();
            continue;
        }
        break;
    }

    return 0;
}