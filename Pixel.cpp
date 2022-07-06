#include <iostream>
#include "Pixel.hpp"
#include "Fractal.hpp"

using namespace std;

~Pixel() {

}
const unsigned int& operator[](const char*){

}

Pixel() : blue(0), green(0), red(0) {

}

Pixel(const Pixel&) : blue(0), green(0), red(0) {

}

Pixel(unsigned int, unsigned int, unsigned int) : blue(0), green(0), red(0) {

}