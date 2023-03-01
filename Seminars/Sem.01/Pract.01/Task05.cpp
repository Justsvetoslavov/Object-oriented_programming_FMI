#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct Complex {
    double real;
    double imag;
};

Complex sumComplex(Complex z1, Complex z2) {
    Complex result;
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

void printComplex(const Complex& z) {
    cout << z.real << "+" << z.imag << "i" << endl;
}

int main()
{
    Complex z1;
    cin >> z1.real;
    cin >> z1.imag;
    Complex z2;
    cin >> z2.real;
    cin >> z2.imag;
    Complex result = sumComplex(z1, z2);
    printComplex(result);
}

