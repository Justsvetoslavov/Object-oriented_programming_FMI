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
        if(name == nullptr){
            copyString(this->name,"");
        }
        copyString(this->name,name);
    }
    char* getName(char*name){
        copyString(name,this->name);
    }

    void setAge(int age){
        if(age<18){
            age=18;
        }
        this->age=age;
    }
    int getAge(){
        return age;
    }

    void setInter(int inter){
        if(inter<0){
            inter=0;
        }
        this->internship=inter;
    }
    int getInter(){
        return internship;
    }
};