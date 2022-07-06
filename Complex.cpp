#include <iostream>
#include "Complex.hpp"
using namespace std;

~Complex()  {
	cout << "complex destructor called" << endl;
}

Complex() : imag(0), real(0) {
	cout << "default constructor called" << endl;
}

Complex(const Complex&) : imag(0), real(0) {
	cout << "Copy constructor called" << endl;
}

Complex(double, double) : imag(0), real(0){

}

double& operator[](const char*){
}