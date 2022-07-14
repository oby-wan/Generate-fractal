#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pixel
{
private:
	unsigned int red;
	unsigned int green;
	unsigned int blue;
public:
	Pixel();
	~Pixel();
	Pixel(const Pixel&);
	Pixel(unsigned int, unsigned int, unsigned int);
	const unsigned int& operator[](const char*) const;
	friend ofstream& operator<<(ofstream& , const Pixel& );

};
