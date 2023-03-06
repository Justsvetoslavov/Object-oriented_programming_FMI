#include <iostream>
#include <fstream>

const char FILE_PATH[] =
        "C:\\Users\\nikol\\Documents\\"
        "GitHub\\Object-oriented_programming_FMI_2023\\"
        "Seminars\\Sem.02\\Pract.02\\"
        "result.txt";

long long lengthOfFile(const char* fileName){

    std::ifstream file(fileName,std::ios::in);

    if(!file.is_open())return -1;

    file.seekg(0,std::ios::end);

    return file.tellg();

}
int main(){

    std::cout<<lengthOfFile(FILE_PATH);

}
