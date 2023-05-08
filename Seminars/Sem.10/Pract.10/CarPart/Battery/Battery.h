#pragma once
#include "../CarPart.h"

class Battery: protected CarPart{

    unsigned short capacity = 0;
    char* id = new char[1];

    void copyFrom(const Battery& other);
    void free();

public:

    Battery(const char* _id, unsigned int id);
    Battery(const char* _id,unsigned short capacity, unsigned int id);
    Battery(const char* _id,unsigned short capacity, unsigned int id,const char* brand,const char* description);
    Battery(const char* _id);
    Battery(const Battery& other);
    Battery(Battery&& other);

    const char * getId() const;
    unsigned short getCapacity() const;
    unsigned short setCapacity(const unsigned short _capacity);
    Battery& setId(const char * _id);

    Battery& operator=(const Battery& other);
    Battery& operator=( Battery&& other);

    friend std::ostream& operator<<(std::ostream& os,const Battery& battery);

};