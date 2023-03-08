#include <iostream>
#include <fstream>

const char SYSTEM_PATH[] =
        "C:\\Users\\nikol\\Documents\\"
        "GitHub\\Object-oriented_programming_FMI_2023\\"
        "Seminars\\Sem.02\\Pract.02\\"
        "system.txt";

int const MAX_SIZE = 128;

struct User{

    char name[MAX_SIZE] = "Default";
    char email[MAX_SIZE] = "Default@emai.struct";
    char password[MAX_SIZE];

};

struct System{

    int size = 0;
    const int max_size = 100;
    User *userList = new User[max_size];

};

bool addUserToSystem(const User &user,System &system){

    if(system.size+1 == system.max_size)return false;

    system.userList[system.size++] = user;

    return true;

}

User createUser(const char name[],const char email[],const char password[]){

    User user;

    std::copy(&name[0],&name[sizeof user.name],user.name);
    std::copy(&email[0],&email[sizeof user.email],user.email);
    std::copy(&password[0],&password[sizeof user.password],user.password);

    return user;

}

bool downLoadData(System &system){

    std::ifstream file(SYSTEM_PATH,std::ios::in);
    if(!file.is_open())return false;

    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char password[MAX_SIZE];


    while(!file.eof()){

        file>>name;
        file>>email;
        file>>password;
        if(name[0] != '\0' or email[0] != '\0' or password[0] != '\0')
            addUserToSystem(createUser(name,email,password),system);

    }

    file.close();

    return true;

}

bool saveData(System &system){

    std::ofstream file(SYSTEM_PATH,std::ios::out);
    file.clear();
    for(int i = 0; i < system.size;i++){

        file<<system.userList[i].name<<std::endl;
        file<<system.userList[i].email<<std::endl;
        if(system.size - 1 == i) file<<system.userList[i].password;
        else file<<system.userList[i].password<<std::endl;

    }

    delete[] system.userList;
    file.close();

    return true;

}

void printUser(const User &user){

    std::cout<<"Name = "<<user.name<<" ";
    std::cout<<"Email = "<<user.email<<" ";
    std::cout<<"Password = "<<user.password<<"\n";

}

void printSystem(const System &system){

    for(int i = 0; i < system.size;i++){
        printUser(system.userList[i]);
    }

}
bool compareStr(const char left[],const char right[]){

    int i = 0;
    for(;left[i]!='\0' or right[i]!='\0';i++){
        if(left[i] != right[i])
            return false;
    }

    if(left[i] == '\0' and right[i] == '\0')return true;
    else return false;

}
bool loginUser(const User &user,System &system){

    for(int i=0;i< system.size;i++){

        if( compareStr(system.userList[i].email,user.email)
            and
            compareStr(system.userList[i].password,user.password) )
            return true;

    }

    return false;

}

int main(){

    System system;
    downLoadData(system);

    char registerCommand[] = "register";
    char loginCommand[] = "login";
    char command[8];

    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char password[MAX_SIZE];

    std::cout<<"Enter Command =>  ";
    std::cin>>command;

    if(compareStr(command,registerCommand)){

        std::cout<<"Name =>  ";
        std::cin>>name;
        std::cout<<"Email =>  ";
        std::cin>>email;
        std::cout<<"Password =>  ";
        std::cin>>password;

        addUserToSystem(createUser(name,email,password),system);

    }
    else if(compareStr(command,loginCommand)){

        std::cout<<"Email =>  ";
        std::cin>>email;
        std::cout<<"Password =>  ";
        std::cin>>password;

        if(loginUser(createUser("",email,password),system))
            std::cout<<"Login successful";
        else std::cout<<"No matches";
    }
    else std::cout<<"Wrong Command";

    saveData(system);

}
