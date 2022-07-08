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

Pixel::Pixel(unsigned int b, unsigned int g, unsigned int r) : blue(b), green(g), red(r) {
	cout << "3-arg constructor called" << endl;
}

ofstream& operator<<(ofstream& os, Pixel& p) {

	os << p["red"] << " " << p["green"] << " " << p["blue"] << " ";

	return os;

}
