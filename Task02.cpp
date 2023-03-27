#include "ComplexNumber/ComplexNumber.h"

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
