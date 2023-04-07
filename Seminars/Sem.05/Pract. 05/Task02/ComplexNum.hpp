#pragma once
class ComplexNum
{
private:
	double a;
	double b;
public:
	ComplexNum() = default;

	ComplexNum(double a, double b);

	ComplexNum(const ComplexNum& other) = default;

	void setA(double a);

	void setB(double b);

	double getA() const;

	double getB() const;

	bool isEqual(const ComplexNum& cocomplexNum1, const ComplexNum& complexNum2);

	ComplexNum add(const ComplexNum& cocomplexNum1, const ComplexNum& complexNum2);

	ComplexNum substract(const ComplexNum& complexNum1, const ComplexNum& complexNum2);

	ComplexNum multiply(const ComplexNum& cocomplexNum1, const ComplexNum& complexNum2);
	
	void conjugate(ComplexNum& complexNum);

	void getConjugated(ComplexNum& complexNum);

	void print(const ComplexNum& complexNum);

	~ComplexNum() = default;
};