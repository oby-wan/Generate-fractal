#include "Complex.hpp"

Complex::Complex() : real(0.0), imag(0.0) {}

Complex::~Complex() {}

Complex::Complex(const Complex& a) : real(a.real), imag(a.imag) {}
Complex::Complex(double a, double b) : real(b), imag(a) {}

double& Complex::operator[](const char* a)
{
	if (strcmp(a, "real") == 0)
		return real;
	else if (strcmp(a, "imag") == 0)
		return imag;
	else
		exit(1);
}
const Complex operator*(const Complex& a, const Complex& b)
{
	Complex x;
	x.real = a.real * b.real - a.imag * b.imag;
	x.imag = a.real * b.imag + a.imag * b.real;
	return x;
}

const Complex operator+(const Complex& a, const Complex& b)
{
	Complex x;
	x.real = (a.real) + (b.real);
	x.imag = (a.imag) + (b.imag);
	return x;
}

double getMagnitudeSquared(const Complex& a)
{
	double c = (a.imag) * (a.imag) + (a.real) * (a.real);
	return c;
}