//
// Created by Mihail Tsankov on 23.03.23.
//

#include "secret.h"
#include <cstring>

void Secret::setTaskUnsafe(const char* task){
    strcpy(this->task, task);
}

const char* Secret::getTaskUnsafe() const {
    return this->task;
}

void  Secret::setPasswordUnsafe(const char* password){
    strcpy(this->password, password);
}

const char*  Secret::setPasswordUnsafe() const{
    return this->password;
}

void  Secret::ensureActionIsProtected(const char* password, const char* data, void (Secret::*action)(const char*)) {
    if(strcmp(this->password,password) != 0){
        this->failedLogIns++;
        return;
    }

    (*this.*action)(data);
}

const char*  Secret::ensureActionIsProtected(const char* password, const char* (Secret::*action)()const) const{
    if(strcmp(this->password,password) != 0){
        this->failedLogIns++;
        return nullptr;
    }

    return (*this.*action)();
}


int  Secret::getLoginFails() const{
    return this->failedLogIns;
}

const char*  Secret::getTask(const char* password)const{
    return ensureActionIsProtected(password, &Secret::getTaskUnsafe);
}

void  Secret::setTask(const char* newTask, const char* password){
    ensureActionIsProtected(password, newTask, &Secret::setTaskUnsafe);
}

void  Secret::setPassword(const char* newPassword, const char* password){
    ensureActionIsProtected(password, newPassword, &Secret::setPasswordUnsafe);
}