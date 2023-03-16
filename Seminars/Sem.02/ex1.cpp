#include <iostream>
#include <fstream>

void printCode(std::ifstream& ifs){

    if(! ifs.is_open()){
        std::cout<<"Error";
        return;
    }
    while (!ifs.eof()){
        char buff[128];
       ifs.getline(buff,128);
       std::cout<<buff<<std::endl;
    }

}

int main(){

    std::ifstream input("ex1.cpp");
    printCode(input);
    return 0;
}