#include "Complex.h"
#include <string>

using namespace std;


Complex::Complex(double defReal, double defImag) 
{
	real = defReal;
	imaginary = defImag;
}

double Complex::GetReal() const
{
	return real;
}

double Complex::GetImaginary() const
{
	return imaginary;
}

void Complex::SetReal(double newReal)
{
	real = newReal;
}

void Complex::SetImaginary(double newImag)
{
	imaginary = newImag;
}

void Complex::ConvertStringToComplex(string& complexString)
{
	complexString += to_string(real) += "+";
	complexString += to_string(imaginary) += "i";
}



ostream& operator<<(ostream & out, const Complex & rhsComplex)
{
	out << rhsComplex.real << '+' << rhsComplex.imaginary << 'i';
}

istream& operator>>(istream& in, Complex& rhsComplex)
{
	double realNum, imagNum;
	char plus, imagLetter;

	in >> realNum >> plus >> imagNum >> imagLetter;

	rhsComplex.real = realNum;
	rhsComplex.imaginary = imagNum;
}

Complex operator+(const Complex& lhsComplex, const Complex& rhsComplex)
{
	double realNum, imagNum;

	realNum = lhsComplex.real + rhsComplex.real;
	imagNum = lhsComplex.imaginary + rhsComplex.imaginary;

	Complex tempComplex(realNum, imagNum);
	return tempComplex;
}

Complex operator-(const Complex& lhsComplex, const Complex& rhsComplex)
{
	double realNum, imagNum;

	realNum = lhsComplex.real + rhsComplex.real;
	imagNum = lhsComplex.imaginary + rhsComplex.imaginary;

	Complex tempComplex(realNum, imagNum);
	return tempComplex;
}

Complex operator*(const Complex& lhsComplex, const Complex& rhsComplex)
{
	double realNum, imagNum, realL, realR, imagL, imagR;

	realL = lhsComplex.real;
	realR = rhsComplex.real;
	imagL = lhsComplex.imaginary;
	imagR = rhsComplex.imaginary;

	realNum = (realL*realR) - (imagL * imagR);
	imagNum = (realL*imagR) + (realR * imagL);

	Complex tempComplex(realNum, imagNum);
	return tempComplex;
}

Complex operator/(const Complex& lhsComplex, const Complex& rhsComplex)
{
	double realNum, imagNum, realL, realR, imagL, imagR;

	realL = lhsComplex.real;
	realR = rhsComplex.real;
	imagL = lhsComplex.imaginary;
	imagR = rhsComplex.imaginary;

	realNum = ((realL*realR) + (imagL*imagR)) 
		    / ((realR*realR) + (imagR*imagR));

	imagNum = ((imagL*realR) - (realL*imagR))
			/ ((realR*realR) + (imagR*imagR));

	Complex tempComplex(realNum, imagNum);
	return tempComplex;
}

bool operator==(const Complex& lhsComplex, const Complex& rhsComplex)
{
	return ((lhsComplex.real == rhsComplex.real) && (lhsComplex.imaginary == rhsComplex.imaginary));
}