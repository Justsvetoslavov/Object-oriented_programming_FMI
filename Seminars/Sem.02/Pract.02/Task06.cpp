#include <iostream>
#include <fstream>

const char PATH[] =
        "C:\\Users\\nikol\\Documents\\"
        "GitHub\\Object-oriented_programming_FMI_2023\\"
        "Seminars\\Sem.02\\Pract.02\\"
        "Task06.cpp";

int main(){

    std::ifstream file(PATH, std::ios::in);
    char temp[128];
    while ( file.getline(temp, sizeof temp) )
    {
        std::cout<<temp<<std::endl;
    }

    file.close();

    return 0;

}
