#include <iostream>
#include "Complex.hpp"
#include "Pixel.hpp"
#include "Fractal.hpp"
#include "fstream"
using namespace std;

Fractal::Fractal() : cols(0), rows(0), grid(nullptr), maxIter(512), type(' ')
{
	cout << "> Default constructor called" << endl;
}

Fractal::Fractal(const Fractal& a) : cols(0), rows(0), grid(nullptr), maxIter(0), type(' ')
{
	cout << "> Copy constructor called" << endl;

	rows = a.rows;
	cols = a.cols;
	type = a.type;
	maxIter = a.maxIter;

	grid = new Pixel* [rows];
	
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new Pixel[cols];

		for (int j = 0; j < cols; j++)
			grid[i][j] = a.grid[i][j];
	}
}

Fractal::Fractal(Fractal&& a) : cols(0), rows(0), grid(nullptr), maxIter(0), type(' ')
{
	cout << "> Move constructor called" << endl;

	if ((a.type != 'm' && a.type != 'j'))
	{
		cout << "ERROR: Invalid type, please choose a type of either 'm' or 'j'" << endl;
		exit(1);
	}

	type = a.type;
	rows = a.rows;
	cols = a.cols;
	maxIter = a.maxIter;
	grid = a.grid;
	a.grid = nullptr;
}

Fractal::Fractal(unsigned int a, unsigned int b, char c) : cols(0), rows(0), grid(nullptr), maxIter(512), type(' ')
{
	cout << "> 3-arg constructor called" << endl;

	rows = a;
	cols = b;
	type = c;
	
	grid = new Pixel * [rows];

	for (int i = 0; i < rows; i++)
		grid[i] = new Pixel[cols];
}

const Fractal& Fractal::operator=(const Fractal& a)
{
	cout << "> Fractal assignment operator called" << endl;

	cols = a.cols;
	rows = a.rows;
	type = a.type;
	maxIter = a.maxIter;

	if (this != &a)
	{
		if (grid != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] grid[i];
				grid[i] = nullptr;
			}
			delete[] grid;
		}
			
		grid = new Pixel * [rows];
		for (int i = 0; i < rows; i++)
		{
			grid[i] = new Pixel[cols];
			for (int j = 0; j < cols; j++)
				grid[i][j] = a.grid[i][j];
		}
	}

	return *this;
}

Fractal& Fractal::operator=(Fractal&& a)
{
	cout << "> Move assignment operator called" << endl;

	if (this != &a)
	{
		swap(cols, a.cols);
		swap(rows, a.rows);
		swap(type, a.type);
		swap(maxIter, a.maxIter);
		swap(grid, a.grid);
	}

	return *this;
}

Fractal::~Fractal()
{
	cout << "> Destructor called" << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] grid[i];
		grid[i] = nullptr;
	}

	delete[] grid;
	grid = nullptr;
}

unsigned int Fractal::determinePixelColor(Complex z, Complex c)
{
	double lengthSquared;
	int iter = 0;
	while (iter < maxIter)
	{
		iter = iter + 1;
		z = z * z;
		z = z + c;
		lengthSquared = getMagnitudeSquared(z);
		if (lengthSquared > 4.0)
			return iter;
	}
	return maxIter;
}

void Fractal::makeMandelbrotFractal()
{
	cout << "> Now creating the Mandelbrot patterns..." << endl;

	Complex Z, C;
	double step_height = 4.0 / (double)rows;
	double step_width = 4.0 / (double)cols;

	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			Z["imag"] = 0.0;
			Z["real"] = 0.0;
			C["real"] = ((double)j * step_height) - 2.0;
			C["imag"] = ((double)k * step_width) - 2.0;

			unsigned int Color = determinePixelColor(Z, C);
			grid[j][k] = converToPixel(Color);
		}
	}
}

void Fractal::makeJuliaFractal()
{
	cout << "> Now creating the Julia patterns..." << endl;

	Complex Z, C;
	double step_height = 4.0 / (double)rows;
	double step_width = 4.0 / (double)cols;

	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < cols; k++)
		{
			Z["imag"] = ((double)k * step_width) - 2.0;
			Z["real"] = ((double)j * step_height) - 2.0;
			C["real"] = 1.0;
			C["imag"] = 1.0;

			unsigned int Color = determinePixelColor(Z, C);
			grid[j][k] = converToPixel(Color);
		}
	}
}

Fractal Fractal::testMoveConstructor(unsigned int rows, unsigned int cols, char c)
{
	Fractal temp = Fractal(rows, cols, c);

	return temp;
}

void saveToPPM(const Fractal& f, const char* fn)
{
	cout << "> Saving Fractal Object to ASCII File..." << endl;

	ofstream outfile(fn);

	outfile << "P6" << '\n'
		<< "# Sample Comment" << '\n'
		<< f.rows << ' ' << f.cols << '\n'
		<< f.maxIter << '\n';

	for (int i = 0; i < f.rows; i++)
	{
		for (int j = 0; j < f.cols; j++) {
			outfile << f.grid[i][j] << " ";
		}

		outfile << endl;
	}
}

Pixel Fractal::converToPixel(unsigned int color) {
	Pixel convert((color / 64) % 8, (color / 8) % 8, color % 8);

	return convert;
}