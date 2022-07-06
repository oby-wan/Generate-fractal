#include <iostream>
#include "Complex.hpp"
using namespace std;

Complex::~Complex()  {
	cout << "complex destructor called" << endl;
}

Complex::Complex() : imag(0), real(0) {
	cout << "default constructor called" << endl;
}

Complex::Complex(const Complex& c) : imag(0), real(0) {
	cout << "Copy constructor called" << endl;
}

Complex::Complex(double z, double c) : imag(0), real(0){
	cout << "Parameterized constructor called" << endl;
}

double& Complex::operator[](const char* c){
}