#include <iostream>
#include <fstream>

struct Student{
    char name[10];
    char family[10];
    char facNum[15];
    char Email [30];
};

int linesCounter(std::ifstream& ifs){
    int counter =0;
    while (! ifs.eof()){
        char buff[256];
        ifs.getline(buff,256);
        counter++;

    }
    return counter;
}

void getInfo(std::ifstream& ifs,Student* students){

    while (!ifs.eof()){
        char buff[128];
        ifs.getline(buff,128);

    }

}

void separateLine(Student* students,char buff[128]){

    for(int i=0,j=0;buff[i]!= '\0';i++){
        if(buff[i]==',')
        char temp[30];
    }
}

int main(){
    std::ifstream ifs("students.csv");
    int size= linesCounter(ifs);
    Student* students = new Student[size];



    delete[] students;
    return 0;
}