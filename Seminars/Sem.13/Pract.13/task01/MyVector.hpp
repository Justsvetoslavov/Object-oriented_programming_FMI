#ifndef TASK02_MYVECTOR_HPP
#define TASK02_MYVECTOR_HPP
#include <iostream>

template<class T>
class MyVector{
    T*data;
    size_t size;
    size_t capacity;

    void copyFrom(const MyVector&other);
    void free();
    void moveFrom(MyVector&&other);
    void resize();

public:
    MyVector();
    explicit MyVector(size_t n);
    MyVector(const MyVector&other);
    MyVector& operator=(const MyVector&other);
    ~MyVector();
    MyVector(MyVector&&other);
    MyVector& operator=(MyVector&& other);
    ////////////////////////////////////////////////

    size_t getSize()const;
    size_t getCapacity()const;
    bool isEmpty()const;
    const T& getFront()const;
    const T& getEnd()const;
    const T& operator [](size_t n)const;
    T& operator [](size_t n);
    MyVector& insert(const T& element);
    //MyVector& insert(const T&element, size_t n);
    MyVector& removeElement(const T& element);
    MyVector& swap(size_t n,size_t n1);

};

template<class T>
T &MyVector<T>::operator[](size_t n) {
    return data[n];
}

template<class T>
const T &MyVector<T>::operator[](size_t n) const {
    return data[n];
}
template<class T>
const T &MyVector<T>::getEnd() const {
    return data[size-1];
}

template<class T>
const T &MyVector<T>::getFront() const {
    return data[0];
}

template<class T>
bool MyVector<T>::isEmpty() const {
    return size==0;
}

template<class T>
size_t MyVector<T>::getSize() const {
    return size;
}

template<class T>
size_t MyVector<T>::getCapacity() const {
    return  capacity;
}

template<class T>
MyVector<T> &MyVector<T>::insert(const T &element) {
    if(size>=capacity){
        resize();
    }

    data[size++]=element;
    return *this;
}

template<class T>
MyVector<T> &MyVector<T>::removeElement(const T &element) {
    if(isEmpty()){
        return *this;
    }
}

template<class T>
MyVector<T> &MyVector<T>::swap(size_t n, size_t n1) {
    T temp= n;
    n=n1;
    n1= temp;
}

///////////////////////////////////////////////////////////////////////////
template<class T>
MyVector<T>::MyVector(): MyVector(1) {}

template<class T>
MyVector<T>::MyVector(size_t n) {
    size=0;
    capacity=n;
    data= new T[capacity];
}

template<class T>
MyVector<T>::MyVector(const MyVector<T> &other) {
    copyFrom(other);
}

template<class T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other) {
    if(this!=&other){
        free();
        copyFrom(other);
    }
    return *this;
}

template<class T>
MyVector<T>::~MyVector() {
    free();
}

template<class T>
MyVector<T>::MyVector(MyVector<T> &&other) {
    moveFrom(std::move(other));
}

template<class T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) {
    if(this!=&other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}


////////////////////////////////////////////////////////////////////
template<class T>
void MyVector<T>::copyFrom(const MyVector<T> &other) {
    size=other.size;
    capacity=other.capacity;
    data = new T[capacity];
    for(int i=0;i<size;i++){
        data[i]=other.data[i];
    }
}

template<class T>
void MyVector<T>::moveFrom(MyVector<T> &&other) {
    size=other.size;
    capacity=other.capacity;
    data=other.data;
    other.data= nullptr;
}

template<class T>
void MyVector<T>::free() {
    delete[]data;
}

template<class T>
void MyVector<T>::resize() {
    capacity*=2;
    T* temp = new T[capacity];
    for(int i=0;i<size;i++) {
        temp[i]=data[i];
    }
    delete [] data;
    data=temp;
}


#endif //TASK02_MYVECTOR_HPP
