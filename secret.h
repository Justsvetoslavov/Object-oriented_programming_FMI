//
// Created by Mihail Tsankov on 23.03.23.
//

#pragma once
#include <cstring>

class Secret{
private:
    char* task;
    char password[20];
    mutable int failedLogIns ;

    void setTaskUnsafe(const char* task);

    const char* getTaskUnsafe() const ;

    void setPasswordUnsafe(const char* password);

    const char* setPasswordUnsafe() const;

    void ensureActionIsProtected(const char* password, const char* data, void (Secret::*action)(const char*));

    const char* ensureActionIsProtected(const char* password, const char* (Secret::*action)()const) const;

public:
    Secret(const char* task, const char* password){
        this->task = new char [strlen(task) + 1];
        this->setTaskUnsafe(task);
        this->setPasswordUnsafe(password);
    }

    int getLoginFails() const;

    const char* getTask(const char* password)const;

    void setTask(const char* newTask, const char* password);

    void setPassword(const char* newPassword, const char* password);


    ~Secret(){
        delete task;
    }

};