#pragma once

#include <iostream>
#include "Complex.hpp"


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


	Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c);
	friend void saveToPPM(const Fractal&, const char* );
};


