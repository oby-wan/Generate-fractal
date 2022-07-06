#include <iostream>
#include "Complex.hpp"
using namespace std;

~Complex()  {
	cout << "complex destructor called" << endl;
}

Complex() : imag(0), real(0) {
	cout << "default constructor called" << endl;
}

Complex(const Complex& c) : imag(0), real(0) {
	cout << "Copy constructor called" << endl;
}

Complex(double i, double r) : imag(0), real(0){
	cout << "Parameterized constructor called" << endl;
}

double& operator[](const char* c){
}