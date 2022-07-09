#include <iostream>
#include "Complex.hpp"

using namespace std;

Complex::Complex() : imag(0.0), real(0.0)
{
	// doesn't need cout statement
}

Complex::Complex(const Complex& a) : imag(a.imag), real(a.real)
{
	// doesn't need cout statement
}

Complex::Complex(double a, double b) : imag(a), real(b)
{
	// doesn't need cout statement
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

	x.imag = (a.imag) + (b.imag);
	x.real = (a.real) + (b.real);

	return x;
}

double getMagnitudeSquared(const Complex& a)
{
	double squaredMag = (a.imag * a.imag) + (a.real * a.real);

	return squaredMag;
}

Complex::~Complex()
{
	// doesn't need cout statement
}
