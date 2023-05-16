## Шаблони

Функция, която работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция. <br />
Kлас, който работи не с променливи от някакъв дефиниран тип, а с абстрактни променливи, се нарича шаблонен клас. <br />

```c++
#include <iostream>

template <typename T>
T sum(const T& a,const T& b) {
    return a + b;
}

int main() {
    int a = 4;
    int b = 9;
    std::cout << sum<int>(a, b) << std::endl;

    double c = 3.14;
    double d = 4.5;
    std::cout << sum<double>(c, d) << std::endl;
	
    return 0;
}
```
Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

**Задача 1: Stack**
Релизирайте структурата от данни [стек(Stack)](https://www.guru99.com/stack-in-cpp-stl.html). <br />
![enter image description here](https://www.softwaretestinghelp.com/wp-content/qa/uploads/2019/06/pictorial-representation-of-stack.png)
<br />

**Пример**:

```c++
int main() {
   Stack st; //Default constructor

   for(size_t i = 0; i < 1000; ++i) {
        st.push(i); // Add element to the stack
   }

   Stack st1 = st; //Copy constructor 
   Stack st2; // Default constructor
   st2 = st1; // Copy assignment operator

   while (!st2.empty()) { // Until stack is not empty
         std::cout << st2.pop() << ' '; //remove element and print it
   }

   std::cout << std::endl;

   return 0;
}
```
