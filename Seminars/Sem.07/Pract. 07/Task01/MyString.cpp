#include "MyString.h"

MyString::MyString(const char *str) : size(strlen(str)){

    this->data = new char[size + 1];
    strcpy(this->data, str);

}
MyString::MyString(const MyString &other){
     copyFrom(other);
}

void MyString::free() {delete[] data;}
void MyString::copyFrom(const MyString &other) {

    size = other.size;

    data = new char[size + 1];
    strcpy(data,other.data);

}
const char* MyString::c_str() {
    return data;
}
size_t MyString::length() const {
    return size;
}

bool MyString::empty() const {
    if(size == 0)return true;
    return false;
}
size_t MyString::compare(const MyString &other) {

    if(this->empty() or other.empty())
        return size - other.length();

    return strcmp(data,other.data);
}

MyString& MyString::clear() {

    free();
    data = new char[1];
    data[0] = 0;

    return *this;

}
MyString& MyString::append(const MyString &other) {
    *this += other;
    return *this;
}
MyString& MyString::append(const char *str) {
    *this+=str;
    return *this;
}

MyString& MyString::operator=(const MyString &other) {

    if(this != &other) {

        free();
        copyFrom(other);

    }

    return *this;

}

MyString& MyString::operator+=(const MyString &other) {

    char* result = new char[length() + other.length() + 1];
    strcpy(result, data);
    strcat(result, other.data);

    delete[] data;
    data = result;
    size += other.length();

    return *this;

}

MyString operator+(const MyString &lhs,const MyString &rhs ) {

    MyString res(lhs);
    res+=rhs;
    return res;

}

bool operator==(const MyString &lhs,const MyString &rhs){

    if(strcmp(lhs.data,rhs.data) == 0)return true;
    return false;

}
bool operator!=(const MyString &lhs, const MyString &rhs) {
    return !(lhs==rhs);
}
bool operator>(const MyString &lhs, const MyString &rhs) {
    if(lhs.size > rhs.size)return true;
    return false;
}
bool operator<(const MyString &lhs, const MyString &rhs) {
    return !(lhs>rhs);
}
bool operator>=(const MyString &lhs, const MyString &rhs) {

    return (lhs.size > rhs.size | lhs.size == rhs.size);
}
bool operator<=(const MyString &lhs, const MyString &rhs) {

    return (lhs.size < rhs.size | lhs.size == rhs.size);
}

char MyString::operator[](size_t i) {
    return data[i];
}
char &MyString::operator[](size_t i) const {
    return data[i];
}

std::ostream& operator<<(std::ostream &os, const MyString &string) {
    os << string.data;
    return os;
}
std::istream &operator>>(std::istream &is, MyString &string) {

    char* str = new char[8];
    is >> str;
    string = str;
    delete[] str;
    return is;

}

MyString::~MyString() {free();/*std::cout<<"\n~MyString() "<<*this<<"\n"*/;}

//features
MyString operator*(const MyString &lhs,size_t num) {
    MyString result;
    while(num--)result+=lhs;
    return result;
}
MyString operator*(size_t num, const MyString &rhs) {
    return rhs * num;
}


