#pragma once
#include <iostream>
using namespace std;

class Pixel
{
private:
	unsigned int blue;
	unsigned int green;
	unsigned int red;
public:
	Pixel();
	~Pixel();
	Pixel(const Pixel&);
	Pixel(unsigned int, unsigned int, unsigned int);
	const unsigned int& operator[](const char*);
	friend ofstream& operator<<(ofstream&, Pixel&);
};
