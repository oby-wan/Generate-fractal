#include <iostream>
#include "Complex.hpp"
using namespace std;

Complex::~Complex() 
{
	cout << "complex destructor called" << endl;
}

Complex::Complex() : imag(0.0), real(0.0)
{
	cout << "default constructor called" << endl;
}

Complex::Complex(const Complex& a) : imag(a.imag), real(a.real)
{
	cout << "Copy constructor called" << endl;

}

Complex::Complex(double a, double b) : imag(a), real(b)
{
	cout << "Parameterized constructor called" << endl;
}

double& Complex::operator[](const char* a)
{
	if (strcmp(a, "real") == 0)
		return real;
	else if (strcmp(a, "imag") == 0)
		return imag;
	else
		exit(1);
}

const Complex Complex::operator*(const Complex& a, const Complex& b)
{
	Complex x;
	x.real = a.real * b.real - a.imag * b.imag;
	x.imag = a.real * b.imag + a.imag * b.real;
	return x;
}

const Complex Complex::operator+(const Complex& a, const Complex& b)
{
	Complex x;
	x.imag = (a.imag) + (b.imag);
	x.real = (a.real) + (b.real);
	return x;
}

double Complex::getMagnitudeSquared(const Complex& a)
{
	double c = (a.imag)*(a.imag) + (a.real)*(a.real);
	return c;
}
