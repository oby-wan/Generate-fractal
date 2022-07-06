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

Fractal(unsigned int c, unsigned int r, char t) : cols(), rows(), maxltr(0), grid(nullptr), type(nullptr){
	cout << "3-arg constructor called" << endl;
}

const Fractal& operator=(const Fractal& f {
	
}

Fractal& operator=(Fractal&& f) {
	cout << "Move assignment operator called..." << endl;
}

unsigned int determinePixelColor(Complex z, Complex c ) {
	unsigned int lengthSquared;
	unsigned iter = 0;

	while (iter < maxIter) {
		iter = iter + 1;
		z *= z;
		z += c;
		lengthSquared = getMagnitudeSquared(z);

		if (lengthSquared > 4.0)
			return iter;
	}
	return maxIter;
}

void makeJuliaFractal() {
	cout << "Now creating the Julia patterns" << endl;
}

void makeMandelbrotFractal() {
	cout << "Now creating the Mandelbrot patterns" << endl;

	Complex z;
	Complex c;
	double stepHeight = 4.0 / rows;
	double step_width = 4.0 / cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; J++) {
			imag[z] = 0.0;
			real[z] = 0.0;
			real[c] = ((double)i * step_height) - 2.0;
			imag[c] = ((double)j * step_height) - 2.0;
			

			unsigned int color = determinePixelColor(z, c);
			grid[i][j] = converToPixel(color);
		}
	}

}

