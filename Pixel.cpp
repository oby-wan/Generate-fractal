#include <iostream>
#include "Pixel.hpp"
#include "Fractal.hpp"

using namespace std;

~Pixel() {
	cout << "pixel destructor called" << endl;
}
const unsigned int& operator[](const char*){

}

Pixel() : blue(0), green(0), red(0) {
	cout << "default constructor called" << endl;
}

Pixel(const Pixel&) : blue(0), green(0), red(0) {
	cout << "Copy constructor called" << endl; 

}

Pixel(unsigned int, unsigned int, unsigned int) : blue(0), green(0), red(0) {
	cout << "3-arg constructor called" << endl;
}