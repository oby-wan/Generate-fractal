#pragma once
#include <iostream>


class Complex{

protected:
	double imag;
	double real;

public:
	~Complex();
	Complex();
	Complex(const Complex&);
	Complex(double, double);
	double& operator[](const char*);

}