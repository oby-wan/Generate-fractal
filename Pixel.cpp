#include <iostream>
#include "Pixel.hpp"
#include "Fractal.hpp"

using namespace std;

Pixel::~Pixel() {
	cout << "pixel destructor called" << endl;
}
const unsigned int& Pixel::operator[](const char* c){

}

Pixel::Pixel() : blue(0), green(0), red(0) {
	cout << "default constructor called" << endl;
}

Pixel::Pixel(const Pixel& p) : blue(0), green(0), red(0) {
	cout << "Copy constructor called" << endl; 

}

Pixel::Pixel(unsigned int blue, unsigned int green, unsigned int red) : blue(0), green(0), red(0) {
	cout << "3-arg constructor called" << endl;
}