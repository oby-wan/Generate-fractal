#include "Pixel.hpp"

Pixel::Pixel() :red(0), green(0), blue(0) {}

const unsigned int& Pixel::operator[](const char* a) const
{
	if (strcmp(a, "red") == 0)
		return red;
	else if (strcmp(a, "green") == 0)
		return green;
	else if (strcmp(a, "blue") == 0)
		return blue;
	else
		exit(1);
}

Pixel::~Pixel()
{
	cout << "pixel destructor called" << endl;
}

Pixel::Pixel(const Pixel& a) : red(0), green(0), blue(0)
{
	cout << "Copy constructor called" << endl;
	red = a.red;
	green = a.green;
	blue = a.blue;

}

Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) : red(r), green(g), blue(b)
{
	cout << "3-arg constructor called" << endl;
}


ofstream& operator << (ofstream& os, const Pixel& a)
{

	os << a["red"] << " " << a["green"] << " " << a["blue"] << " ";

	return os;
}

