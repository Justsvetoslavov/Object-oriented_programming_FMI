#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Complex_num {
    int r, i;
};

Complex_num sum_complex_num(const Complex_num &a, const Complex_num &b) {
    Complex_num res{ a.r + b.r, a.i + b.i };
    return res;
}

void print_complex_num(const Complex_num &num) {
    cout << num.r << " + " << num.i << "i\n";
}

int main() {
    Complex_num n1{3, 5}, n2{4, 3};
    print_complex_num(n1);
    Complex_num sum = sum_complex_num(n1, n2);
    print_complex_num(sum);
}
