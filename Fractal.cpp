#include <iostream>
#include "Complex.hpp"
#include "Fractal.hpp"

using namespace std;

~Fractal() {																									
	cout << "fractal destructor called" << endl;
}

Fractal() : cols(), rows(), maxltr(0), grid(nullptr), type(nullptr) {
	cout << "default constructor called" << endl;
}

Fractal(const Fractal& f) : cols(), rows(), maxltr(0), grid(nullptr), type(nullptr) {
	cout << "Copy constructor called" << endl;
}

Fractal(Fractal&& f) {
	cout << "Move constructor called..." << endl;
}

Fractal(unsigned int c, unsigned int r, char t) : cols(), rows(), maxltr(0), grid(nullptr), type(nullptr)
	cout << "3-arg constructor called" << endl;
}

const Fractal& operator=(const Fractal& f {
	
}

Fractal& operator=(Fractal&& f) {
	cout << "Move assignment operator called..." << endl;
}

unsigned int determinePixelColor(Complex i, Complex r ) {

}

void makeJuliaFractal() {
	cout << "Now creating the Julia patterns" << endl;
}

void makeMandelbrotFractal() {
	cout << "Now creating the Mandelbrot patterns" << endl;
}

