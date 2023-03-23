#include <iostream>

char* copyString(char *arr,char* from){

    for(int i=0;from[i]!='\0';i++){
        arr[i]=from[i];
    }
    return arr;
}

class Teacher{
    char name[30];
    int age;
    int internship;
public:

    Teacher(char* name, int age, int inter){
        setName(name);
        setAge(age);
        setInter(inter);
    }
    void setName( char*name){
        copyString(this->name,name);
    }
    char* getName(char*name){
        copyString(name,this->name);
    }

    void setAge(int age){
        this->age=age;
    }
    int getAge(){
        return age;
    }

    void setInter(int inter){
        this->internship=inter;
    }
    int getInter(){
        return internship;
    }
};