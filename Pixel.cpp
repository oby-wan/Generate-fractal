#include "Pixel.hpp"
#include "Fractal.hpp"

Pixel::Pixel():red(0),green(0),blue(0)
{
	cout << "default constructor called" << endl;
}

Pixel::~Pixel() 
{
	cout << "pixel destructor called" << endl;
}

Pixel::Pixel(const Pixel& a) : red(a.red) , blue(a.blue), green(a.green)
{
	cout << "Copy constructor called" << endl; 
}

Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) : red(r), blue(b), green(g)
{
	cout << "3-arg constructor called" << endl;
}

const unsigned int& Pixel::operator[](const char* a)
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

ofstream& operator << (ofstream& os, const Pixel& p)
{
	os << p["red"] << " " <<  p["green"] << " " << p["blue"] << " ";
	return os;	
} 
