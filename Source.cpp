#include <iostream>

using namespace std;


int main()
{
	Fractal m1(768U, 1024U, 'm'), j1(768U, 1024U, 'j'), m2, j2;
	saveToPPM(m1, "mandelbrot.ppm");
	saveToPPM(j1, "julia.ppm");
	m2 = Fractal(m1);
	j2 = testMoveConstructor(600U, 800U, 'j');
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