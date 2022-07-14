#include <iostream>
#include "Complex.hpp"
#include "Fractal.hpp"
#include "Pixel.hpp"
using namespace std;

Fractal testMoveConstructor(unsigned int rows, unsigned int cols, char c) {
	Fractal temp = Fractal(rows, cols, c);

	return temp;
}

int main()
{

	Fractal m1(768U, 1024U, 'm'), j1(768U, 1024U, 'j'), m2, j2;
	saveToPPM(m1, "mandelbrot.ppm");
	saveToPPM(j1, "julia.ppm");
	m2 = Fractal(m1);
	j2 = testMoveConstructor(600U, 800U, 'j');
	Fractal j3(768U, 1024U, 'l');
	saveToPPM(j2, "julia_2.ppm");
	return 0;
}

/*
Group Members

Parivash Gholipourganjgah
Bailey Holmes
Toby Hosseinnia
Raffi Macaraig

*/