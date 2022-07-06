#pragma once

#include <iostream>
#include "Complex.hpp"
#include "Fractal.hpp"

class Fractal {

protected:
	unsigned int cols;
	unsigned int rows;
	Pixel** grid;
	unsigned int maxlter;
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


};

