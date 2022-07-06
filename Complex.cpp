#include <iostream>
#include "Complex.hpp"
using namespace std;

~Complex()  {

}

Complex() : imag(0), real(0) {

}

Complex(const Complex&) : imag(0), real(0) {

}

Complex(double, double) : imag(0), real(0){

}

double& operator[](const char*){
}