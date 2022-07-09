#pragma once

#include <iostream>
#include "Complex.hpp"
#include "Pixel.hpp"

class Fractal {

protected:
	unsigned int cols;
	unsigned int rows;
	Pixel** grid;
	unsigned int maxIter;
	char type;
	unsigned int determinePixelColor(Complex, Complex);
	void makeJuliaFractal();
	void makeMandelbrotFractal();

public:
	~Fractal();
	Fractal();
	Fractal(const Fractal&);
	Fractal(Fractal&&);
	Fractal(unsigned int, unsigned int, char);
	const Fractal& operator=(const Fractal&);
	Fractal& operator=(Fractal&&);
	Pixel convertToPixel(unsigned int color);

	friend void saveToPPM(const Fractal&, const char*);
};
