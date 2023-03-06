#include <iostream>
#include <fstream>

bool printInFileDigit(std::ofstream& file, int digit){

    if(file.is_open()){
        file<<digit;
        file.flush();
        return true;
    }
    else return false;
}

int readDigitFromFile(std::ifstream& file){

    if(file.is_open()){
        int digit;
        file>>digit;
        return digit;
    } else return -1;
}

const char FILE_PATH[] =
    "C:\\Users\\nikol\\Documents\\"
    "GitHub\\Object-oriented_programming_FMI_2023\\"
    "Seminars\\Sem.02\\Pract.02\\"
    "result.txt";

int main(){

    int a,b,c;
    std::cin>>a>>b>>c;

    std::ofstream fileToPrint(FILE_PATH);

    printInFileDigit(fileToPrint,a+b+c);
    fileToPrint<<std::endl;
    printInFileDigit(fileToPrint,a*b*c);

    fileToPrint.close();

    std::ifstream fileToRead(FILE_PATH);

    std::cout<<"\n"<<std::abs(readDigitFromFile(fileToRead) - readDigitFromFile(fileToRead));

    fileToRead.close();

}

