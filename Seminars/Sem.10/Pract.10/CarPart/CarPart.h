#pragma once
#include <cstring>
#include <iostream>

const int DEFAULT_BRAND_LENGTH  = 8;
const int DEFAULT_DESCRIPTION_LENGTH  = 16;

class CarPart{

    unsigned int id;
    char* brand;
    char* description;

    void copyFrom(const CarPart& other);
    void free();

public:

    CarPart();
    CarPart(unsigned int id);
    CarPart(const CarPart& other);
    CarPart(unsigned int id,const char* brand,const char* description);
    CarPart(CarPart&& other);
    ~CarPart();

    const unsigned int getId() const;
    const char* getBrand() const ;
    const char* getDescription() const;

    CarPart& setId(unsigned int newId);
    CarPart& setBrand(const char * newBrand);
    CarPart& setDescription(const char * newDescription);

    CarPart& operator=(const CarPart& other);
    CarPart& operator=(CarPart&& other);

};
