#include<iostream>
using namespace std;
//Natalia Nakollofski   1MI8000034    GR.1


//Да се създаде структура която представя комплексно число.
//
//Създайте функция, която събира две комплексни числа.
//
//Създайте подходяща функция за извеждане принтиране на комплексни числа




struct complex {
	double real;
	double imaginary;
};

complex sum(const complex& reall, const complex& imaginaryy) {
	return { reall.real + reall.real,imaginaryy.imaginary + imaginaryy.imaginary };
}
void printnumbers(const complex& number) {
	cout << number.real << "+" << number.imaginary << "i" << endl;
}


int main() {
	complex a = { 1.0,2.0 };
	complex b = { 3.0,4.0 };
	complex c = sum(a, b);
	printnumbers(c);

}