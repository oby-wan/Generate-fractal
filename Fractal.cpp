#include <iostream>
#include "Complex.hpp"
#include "Fractal.hpp"

using namespace std;

Fractal::~Fractal() {																									
	cout << "fractal destructor called" << endl;

	delete[] grid;
	grid = nullptr;
}

Fractal::Fractal() : cols(), rows(), maxIter(0), grid(nullptr), type(nullptr) {
	cout << "default constructor called" << endl;
}


Fractal::Fractal(const Fractal& f) : cols(f.cols), rows(f.rows), maxIter(f.MaxIter), grid(f.grid), type(f.type) {
	cout << "Copy constructor called" << endl;
}


Fractal::Fractal(Fractal&& f) {
	cout << "Move constructor called..." << endl;
}


Fractal::Fractal(unsigned int c, unsigned int r, char t) : cols(), rows(), maxItr(0), grid(nullptr), type(nullptr){
	cout << "3-arg constructor called" << endl;


}

const Fractal& Fractal::operator=(const Fractal& f {
	
}

Fractal& Fractal::operator=(Fractal&& f) {
	cout << "Move assignment operator called..." << endl;
}

unsigned int Fractal::determinePixelColor(Complex z, Complex c ) {
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

void Fractal::makeJuliaFractal() {
	cout << "Now creating the Julia patterns" << endl;
}

void Fractal::makeMandelbrotFractal() {
	cout << "Now creating the Mandelbrot patterns" << endl;

	Complex z;
	Complex c;
	double stepHeight = 4.0 / rows;
	double stepWidth = 4.0 / cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			z.imag = 0.0;
			z.real = 0.0;
			c.real = ((double)i * stepHeight) - 2.0;
			c.imag = ((double)j * stepWidth) - 2.0;
			

			unsigned int color = determinePixelColor(z, c);
			grid[i][j] = converToPixel(color);
		}
	}

}



Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c) {

}

void saveToPPM() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

		}
	}
}