#include <iostream>
#include "Pixel.hpp"
#include "Fractal.hpp"

using namespace std;

Pixel::~Pixel() {
	cout << "pixel destructor called" << endl;
}
const unsigned int& Pixel::operator[](const char* c){
	if (strcmp(c, "red") == 0)
		return red;
	else if (strcmp(c, "blue") == 0)
		return blue;
	else if (strcmp(c, "green") == 0)
		return green;
	else {
		cout << "> ERROR: invalid index. Exiting..." << endl;
		exit(1);
	}
}

Pixel::Pixel() : blue(0), green(0), red(0) {
	cout << "default constructor called" << endl;
}

Pixel::Pixel(const Pixel& p) : blue(p.blue), green(p.green), red(p.red) {
	cout << "Copy constructor called" << endl; 
}

Pixel::Pixel(unsigned int blue, unsigned int green, unsigned int red) : blue(0), green(0), red(0) {
	cout << "3-arg constructor called" << endl;
	grid = f.cols * f.rows;

	for (unsigned int i = 0; i < f.cols; i++) {
		(*this)[i] = Pixel(blue[i], green[i], red[i]);
	}
	return *this;

}
unsigned int Pixel::converToPixel(unsigned int color) {
	Pixel* convert;

	for (int i = 0; i < cols; i++) {
		(*this)[i] = Pixel(red[i], blue[i], green[i]);
	}
	return *this;
}

unsigned int operator<<(ofstream& file, Pixel& p) {

	ofstream outfile(file);
	file << p.red << p.green << p.blue;
	return file;

}
