#include <iostream>
#include <cmath>

class ComplexNumber {
    int real, imaginary;
public:
    ComplexNumber() {
        real = 0;
        imaginary = 0;
    }

    ComplexNumber(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    bool isEqual(const ComplexNumber &num) const {
        if (this->real == num.real && this->imaginary == num.imaginary)
            return true;
        return false;
    }

    void add(const ComplexNumber &num) {
        this->real += num.real;
        this->imaginary += num.imaginary;
    }

    void minus(const ComplexNumber &num) {
        this->real -= num.real;
        this->imaginary -= num.imaginary;
    }

    void multiply(const ComplexNumber &num) {
        int oldReal = this->real;
        this->real = this->real * num.real - this->imaginary * num.imaginary;
        this->imaginary = oldReal * num.imaginary + this->imaginary * num.real;
    }

    void conjugate() {
        this->imaginary *= -1;
    }

    ComplexNumber &operator=(const ComplexNumber &num) {
        if (this != &num) {
            this->real = num.real;
            this->imaginary = num.imaginary;
        }
        return *this;
    }

    ComplexNumber getConjugated() const{
        ComplexNumber res = *this;
        res.conjugate();
        return res;
    }

    void print() const {
        std::cout << this->real << (this->imaginary >= 0 ? " + " : " - ")
                  << (this->imaginary >= 0 ? this->imaginary : this->imaginary * -1) << "i\n";
    }
};

int main() {
    ComplexNumber ex1(3, 1);
    ComplexNumber ex2(2, 1);
    ex1.multiply(ex2);
    ex1.add(ex2);
    ex1.conjugate();
    ex2 = ex1.getConjugated();
    ex2.print();
    ex2 = ex1;
    ex2.print();
    std::cout << ex2.isEqual(ex1);
}
