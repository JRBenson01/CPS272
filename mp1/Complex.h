#pragma once

#include <iostream>

using namespace std;

class Complex {
	friend ostream& operator<<(ostream& out, const Complex& rhsComplex);
	friend istream& operator>>(istream& in, Complex& rhsComplex);
	friend Complex operator+(const Complex& lhsComplex, const Complex& rhsComplex);
	friend Complex operator-(const Complex& lhsComplex, const Complex& rhsComplex);
	friend Complex operator*(const Complex& lhsComplex, const Complex& rhsComplex);
	friend Complex operator/(const Complex& lhsComplex, const Complex& rhsComplex);
	friend bool operator==(const Complex& lhsComplex, const Complex& rhsComplex);
private:
	double real;
	double imaginary;
public:
	Complex(double defReal = 0.0, double defImag = 0.0);
	double GetReal() const;
	double GetImaginary() const;
	void SetReal(double newReal);
	void SetImaginary(double newImag);
	void ConvertStringToComplex(string& complexString);
};

