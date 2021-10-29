#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Complex {
private: 
	double real;	double imag;
public:
	Complex() {
		real = NULL;
		imag = NULL;
	}
	Complex(double n, double a) {
		real = n*cos(a);
		imag = n*sin(a);
	}
	Complex(Complex& comp) {
		real = comp.real;
		imag = comp.imag;
	}
	~Complex() {}

	Complex operator + (Complex& z) {
		Complex z_sum(real + z.real, imag + z.imag);
		return z_sum;
	}
	friend ostream& operator << (ostream& str, Complex& comp)
	{
		return str << "z = " << comp.real << " + " << comp.imag << "*i" << endl;
	}
};

int main()
{
	double m;
	cout << "Enter absolute value: ";
	cin >> m;

	int a;
	cout << "Enter angle (degrees): ";
	cin >> a;

	double rad = a * M_PI / 180;
	
	cout << endl;

	cout << "Converting to radians..." << endl;
	cout << a << " degrees = " << rad << " radians" << endl << "Converting completed" << endl << endl;

	cout << "z = |z|*(cos(a)+i*sin(a))" << endl;
	Complex z1(m, rad);
	cout << z1;

	cout << "------------------------------------------" << endl;

	cout << "Enter absolute value: ";
	cin >> m;

	cout << "Enter imag (degrees): ";
	cin >> a;

	rad = a * M_PI / 180;

	cout << endl;

	cout << "Converting to radians..." << endl;
	cout << a << " degrees = " << rad << " radians" << endl << "Converting completed" << endl << endl;

	cout << "z = |z|*(cos(a)+i*sin(a))" << endl;
	Complex z2(m, rad);
	cout << z2;
	
	cout << "------------------------------------------" << endl;
	
	Complex z3;
	z3 = z1 + z2;
	cout << z3;
	
}
