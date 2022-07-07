#pragma once

#include <iostream>
using namespace std;

class Pixel {
protected:
	unsigned int blue;
	unsigned int green;
	unsigned int red;

public:
	~Pixel();
	const unsigned int& operator[](const char*);
	Pixel();
	Pixel(const Pixel&);
	Pixel(unsigned int, unsigned int, unsigned int);
	Pixel& convertToPixel(unsigned int color);

	friend unsigned int operator<<(ofstream& file, Pixel&);
};
