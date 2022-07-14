#pragma once

#include <iostream>
#include "Complex.hpp"
#include "Pixel.hpp"
#include <string>


class Fractal {

protected:
	unsigned int cols;
	unsigned int rows;
	Pixel** grid;
	unsigned int maxIter;
	char type;
	unsigned int determinePixelColor(Complex, Complex);
	void makeJuliaFractal();
	void makeJuliaFractal(double, double, int);
	void makeMandelbrotFractal();

public:
	~Fractal();
	Fractal();
	Fractal(const Fractal&);
	Fractal(Fractal&&) noexcept;
	Fractal(unsigned int, unsigned int, char);
	const Fractal& operator=(const Fractal&);
	Fractal& operator=(Fractal&&);
	friend void saveToPPM(const Fractal&, string);
	Pixel converToPixel(unsigned int color);
};

