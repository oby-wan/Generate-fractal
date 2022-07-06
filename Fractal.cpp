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

Fractal(const Fractal&) : cols(), rows(), maxltr(0), grid(nullptr), type(nullptr) {

}

Fractal(Fractal&&) {
	cout << "Move constructor called..." << endl;
}

Fractal(unsigned int, unsigned int, char) : cols(), rows(), maxltr(0), grid(nullptr), type(nullptr)

}

const Fractal& operator=(const Fractal&) {
	cout << "Copy constructor called" << endl;
}

Fractal& operator=(Fractal&&) {
	cout << "Move assignment operator called..." << endl;
}

unsigned int determinePixelColor(Complex, Complex) {

}

void makeJuliaFractal() {
	cout << "Now creating the Julia patterns" << endl;
}

void makeMandelbrotFractal() {
	cout << "Now creating the Mandelbrot patterns" << endl;
}

